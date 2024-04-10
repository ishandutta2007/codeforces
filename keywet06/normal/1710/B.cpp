#include <bits/stdc++.h>

using int64 = long long;

const int N = 200005;
const int M = 1 << 19;

int T, n, m;
int Rp[N], Px[N], Pxr[N];

int64 Rx[N];

int64 a[N];

int64 Maxa[M], Maxi[M], Maxd[M];

inline void Build(int u, int l, int r) {
    if (l == r) return Maxa[u] = a[l], Maxi[u] = a[l] + Rx[Px[l]], Maxd[u] = a[l] - Rx[Px[l]], void(0);
    int Mid = l + r >> 1;
    Build(u << 1, l, Mid), Build(u << 1 | 1, Mid + 1, r);
    Maxa[u] = std::max(Maxa[u << 1], Maxa[u << 1 | 1]);
    Maxi[u] = std::max(Maxi[u << 1], Maxi[u << 1 | 1]);
    Maxd[u] = std::max(Maxd[u << 1], Maxd[u << 1 | 1]);
}

template <int64 M[]>
inline int64 Query(int u, int l, int r, int x, int y) {
    if (l >= x && r <= y) return M[u];
    int Mid = l + r >> 1;
    int64 Ans = INT64_MIN;
    if (x <= Mid) Ans = std::max(Ans, Query<M>(u << 1, l, Mid, x, y));
    if (y > Mid) Ans = std::max(Ans, Query<M>(u << 1 | 1, Mid + 1, r, x, y));
    return Ans;
}

inline void Fix(int &l, int &r) { l = std::max(l, 1), r = std::min(r, n); }
inline int64 QueryMaxa(int l, int r) { return Fix(l, r), l <= r ? Query<Maxa>(1, 1, n, l, r) : INT64_MIN / 2; }
inline int64 QueryMaxi(int l, int r) { return Fix(l, r), l <= r ? Query<Maxi>(1, 1, n, l, r) : INT64_MIN / 2; }
inline int64 QueryMaxd(int l, int r) { return Fix(l, r), l <= r ? Query<Maxd>(1, 1, n, l, r) : INT64_MIN / 2; }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m;
        std::vector<std::pair<int64, int> > Oper;
        for (int i = 1; i <= n; ++i) {
            std::cin >> Rx[i] >> Rp[i], Px[i] = i;
            Oper.emplace_back(Rx[i], i + 5);
            Oper.emplace_back(Rx[i] - Rp[i] + 1, 1);
            Oper.emplace_back(Rx[i] + 1, -2);
            Oper.emplace_back(Rx[i] + Rp[i] + 1, 1);
        }
        std::sort(Oper.begin(), Oper.end());
        std::sort(Px + 1, Px + n + 1, [](int x, int y) { return Rx[x] < Rx[y]; });
        for (int i = 1; i <= n; ++i) Pxr[Px[i]] = i;
        int64 Nx = -10, Nv = 0, Nd = 0;
        for (auto [x, d] : Oper) {
            if (d < 5) {
                Nv += Nd * (x - Nx - 1), Nx = x - 1, Nd += d;
            } else {
                ++x, Nv += Nd * (x - Nx - 1), Nx = x - 1, a[Pxr[d - 5]] = Nv;
            }
        }
        Build(1, 1, n), Px[n + 1] = n + 1, Px[0] = 0, Rx[n + 1] = INT_MAX, Rx[0] = INT_MIN;
        for (int i = 1; i <= n; ++i) {
            int64 Ans = INT64_MIN;
            int64 RCen = Rx[i], RLen = Rp[i], RLeft = RCen - RLen, RRight = RCen + RLen;
            int l = 0, r = n + 1, Mid, ALeft, ACen = Pxr[i], ARight;
            while (l < r) Mid = l + r + 1 >> 1, Rx[Px[Mid]] <= RLeft ? l = Mid : r = Mid - 1;
            ALeft = l, l = 0, r = n + 1;
            while (l < r) Mid = l + r + 1 >> 1, Rx[Px[Mid]] < RRight ? l = Mid : r = Mid - 1;
            ARight = l;
            Ans = std::max(Ans, QueryMaxa(1, ALeft));
            Ans = std::max(Ans, QueryMaxd(ALeft + 1, ACen) + RCen - RLen);
            Ans = std::max(Ans, QueryMaxi(ACen, ARight) - RCen - RLen);
            Ans = std::max(Ans, QueryMaxa(ARight + 1, n));
            std::cout << int(Ans <= m);
        }
        std::cout << '\n';
    }
    return 0;
}