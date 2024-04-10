#include <bits/stdc++.h>

using int64 = long long;

namespace oct {

inline void ios(bool enable = false, std::string s = "") {
    if (enable) {
        std::string t;
        freopen((t = s + ".in").data(), "r", stdin);
        freopen((t = s + ".out").data(), "w", stdout);
    }
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
}

}  // namespace oct

const int N = 100010;

char s[N], t[N];

int n, m;
int sa[N], sb[N], ta[N], tb[N];

int main() {
    oct::ios();
    std::cin >> s + 1 >> t + 1;
    n = strlen(s + 1);
    m = strlen(t + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'A') sa[i] = sa[i - 1] + 1;
        sb[i] = sb[i - 1] + (s[i] == 'B' || s[i] == 'C');
    }
    for (int i = 1; i <= m; i++) {
        if (t[i] == 'A') ta[i] = ta[i - 1] + 1;
        tb[i] = tb[i - 1] + (t[i] == 'B' || t[i] == 'C');
    }
    int q;
    std::cin >> q;
    int l, r, Sa, Sb, Ta, Tb, lenS, lenT;
    while (q--) {
        std::cin >> l >> r;
        Sa = std::min(r - l + 1, sa[r]);
        Sb = sb[r] - sb[l - 1];
        lenS = r - l + 1;
        std::cin >> l >> r;
        Ta = std::min(r - l + 1, ta[r]);
        Tb = tb[r] - tb[l - 1];
        lenT = r - l + 1;
        if (Tb < Sb || ((Tb & 1) != (Sb & 1)) || Ta > Sa) {
            std::cout << 0;
        } else if ((Ta < Sa && Tb > Sb) ||
                   ((Ta != lenS || Ta == lenT) && (Sa - Ta) % 3 == 0)) {
            std::cout << 1;
        } else {
            std::cout << 0;
        }
    }
    std::cout << std::endl;
    return 0;
}