#include <bits/stdc++.h>

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
using namespace std;

#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back

#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define sqr(x) ((x) * (x))

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;


//mt19937_64 mt_rand(chrono::system_clock::now().time_since_epoch().count());

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }

const int maxn = (int) 6e5 + 5;
const int maxlog = 21;
const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-9;
const ld PI = acos(-1.);
const ll llinf = 1e18;
const int inf = 2e9;

ll w[maxn], d[maxn];
vector<pii> g[maxn];

void dfs(int v, int par, ll mx) {
    d[v] = mx;

    for (auto e : g[v]) {
        int to = e.f, len = e.s;
        if (to == par) continue;

        dfs(to, v, max(mx - len + w[to], w[to]));
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> w[i];

    for (int i = 0; i + 1 < n; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        g[u].pb(mp(v, c));
        g[v].pb(mp(u, c));
    }

    dfs(0, -1, w[0]);

    int best_v = -1;
    for (int i = 0; i < n; i++) {
        // cout << d[i] << endl;
        if (best_v == -1 || d[best_v] < d[i])
            best_v = i;
    }
    // cout << best_v << endl;
    dfs(best_v, -1, w[best_v]);

    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, d[i]);
    cout << ans;
    return 0;
}