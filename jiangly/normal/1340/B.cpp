#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
std::string S[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int a[10];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 7; ++j)
            a[i] = 2 * a[i] + S[i][j] - '0';
    int n, k;
    std::cin >> n >> k;
    std::vector<int> s(n);
    std::vector<std::vector<bool>> able(n, std::vector<bool>(8));
    std::vector<std::vector<bool>> suf(n + 1, std::vector<bool>(7 * n + 1));
    for (int i = 0; i < n; ++i) {
        int x = 0;
        for (int j = 0; j < 7; ++j) {
            char c;
            std::cin >> c;
            x = 2 * x + c - '0';
        }
        s[i] = x;
        for (int j = 0; j < 10; ++j) {
            if ((a[j] & x) == x) {
                int cnt = __builtin_popcount(a[j] ^ x);
                able[i][cnt] = true;
            }
        }
    }
    suf[n][0] = true;
    for (int i = n - 1; i >= 0; --i)
        for (int j = 0; j <= 7 * n; ++j)
            if (suf[i + 1][j])
                for (int k = 0; k <= 7; ++k)
                    if (able[i][k])
                        suf[i][j + k] = true;
    if (!suf[0][k]) {
        std::cout << -1 << "\n";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 9; ; --j) {
            if ((a[j] & s[i]) == s[i]) {
                int cnt = __builtin_popcount(a[j] ^ s[i]);
                if (k >= cnt && suf[i + 1][k - cnt]) {
                    std::cout << j;
                    k -= cnt;
                    break;
                }
            }
        }
    }
    std::cout << "\n";
    return 0;
}