#include <bits/stdc++.h>

const int N = 1005;

int T, n, m, w, c;
int p[N];

std::string s;

void pch(int x, int t) {
    for (int i = 0; i < t; ++i) std::cout << x;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m >> s;
        c = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') p[++c] = i;
        }
        if (!c) {
            std::cout << s << std::endl;
            continue;
        }
        pch(0, p[1] - m);
        pch(1, std::min(p[1], m) + 1);
        for (int i = 1; i < c; ++i) {
            int t = p[i + 1] - p[i] - 1, s = t % 2;
            t /= 2;
            pch(1, std::min(t, m));
            pch(0, 2 * std::max(0, t - m) + s);
            pch(1, std::min(t, m) + 1);
        }
        int t = n - p[c] - 1;
        pch(1, std::min(t, m));
        pch(0, t - m);
        std::cout << std::endl;
    }
    return 0;
}