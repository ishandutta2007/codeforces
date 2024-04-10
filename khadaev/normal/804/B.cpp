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
    string s;
    getline(cin, s);
    int n = s.length();
    ll ans = 0, bs = 0;
    ford(i, 0, n) {
        if (s[i] == 'b') {
            ++bs;
            if (bs == MOD) bs = 0;
        } else {
            ans += bs;
            if (ans >= MOD) ans -= MOD;
            bs *= 2;
            if (bs >= MOD) bs -= MOD;
        }
    }
    cout << ans << '\n';
}