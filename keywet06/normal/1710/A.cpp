#include <bits/stdc++.h>

using int64 = long long;

const int N = 100005;

int n, m, k;

int64 a[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m >> k;
        for (int i = 1; i <= k; ++i) std::cin >> a[i];
        bool Flag = false;
        int64 Num = 0;
        for (int i = 1; i <= k; ++i) {
            int64 c = a[i] / m;
            Flag |= c > 2;
            Num += c > 1 ? c : 0;
        }
        if ((Flag || n % 2 == 0) && n <= Num) {
            std::cout << "Yes" << '\n';
            continue;
        }
        std::swap(n, m);
        Flag = false, Num = 0;
        for (int i = 1; i <= k; ++i) {
            int64 c = a[i] / m;
            Flag |= c > 2;
            Num += c > 1 ? c : 0;
        }
        if ((Flag || n % 2 == 0) && n <= Num) {
            std::cout << "Yes" << '\n';
        } else {
            std::cout << "No" << '\n';
        }
    }
    return 0;
}