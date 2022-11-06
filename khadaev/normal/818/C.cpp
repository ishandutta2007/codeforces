#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n - 1); i >= (int)(a); --i)
#define fore(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
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

using event = tuple<int, int, int>;

void solve(vector<event> &x, vector<int> &ans, int tp) {
    int prev = -1, cur = 0, add = 0;
    for (auto p : x) {
        int pos, t, id;
        tie(pos, t, id) = p;
        if (pos != prev) {
            prev = pos;
            cur += add;
            add = 0;
        }
        if (t == tp) {
            ++add;
        } else {
            ans[id] += cur;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int d, n, m;
    cin >> d >> n >> m;
    vector<int> lft(d), rgt(d), top(d), bot(d);
    vector<tuple<int, int, int>> h, v;
    forn(i, 0, d) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        h.eb(min(x1, x2), 1, i);
        h.eb(max(x1, x2), -1, i);
        v.eb(min(y1, y2), 1, i);
        v.eb(max(y1, y2), -1, i);
        if (x1 != x2) {
            --lft[i], --rgt[i];
        } else {
            --top[i], --bot[i];
        }
    }
    sort(all(h));
    solve(h, lft, 1);
    reverse(all(h));
    solve(h, rgt, -1);
    sort(all(v));
    solve(v, top, 1);
    reverse(all(v));
    solve(v, bot, -1);
    int cntl, cntr, cntt, cntb;
    cin >> cntl >> cntr >> cntt >> cntb;
    forn(i, 0, d)
        if (lft[i] == cntl 
                && rgt[i] == cntr
                && top[i] == cntt
                && bot[i] == cntb) {
            cout << i + 1 << '\n';
            return 0;
        }
    /*trace(lft);
    trace(rgt);
    trace(top);
    trace(bot);*/
    cout << -1 << '\n';
}