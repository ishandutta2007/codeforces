#include <bits/stdc++.h>
#define debug std::cerr << "Debug(" << __LINE__ << "): "
#define pub push_back
#define pob pop_back
#define mkp make_pair
#define fir first
#define sec second

using uint8 = unsigned char;
using uint16 = unsigned short int;
using uint32 = unsigned int;
using uint64 = unsigned long long;
using int8 = signed char;
using int16 = short int;
using int32 = int;
using int64 = long long;
using pi32 = std::pair<int32, int32>;

namespace oct {
template <typename _Tp>
_Tp &mad(_Tp &x, _Tp y);
template <typename _Tp>
_Tp &mid(_Tp &x, _Tp y);
template <typename _Tp>
bool in(_Tp x, _Tp l, _Tp r);

template <typename _Tp>
inline _Tp &mad(_Tp &x, _Tp y) {
    return x = std::max(x, y);
}
template <typename _Tp>
inline _Tp &mid(_Tp &x, _Tp y) {
    return x = std::min(x, y);
}
template <typename _Tp>
inline bool in(_Tp x, _Tp l, _Tp r) {
    return l <= x && x <= r;
}
}  // namespace oct

// the pre-document end

const int N = 200005;
const int Nl1 = N << 1;
struct rec {
    int x1, x2, y1, y2, id;
};
struct poi {
    int x, y;
};
int n, m, k, q;
int ans[N];
int max[Nl1];
poi p[N];
rec r[N];
inline std::istream &operator>>(std::istream &in, poi &x) {
    return in >> x.x >> x.y;
}
inline std::istream &operator>>(std::istream &in, rec &x) {
    return in >> x.x1 >> x.y1 >> x.x2 >> x.y2;
}
inline void update(int u, int l, int r, int x, int y) {
    if (l == r) {
        max[u] = y;
        return;
    }
    int mid = l + r >> 1;
    x <= mid ? update(u << 1, l, mid, x, y)
             : update(u << 1 | 1, mid + 1, r, x, y);
    max[u] = std::min(max[u << 1], max[u << 1 | 1]);
}
inline int query(int u, int l, int r, int x, int y) {
    if (x <= l && r <= y) return max[u];
    int mid = l + r >> 1, ans = INT_MAX;
    if (x <= mid) oct::mid(ans, query(u << 1, l, mid, x, y));
    if (y > mid) oct::mid(ans, query(u << 1 | 1, mid + 1, r, x, y));
    return ans;
}
inline void solve() {
    std::sort(p, p + k, [](poi x, poi y) { return x.x < y.x; });
    std::sort(r, r + q, [](rec x, rec y) { return x.x2 < y.x2; });
    for (int i = 1, cnt1 = 0, cnt2 = 0; i <= n; ++i) {
        for (; cnt1 < k && p[cnt1].x <= i; ++cnt1) {
            update(1, 1, m, p[cnt1].y, p[cnt1].x);
        }
        for (; cnt2 < q && r[cnt2].x2 <= i; ++cnt2) {
            ans[r[cnt2].id] |= oct::in(query(1, 1, m, r[cnt2].y1, r[cnt2].y2),
                                       r[cnt2].x1, r[cnt2].x2);
        }
    }
}
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m >> k >> q;
    for (int i = 0; i < k; ++i) std::cin >> p[i];
    for (int i = 0; i < q; ++i) std::cin >> r[i], r[i].id = i;
    solve();
    for (int i = 0; i < k; ++i) std::swap(p[i].x, p[i].y);
    for (int i = 0; i < q; ++i) {
        std::swap(r[i].x1, r[i].y1);
        std::swap(r[i].x2, r[i].y2);
    }
    std::swap(n, m);
    memset(max, 0, sizeof(max));
    solve();
    for (int i = 0; i < q; ++i) std::cout << (ans[i] ? "YES" : "NO") << '\n';
    return 0;
}