#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(a) (int) (a).size()
#define eb emplace_back
#define ld long double
#define ve vector
#define forn(i, n) for (int i = 0; i < n; i++)

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    set<pii> l, r;
    l.insert({0, 0});
    r.insert({0, 0});
    int p = 0;
    ve<int> pr(n + 1, -1), pr2(n + 1, -1);
    forn (i, n) {
        int k;
        cin >> k;
        int A = sz(l), B = sz(r);
        if (B) l.insert({p, i});
        if (A) r.insert({p, i});
        int L, R;
        cin >> L >> R;
        if (k < L || k > R) l.clear();
        int L2, R2;
        cin >> L2 >> R2;
        if (k < L2 || k > R2) r.clear();
        while (sz(l) && (*l.begin()).fi < L2) l.erase(*l.begin());
        while (sz(l) && (*l.rbegin()).fi > R2) l.erase(*l.rbegin());
        while (sz(r) && (*r.begin()).fi < L) r.erase(*r.begin());
        while (sz(r) && (*r.rbegin()).fi > R) r.erase(*r.rbegin());
        p = k;
        if (sz(l) == 0 && sz(r) == 0) {
            cout << "No";
            return 0;
        }
        if (sz(l)) {
            pr[i + 1] = (*l.begin()).se;
        }
        if (sz(r)) {
            pr2[i + 1] = (*r.begin()).se;
        }
        //for (auto [x, y] : l) {
            //cout << x << " " << y << " +l ";
        //} cout << endl;
        //for (auto [x, y] : r) {
        //    cout << x << " " << y << " +r ";
        //} cout << endl;
    }
    //for (auto x : pr) cout << x << " + "; cout << endl;
    //for (auto y : pr2) cout << y << " - "; cout << endl;
    int t = 0;
    if (sz(r)) t = 1;
    ve<int> ans(n);
    while (n) {
        if (t == 0) {
            int z = pr[n];
            assert(z != -1);
            for (int i = z; i < n; i++) ans[i] = 0;
            n = z;
        }
        else {
            int z = pr2[n];
            assert(z != -1);
            for (int i = z; i < n; i++) ans[i] = 1;
            n = z;
        }
        t = 1 - t;
    }
    cout << "Yes\n";
    for (auto x : ans) cout << x << " ";
}