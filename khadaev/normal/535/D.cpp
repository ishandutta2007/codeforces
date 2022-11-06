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

vector<int> Z(string s) {
    int n = s.length();
    vector<int> z(n, 0);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int l = s.length();
    vector<int> z = Z(s);
    vector<int> y(m);
    forn(i, 0, m) cin >> y[i];
    forn(i, 0, m) --y[i];
    forn(i, 0, m - 1)
        if (y[i + 1] < y[i] + l) {
            if (z[y[i + 1] - y[i]] < y[i] + l - y[i + 1]) {
                cout << "0\n";
                return 0;
            }
        }
    vector<char> def(n, 0);
    forn(i, 0, m) {
        ford(j, y[i], y[i] + l) {
            if (!def[j]) def[j] = 1;
            else break;
        }
    }
    ll ans = 1;
    forn(i, 0, n) if (!def[i]) ans = ans * 26 % MOD;
    cout << ans << '\n';
}