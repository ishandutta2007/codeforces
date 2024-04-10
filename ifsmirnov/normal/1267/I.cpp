#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef long long ll;

map<pii, int> q;

int ask(int i, int j) {
    if (q.count({i, j})) return q[{i, j}];
    int& res = q[{i, j}];
    cout << "? " << i+1 << " " << j+1 << endl;
    char c[10];
    cin >> c;
    return res = (c[0] == '>');
}

void solve() {
    q.clear();
    int n;
    cin >> n;
    vector<pii> a;
    forn(i, n) {
        int x = i*2, y = i*2+1;
        if (ask(x, y)) a.emplace_back(x, y);
        else a.emplace_back(y, x);
    }
    sort(all(a), [](pii x, pii y) { return ask(x.second, y.second); });
    vi t;
    forn(i, n) if (i) {
        t.push_back(a[i].fi);
        t.push_back(a[i].se);
    }
    sort(all(t), [](int x, int y) { return ask(x, y); });
    int pidor = a[0].se;
    forn(i, t.size()) if (i) ask(t[i], pidor);
    cout << "!" << endl;
}

int main() {
#ifdef LOCAL
    // freopen("i.in", "r", stdin);
#endif

    int t;
    cin >> t;
    forn(i, t) solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}