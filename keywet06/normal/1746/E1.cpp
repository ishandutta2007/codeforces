#include <bits/stdc++.h>

const int N = 100005;

int n, c;
int f[N], g[N];

bool Check(int l, int r) {
    std::cout << "? " << r - l + 1;
    for (int i = l; i <= r; ++i) std::cout << ' ' << f[i];
    std::cout << std::endl;
    std::string s;
    std::cin >> s;
    return s == "YES";
}

inline void Fit(int l1, int r1, int l2 = 1, int r2 = 0, int l3 = 1, int r3 = 0) {
    int t = 0;
    for (int i = l1; i <= r1; ++i) g[t++] = f[i];
    for (int i = l2; i <= r2; ++i) g[t++] = f[i];
    for (int i = l3; i <= r3; ++i) g[t++] = f[i];
    for (int i = 0; i < t; ++i) f[i + 1] = g[i];
    n = t;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) f[i] = i;
    while (n > 3) {
        c = n / 4;
        if (Check(1, c * 2)) {
            if (Check(2 * c + 1, 3 * c)) {
                Fit(1, 3 * c);
            } else {
                Fit(1, 2 * c, 3 * c + 1, n);
            }
        } else {
            if (Check(1, c)) {
                Fit(1, c, 2 * c + 1, n);
            } else {
                Fit(c + 1, n);
            }
        }
    }
    if (n == 3) {
        if (Check(1, 2) && Check(1, 2)) {
            Fit(1, 2);
        } else if (Check(1, 1)) {
            Fit(1, 1, 3, 3);
        } else {
            Fit(2, 3);
        }
    }
    std::string s;
    std::cout << "! " << f[1] << std::endl;
    std::cin >> s;
    if (s == ":)") return 0;
    std::cout << "! " << f[2] << std::endl;
    return 0;
}