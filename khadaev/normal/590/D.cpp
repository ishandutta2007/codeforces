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

const int N = 151;
const int COST = N * (N - 1) / 2;

ll ans[N][COST];
ll q[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, s;
    cin >> n >> k >> s;
    s += k * (k - 1) / 2;
    s = min(s, n * (n - 1) / 2);
    forn(i, 0, N) forn(j, 0, COST) ans[i][j] = LINF;
    forn(i, 0, n) cin >> q[i];
    ans[1][0] = q[0];
    ans[0][0] = 0;
    forn(i, 1, n) {
        ford(j, 1, n + 1)
            ford(cost, 0, COST)
                if (cost >= i)
                    ans[j][cost] = min(ans[j][cost], ans[j - 1][cost - i] + q[i]);
    }
    ll res = LINF;
    fore(c, 0, s) res = min(res, ans[k][c]);
    cout << res << '\n';
}