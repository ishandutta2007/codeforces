#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n - 1); i >= (int)(a); --i)
#define fore(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
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

template<typename T>
inline void setmax(T& a, T b) {
    if (a < b) a = b;
}

template<typename T>
inline void setmin(T& a, T b) {
    if (a > b) a = b;
}

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 1e5 + 10;
vector<int> e[N];
int n, m, k, x;

vector<ll> le[N], eq[N], gr[N];

vector<ll> operator*(vector<ll> a, vector<ll> b) {
    vector<ll> ans(x + 1);
    fore(i, 0, x)
        fore(j, 0, x - i) {
            ans[i + j] += a[i] * b[j];
            ans[i + j] %= MOD;
        }
    return ans;
}

vector<ll> operator+(vector<ll> a, vector<ll>& b) {
    fore(i, 0, x) {
        a[i] += b[i];
        if (a[i] >= MOD) a[i] -= MOD;
    }
    return a;
}

void dfs(int u, int p) {
    le[u].resize(x + 1);
    eq[u].resize(x + 1);
    gr[u].resize(x + 1);
    le[u][0] = k - 1;
    eq[u][1] = 1;
    gr[u][0] = m - k;
    for (int v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
        le[u] = le[u] * (le[v] + eq[v] + gr[v]);
        eq[u] = eq[u] * le[v];
        gr[u] = gr[u] * (gr[v] + le[v]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    cin >> n >> m;
    forn(i, 1, n) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        e[u].eb(v);
        e[v].eb(u);
    }
    cin >> k >> x;
    dfs(0, -1);
    ll ans = 0;
    fore(i, 0, x) ans += le[0][i] + eq[0][i] + gr[0][i];
    cout << ans % MOD << '\n';
}