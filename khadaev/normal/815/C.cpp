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

const int N = 5010;
vector<int> ch[N];
int c[N], d[N];
vector<ll> dp1[N], dp2[N];

vector<ll> operator+ (vector<ll> a, vector<ll> b) {
    assert(a.size() == b.size());
    vector<ll> ans(a.size(), LINF);
    forn(i, 0, a.size()) ans[i] = min(a[i], b[i]);
    return ans;
}

vector<ll> operator* (vector<ll> a, vector<ll> b) {
    vector<ll> ans(a.size() + b.size() - 1, LINF);
    forn(i, 0, a.size())
        forn(j, 0, b.size()) ans[i + j] = min(ans[i + j], a[i] + b[j]);
    return ans;
}

void dfs(int u) {
    dp1[u] = {LINF, c[u] - d[u]};
    dp2[u] = {0, c[u]};
    for (int v : ch[u]) {
        dfs(v);
        dp1[u] = dp1[u] * (dp1[v] + dp2[v]);
        dp2[u] = dp2[u] * dp2[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, b;
    cin >> n >> b;
    forn(i, 0, n) {
        cin >> c[i] >> d[i];
        if (i) {
            int x;
            cin >> x;
            ch[--x].eb(i);
        }
    }
    dfs(0);
    int ans = 0;
    vector<ll> v = dp1[0] + dp2[0];
    for (int i = 0; i < v.size(); ++i)
        if (v[i] <= b) ans = max(ans, i);
    cout << ans << '\n';
}