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
    string t, p;
    cin >> t >> p;
    int n = t.length();
    vector<int> a(n);
    forn(i, 0, n) {
        cin >> a[i];
        --a[i];
    }
    int l = 0, r = n + 1;
    while (l < r - 1) {
        int m = (l + r) / 2;
        vector<int> is(n, 1);
        forn(j, 0, m) is[a[j]] = 0;
        int x = 0;
        forn(j, 0, n) {
            if (is[j] == 0) continue;
            if (t[j] == p[x]) ++x;
            if (x == p.length()) break;
        }
        if (x == p.length()) l = m;
        else r = m;
    }
    cout << r - 1 << '\n';
}