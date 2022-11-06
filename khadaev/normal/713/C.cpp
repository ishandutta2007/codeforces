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

const int N = 3001;
ll dp[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n) a[i] -= i;
    vector<pair<ll, ll>> p(n);
    forn(i, 0, n) {
        p[i].fs = a[i];
        p[i].sn = i;
    }
    sort(all(p));
    forn(i, 0, n) dp[0][i] = abs(a[i] - a[0]);
    forn(i, 1, n) {
        ll opt = LINF;
        forn(j, 0, n) {
            opt = min(opt, dp[i - 1][p[j].sn]);
            dp[i][p[j].sn] = opt + abs(a[i] - p[j].fs);
        }
    }
    ll ans = LINF;
    forn(i, 0, n) ans = min(ans, dp[n - 1][i]);
    cout << ans << '\n';
}