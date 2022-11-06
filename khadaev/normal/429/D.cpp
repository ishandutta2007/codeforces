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

const int N = 1e5 + 10;

struct pt {
    ll x, y;
    int id;
};
 
inline bool cmp_x (const pt & a, const pt & b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
 
inline bool cmp_y (const pt & a, const pt & b) {
    return a.y < b.y;
}
 
pt a[N];

inline ll sq(ll n) {
    return n * n;
}

ll mindist;
int ansa, ansb;

void upd_ans(const pt &a, const pt &b) {
    ll dist = (sq(a.x - b.x) + sq(a.y - b.y));
    if (dist < mindist)
        mindist = dist, ansa = a.id, ansb = b.id;
}

void rec(int l, int r) {
    if (r - l <= 3) {
        for (int i = l; i <= r; ++i)
            for (int j = i + 1; j <= r; ++j)
                upd_ans(a[i], a[j]);
        sort(a + l, a + r + 1, &cmp_y);
        return;
    }
 
    int m = (l + r) / 2;
    ll midx = a[m].x;
    rec (l, m);
    rec (m + 1, r);
    static pt t[N];
    merge (a + l, a + m + 1, a + m + 1, a + r + 1, t, &cmp_y);
    copy (t, t + r - l + 1, a + l);
 
    int tsz = 0;
    for (int i = l; i <= r; ++i)
        if (sq(a[i].x - midx) < mindist) {
            for (int j = tsz - 1; j >= 0 && sq(a[i].y - t[j].y) < mindist; --j)
                upd_ans(a[i], t[j]);
            t[tsz++] = a[i];
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    //n = 1e5;
    vector<int> q(n);
    forn(i, 0, n) cin >> q[i];
    //forn(i, 0, n) q[i] = 1e4;
    ll s = 0;
    forn(i, 0, n) {
        s += q[i];
        a[i].x = s;
        a[i].y = i;
        a[i].id = i;
    }
    sort(a, a + n, &cmp_x);
    mindist = LINF;
    rec(0, n - 1);
    cout << mindist << '\n';
}