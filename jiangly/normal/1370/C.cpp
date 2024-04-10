#include <bits/stdc++.h>
bool isprime(int n) {
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int win;
        if (n == 1) {
            win = 0;
        } else if (n % 2 == 1) {
            win = 1;
        } else if (n == 2) {
            win = 1;
        } else if ((n & -n) == n) {
            win = 0;
        } else if (n % 4 == 0) {
            win = 1;
        } else if (isprime(n / 2)) {
            win = 0;
        } else {
            win = 1;
        }
        std::cout << (win ? "Ashishgup" : "FastestFinger") << "\n";
    }
    return 0;
}