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

const int N = 2e5 + 10;
vector<int> d[N];
ll cur = 1;
int m;

ll Pow(ll a, ll b, ll mod) {
    ll x = 1, y = a;
    while (b) {
        if (b % 2) x = x * y % mod;
        y = y * y % mod;
        b /= 2;
    }
    return x;
}

int phi(int n) {
    int ans = 0;
    fore(i, 1, n)
        if (__gcd(i, n) == 1) ++ans;
    return ans;
}

ll solve(int r, int nxt, int ph, int mod) {
    return (nxt / r) * Pow(cur / r, ph - 1, mod) % m;
}

void solve(int r) {
    if (d[r].empty()) return;
    ll tmp = r / __gcd((int)cur, m);
    cur = cur * tmp % m;
    int mod = m / r;
    int ph = phi(mod);
    cout << tmp * solve(r, d[r][0], ph, mod) % m << ' ';
    cur = d[r][0];
    forn(i, 1, d[r].size()) {
        cout << solve(r, d[r][i], ph, mod) << ' ';
        cur = d[r][i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n >> m;
    vector<int> good(m, 1);
    forn(i, 0, n) {
        int x;
        cin >> x;
        good[x] = 0;
    }
    forn(i, 1, m)
        if (good[i])
            d[__gcd(i, m)].eb(i);
    vector<int> dp(m + 1, 0), prev(m + 1, 1);
    forn(i, 1, m) {
        dp[i] += d[i].size();
        for (int j = 2 * i; j <= m; j += i) {
            if (dp[i] > dp[j]) {
                dp[j] = dp[i];
                prev[j] = i;
            }
        }
    }
    cout << dp[m] + good[0] << '\n';
    vector<int> path;
    int x = prev[m];
    while (x > 1) {
        path.eb(x);
        x = prev[x];
    }
    path.eb(1);
    reverse(all(path));
    for (int i : path) solve(i);
    if (good[0]) cout << 0 << ' ';
}