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

const int S = 52;
int m;
ll mt[S][S], x[S][S], y[S][S];

int ix(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    return c - 'A' + 26;
}

void Pow(ll n) {
    if (n == 0) {
        forn(i, 0, m) x[i][i] = 1;
        return;
    }
    Pow(n / 2);
    forn(i, 0, m) forn(j, 0, m) y[i][j] = 0;
    forn(i, 0, m) forn(j, 0, m) forn(k, 0, m) {
        y[i][k] += x[i][j] * x[j][k];
        y[i][k] %= MOD;
    }
    forn(i, 0, m) forn(j, 0, m) x[i][j] = y[i][j];
    if (n % 2) {
        forn(i, 0, m) forn(j, 0, m) y[i][j] = 0;
        forn(i, 0, m) forn(j, 0, m) forn(k, 0, m) {
            y[i][k] += x[i][j] * mt[j][k];
            y[i][k] %= MOD;
        }
        forn(i, 0, m) forn(j, 0, m) x[i][j] = y[i][j];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> m >> k;
    forn(i, 0, m) forn(j, 0, m) mt[i][j] = 1;
    forn(i, 0, k) {
        string s;
        cin >> s;
        mt[ix(s[0])][ix(s[1])] = 0;
    }
    Pow(n - 1);
    ll ans = 0;
    forn(i, 0, m) forn(j, 0, m) {
        ans += x[i][j];
        if (ans >= MOD) ans -= MOD;
    }
    cout << ans << '\n';
}