#include <bits/stdc++.h>

const int N = 200005;
const int M = 1 << 19;

int lT, rT, lN, rN;
int a[N], lt[N], rt[N], Min[M];

inline void Build(int u, int l, int r) {
    if (l == r) return void(Min[u] = a[l]);
    int Mid = l + r >> 1;
    Build(u << 1, l, Mid), Build(u << 1 | 1, Mid + 1, r);
    Min[u] = std::min(Min[u << 1], Min[u << 1 | 1]);
}

inline int Query(int u, int l, int r, int x, int y) {
    if (l >= x && r <= y) return Min[u];
    int Mid = l + r >> 1, Ans = INT_MAX;
    if (x <= Mid) Ans = std::min(Ans, Query(u << 1, l, Mid, x, y));
    if (y > Mid) Ans = std::min(Ans, Query(u << 1 | 1, Mid + 1, r, x, y));
    return Ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        std::string s;
        std::cin >> s;
        int cw = 0, c0 = 0, c1 = 0;
        for (char ch : s) ++(ch == '?' ? cw : ch == '(' ? c0 : c1);
        if (std::abs(c0 - c1) > cw || ((cw + std::abs(c0 - c1)) & 1)) {
            std::cout << "NO" << '\n';
            continue;
        }
        lN = cw + c1 - c0 >> 1, rN = cw - lN, lT = rT = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            char &c = s[i];
            if (c != '?') continue;
            if (lT < lN) {
                lt[++lT] = i + 1, c = '(';
            } else {
                rt[++rT] = i + 1, c = ')';
            }
        }
        for (int i = 0; i < n; ++i) a[i + 1] = a[i] + (s[i] == '(' ? 1 : -1);
        Build(1, 1, n);
        if (Query(1, 1, n, 1, n) < 0) {
            std::cout << "NO" << '\n';
            continue;
        }
        bool Flag = !lT || !rT || Query(1, 1, n, lt[lT], rt[1] - 1) < 2;
        std::cout << (Flag ? "YES" : "NO") << '\n';
    }
    return 0;
}