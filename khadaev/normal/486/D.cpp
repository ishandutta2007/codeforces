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

int d, n;
vector<int> a;
int cur;
vector<ll> cnt;
vector<int> e[2017];

bool good(int v) {
    if (a[v] > a[cur]) return false;
    if (a[v] == a[cur]) return v <= cur;
    return a[v] >= a[cur] - d;
}

void solve(int v, int p) {
    if (!good(v)) return;
    cnt[v] = 1;
    for (int u : e[v]) {
        if (u == p) continue;
        solve(u, v);
        cnt[v] *= 1 + cnt[u];
        cnt[v] %= MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> d >> n;
    a.resize(n);
    cnt.resize(n);
    forn(i, 0, n) cin >> a[i];
    forn(i, 1, n) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        e[u].eb(v);
        e[v].eb(u);
    }
    ll ans = 0;
    forn(i, 0, n) {
        fill(all(cnt), 0);
        cur = i;
        solve(i, -1);
        ans += cnt[i];
    }
    cout << ans % MOD << '\n';
}