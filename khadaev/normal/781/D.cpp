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

const int N = 512;
const int LOG = 60;

bitset<N> p[2][LOG][N];

const ll BOUND = 1000000000000000000LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int v, u, t;
        cin >> v >> u >> t;
        --v, --u;
        p[t][0][v].set(u);
    }
    forn(i, 1, LOG) {
        forn(from, 0, n) {
            forn(to, 0, n) {
                if (p[0][i - 1][from][to]) p[0][i][from] |= p[1][i - 1][to];
                if (p[1][i - 1][from][to]) p[1][i][from] |= p[0][i - 1][to];
            }
        }
    }
    bitset<N> prv;
    int rev = 0;
    prv.set(0);
    ll ans = 0;
    ford(i, 0, LOG) {
        bitset<N> nxt;
        forn(u, 0, n) if (prv[u]) nxt |= p[rev][i][u];
        bool fnd = false;
        forn(j, 0, n) if (nxt[j]) fnd = true;
        if (!fnd) continue;
        ans += (1ll << i);
        rev = 1 - rev;
        prv = nxt;
    }
    if (ans > BOUND) ans = -1;
    cout << ans << '\n';
}