#include <bits/stdc++.h>

const int N = 2005;

int T, n, s;
int a[N];

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        s = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                s += gcd(a[i], a[j] * 2) > 1 || gcd(a[i] * 2, a[j]) > 1;
            }
        }
        std::cout << s << std::endl;
    }
    return 0;
}