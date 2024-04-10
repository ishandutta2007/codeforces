#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

struct Point {
    ll s, r;
    int ix1, ix2;

    Point () {};

    bool operator< (const Point& x) const {
        if (s == x.s) return r > x.r;
        return s > x.s;
    }
};

bool good(Point a, Point b, Point c) {
    return ((b.s - c.s) * (a.r - b.r) * a.s * c.r  - (b.r - c.r) * (a.s - b.s) * a.r * c.s <= 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Point> a(n);
    forn(i, 0, n) {
        cin >> a[i].s >> a[i].r;
        a[i].ix1 = i;
    }
    sort(all(a));
    forn(i, 0, n) a[i].ix2 = i;
    vector<Point> q;
    forn(i, 0, n) {
        int sz = q.size();
        if (sz && a[i].r <= q[sz - 1].r) continue;
        while (sz >= 2 && !good(q[sz - 2], q[sz - 1], a[i])) {
            q.pop_back();
            --sz;
        }
        q.eb(a[i]);
    }
    //int sz = q.size();
    //while (sz >= 2 && q[sz - 1].r <= q[sz - 2].r) {
    //    q.pop_back();
    //    --sz;
    //}
    vector<int> ans;
    for (Point p : q) {
        int j = p.ix2;
        while (j < n && a[j].r == a[p.ix2].r && a[j].s == a[p.ix2].s) {
            ans.eb(a[j].ix1);
            ++j;
        }
    }
    sort(all(ans));
    for (int i : ans) cout << 1 + i << ' ';
}