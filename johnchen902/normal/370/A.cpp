#include <iostream>
#include <cstdlib>
#include <algorithm>

int rook(int r1, int c1, int r2, int c2){
    int moves = 0;
    if(r1 != r2)
        moves++;
    if(c1 != c2)
        moves++;
    return moves;
}
int bishop(int r1, int c1, int r2, int c2){
    if((c1 + r1) % 2 != (c2 + r2) % 2)
        return 0;
    int moves = 0;
    if(c1 + r1 != c2 + r2)
        moves++;
    if(c1 - r1 != c2 - r2)
        moves++;
    return moves;
}
int king(int r1, int c1, int r2, int c2){
    return std::max(std::abs(r1 - r2), std::abs(c1 - c2));
}
int main(){
    int r1, c1, r2, c2;
    std::cin >> r1 >> c1 >> r2 >> c2;
    std::cout << rook(r1, c1, r2, c2) << " "
        << bishop(r1, c1, r2, c2) << " "
        << king(r1, c1, r2, c2) << std::endl;
}