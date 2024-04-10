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

int n, m;
set<int> lift, lest;
int v;

i64 go(int x, int y, int h, int p, int v) {
    i64 s = 0;
    s += abs(x-p);
    s += abs(y-p);
    s += (h+v-1)/v;
    return s;
}

void scan() {
    cin >> n >> m;
    int k1, k2;
    cin >> k1 >> k2;
    cin >> v;
    forn(i, k1) {
        int x;
        cin >> x;
        lest.insert(x);
    }
    forn(i, k2) {
        int x;
        cin >> x;
        lift.insert(x);
    }
}

vi get(set<int>& a, int x) {
    vi res;
    auto it = a.lower_bound(x);
    if (it != a.end()) {
        res.push_back(*it);
    }
    if (it != a.begin()) {
        --it;
        res.push_back(*it);
    }
    return res;
}

void solve() {
    int q;
    cin >> q;
    forn(i, q) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        i64 res = 1e18;
        if (y1 == y2) res = abs(x1-x2);
        for (int x: get(lift, x1)) res = min(res, go(x1, x2, abs(y1-y2), x, v));
        for (int x: get(lift, x2)) res = min(res, go(x1, x2, abs(y1-y2), x, v));
        for (int x: get(lest, x1)) res = min(res, go(x1, x2, abs(y1-y2), x, 1));
        for (int x: get(lest, x2)) res = min(res, go(x1, x2, abs(y1-y2), x, 1));
        cout << res << "\n";
    }
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif

    scan();
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}