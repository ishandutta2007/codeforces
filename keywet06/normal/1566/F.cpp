#include <bits/stdc++.h>

#define Deb std::cerr
#define Delin Deb << "[Debug] at Line " << __LINE__
#define Debug Delin << " : "
#define Deline Delin << std::endl

using int64 = long long;

struct seg {
    int64 l, r;
};

const int B = 2;
const int N = 200005;

int T, n, m, pnt, l, r;

int64 x, y, z;
int64 a[N];
int64 f[N][B];

seg s[N], p[N];

inline int64 mid(int64 &x, int64 y) { return x = std::min(x, y); }

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        for (int i = 1; i <= m; ++i) std::cin >> s[i].l >> s[i].r;
        std::sort(a + 1, a + n + 1);
        std::sort(s + 1, s + m + 1, [](seg x, seg y) {
            return x.l == y.l ? x.r < y.r : x.l < y.l;
        });
        p[pnt = 1] = s[1];
        for (int i = 2; i <= m; ++i) {
            while (pnt && s[i].r <= p[pnt].r) --pnt;
            if (!pnt || s[i].l > p[pnt].l) p[++pnt] = s[i];
        }
        memset(f, 63, sizeof(f));
        l = 1, m = pnt;
        while (l <= m && p[l].r < a[1]) ++l;
        f[1][1] = (f[1][0] = l > 1 ? a[1] - p[1].r : 0) << 1;
        for (int i = 2; i <= n; ++i) {
            while (l <= m && p[l].l <= a[i - 1]) ++l;
            r = l;
            while (r <= m && p[r].r < a[i]) ++r;
            if (l == r-- && (f[i][0] = f[i][1] = f[i - 1][0], 1)) continue;
            mid(f[i][0], f[i - 1][0] + (p[r].l - a[i - 1] << 1));
            mid(f[i][0], f[i - 1][1] + p[r].l - a[i - 1]);
            f[i][1] = f[i][0];
            mid(f[i][0], f[i - 1][0] + a[i] - p[l].r);
            mid(f[i][1], f[i - 1][0] + (a[i] - p[l].r << 1));
            for (int j = l; j < r; ++j) {
                x = p[j].l - a[i - 1], y = a[i] - p[j + 1].r;
                mid(f[i][0], f[i - 1][0] + x + x + y);
                mid(f[i][0], f[i - 1][1] + x + y);
                mid(f[i][1], f[i - 1][0] + x + x + y + y);
                mid(f[i][1], f[i - 1][1] + x + y + y);
            }
            l = r;
        }
        while (l <= m && p[l].l <= a[n]) ++l;
        x = l > m ? 0 : p[m].l - a[n];
        std::cout << std::min(f[n][0] + x + x, f[n][1] + x) << '\n';
    }
    return 0;
}