#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

const int mod = 1e9 + 7;
const int N = 2000005;
char s[N];
int n, m, p, tot;
int a[N], bs[N], c[N];
std::deque<int> q;
inline int add(int x, int y) {
    x += y;
    if (x > mod) return x - mod;
    return x;
}
int gethash(int x, int len) {
    return add(bs[x + len - 1], mod - bs[x - 1] * 1ll * c[len] % mod);
}
bool cmp(int x, int y) {
    int l = 0, r = n, ret = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (gethash(x, mid) == gethash(y, mid)) {
            ret = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    return ret == n ? 1 : s[x + ret] == '(';
}
inline void solve1() {
    c[0] = 1;
    for (int i = 1; i <= m; ++i) {
        a[i] = a[i - 1] + (s[i] == '(' ? 1 : -1);
        c[i] = add(c[i - 1], add(c[i - 1], c[i - 1]));
        bs[i] = add(add(bs[i - 1], add(bs[i - 1], bs[i - 1])),
                    (s[i] == '(' ? 1 : 2));
    }
    for (int i = 1; i < m; ++i) {
        while (q.size() && (a[i] <= a[q.back()])) q.pop_back();
        q.push_back(i);
        while (q.size() && (i - q.front() >= n)) q.pop_front();
        if (i >= n && a[q.front()] >= a[i - n]) {
            if (!p || cmp(i - n + 1, p)) {
                p = i - n + 1;
            }
        }
    }
    for (int i = 0; i < n; i++) putchar(s[p + i]);
    for (int i = 1; i <= tot; ++i) putchar(')');
    return;
}
inline void solve2() {
    c[0] = 1;
    for (int i = 1; i <= m; ++i) {
        c[i] = add(c[i - 1], add(c[i - 1], c[i - 1]));
        bs[i] = add(add(bs[i - 1], add(bs[i - 1], bs[i - 1])),
                    (s[i] == '(' ? 1 : 2));
    }
    for (int i = m; i; --i) a[i] = a[i + 1] - (s[i] == '(' ? 1 : -1);
    for (int i = m - 1; i; --i) {
        while (q.size() && a[i] <= a[q.back()]) q.pop_back();
        q.push_back(i);
        while (q.size() && q.front() - i >= n) q.pop_front();
        if (i <= n && a[q.front()] >= a[i + n])
            if (!p || cmp(i, p)) p = i;
    }
    for (int i = tot; i < 0; i++) putchar('(');
    for (int i = 0; i < n; i++) putchar(s[p + i]);
    return;
}
int main() {
    std::cin >> s + 1;
    n = strlen(s + 1);
    m = n * 2;
    for (int i = 1; i <= n; ++i) {
        s[n + i] = s[i];
        tot += ((s[i] == '(') ? 1 : -1);
    }
    (tot >= 0 ? solve1 : solve2)();
    return 0;
}