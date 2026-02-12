#include <iostream>
#include <limits>
#include <vector>

#include "functions.hpp"

int main() {
  std::vector<std::vector<char>> board;
  InitializeBoard(board);

  char current_player = 'X';
  int row = 0, col = 0;

  PrintBoard(board);

  while (true) {
    std::cout << "Player " << current_player
              << ", enter your move (row and column): ";

    while (!(std::cin >> row >> col)) {
      std::cin.clear();  // Clear the error state.
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                      '\n');  // Ignore invalid input.
      std::cerr << "Invalid input: Please enter integers." << std::endl;
    }

    if (MakeMove(board, row, col, current_player)) {
      PrintBoard(board);
      if (IsBoardFull(board)) {
        PrintBoard(board);
        std::cout << "It's a tie!" << std::endl;
        break;
      }
      char winner = CheckWinner(board);
      if (winner != ' ') {
        PrintBoard(board);
        std::cout << "Player " << winner << " wins!" << std::endl;
        break;
      }
      SwitchPlayer(current_player);
    }
  }

  return 0;
}