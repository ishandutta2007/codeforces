#include <bits/stdc++.h>

const int B = 5;
const int C = 26;

const int realbraille[C][B] = {
    {1, 0, 0, 1, 0}, {1, 1, 0, 2, 0}, {2, 0, 0, 1, 1}, {2, 1, 0, 1, 2},
    {1, 1, 0, 1, 1}, {2, 1, 0, 2, 1}, {2, 2, 0, 2, 2}, {1, 2, 0, 2, 1},
    {1, 1, 0, 1, 1}, {1, 2, 0, 1, 2}, {1, 0, 1, 2, 0}, {1, 1, 1, 3, 0},
    {2, 0, 1, 2, 1}, {2, 1, 1, 2, 2}, {1, 1, 1, 2, 1}, {2, 1, 1, 3, 1},
    {2, 2, 1, 3, 2}, {1, 2, 1, 3, 1}, {1, 1, 1, 2, 1}, {1, 2, 1, 2, 2},
    {1, 0, 2, 2, 1}, {1, 1, 2, 3, 1}, {1, 2, 1, 1, 3}, {2, 0, 2, 2, 2},
    {2, 1, 2, 2, 3}, {1, 1, 2, 2, 2}};
const int braille[C][B] = {
    {1, 0, 0, 1, 0}, {1, 1, 0, 2, 0}, {2, 0, 0, 1, 1}, {2, 1, 0, 1, 2},
    {1, 1, 0, 1, 1}, {2, 1, 0, 2, 1}, {2, 2, 0, 2, 2}, {1, 2, 0, 2, 1},
    {0, 0, 0, 0, 0}, {1, 2, 0, 1, 2}, {1, 0, 1, 2, 0}, {1, 1, 1, 3, 0},
    {2, 0, 1, 2, 1}, {2, 1, 1, 2, 2}, {1, 1, 1, 2, 1}, {2, 1, 1, 3, 1},
    {2, 2, 1, 3, 2}, {1, 2, 1, 3, 1}, {0, 0, 0, 0, 0}, {1, 2, 1, 2, 2},
    {1, 0, 2, 2, 1}, {1, 1, 2, 3, 1}, {1, 2, 1, 1, 3}, {2, 0, 2, 2, 2},
    {2, 1, 2, 2, 3}, {1, 1, 2, 2, 2}};

int n, d;
int c[B];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    while (n--) {
        for (int i = 0; i < B; ++i) std::cin >> c[i];
        for (int i = 0; i < C; ++i) {
            d = 1;
            for (int j = 0; j < B; ++j) d &= c[j] == braille[i][j];
            if (d) std::cout << char('a' + i);
        }
    }
    std::cout << std::endl;
    return 0;
}