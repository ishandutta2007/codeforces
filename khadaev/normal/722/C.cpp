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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, 0, n) cin >> a[i];
    vector<int> pr(n, -1), nx(n, n);
    vector<ll> pref(n);
    pref[0] = 0;
    forn(i, 1, n) pref[i] = pref[i - 1] + a[i];
    vector<ll> l(n, -1), r(n, -1), s(n, -1);
    vector<int> p(n);
    forn(i, 0, n) cin >> p[i];
    forn(i, 0, n) --p[i];
    vector<ll> ans(n);
    ll cur = 0;
    ford(i, 0, n) {
        ans[i] = cur;
        int lf;
        if (p[i] == 0) lf = 0;
        else if (l[p[i] - 1] == -1) lf = p[i];
        else lf = l[p[i] - 1];
        int rr;
        if (p[i] == n - 1) rr = n - 1;
        else if (r[p[i] + 1] == -1) rr = p[i];
        else rr = r[p[i] + 1];
        ll ss = 0;
        if (p[i] != 0 && s[p[i] - 1] != -1) ss += s[p[i] - 1];
        if (p[i] != n - 1 && s[p[i] + 1] != -1) ss += s[p[i] + 1];
        ss += a[p[i]];
        l[rr] = lf;
        r[lf] = rr;
        s[lf] = ss;
        s[rr] = ss;
        cur = max(cur, ss);
    }
    forn(i, 0, n) cout << ans[i] << '\n';
}