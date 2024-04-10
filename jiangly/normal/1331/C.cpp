#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a;
    std::cin >> a;
    int d[6];
    for (int i = 0; i < 6; ++i)
        d[i] = a >> i & 1;
    std::cout << (d[0] << 4 | d[1] << 1 | d[2] << 3 | d[3] << 2 | d[4] | d[5] << 5) << "\n";
    return 0;
}