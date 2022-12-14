#include <bits/stdc++.h>

int main() {
    std::cout << "? ";
    for (int i = 1; i <= 100; i++) {
        std::cout << i << " ";
    } std::cout << std::endl;
    int x; std::cin >> x;
    std::cout << "? ";
    for (int i = 1; i <= 100; i++) {
        std::cout << (i << 7) << " ";
    } std::cout << std::endl;
    int y; std::cin >> y;
    int ans = 0;
    for (int i = 0; i < 7; i++) {
        ans |= 1 << i & y;
    }
    for (int i = 7; i < 14; i++) {
        ans |= 1 << i & x;
    } std::cout << "! " << ans << std::endl;
    return 0;
}