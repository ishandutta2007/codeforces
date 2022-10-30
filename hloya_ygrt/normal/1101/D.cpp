#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
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
typedef pair<int, int> pii;
typedef list<int> vi;
typedef unsigned long long ull;

//mt19937_64 mt_rand(chrono::system_clock::now().time_since_epoch().count());

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }

const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-9;
const ld PI = acos(-1.);
const ll llinf = (ll) 1e18 + 5;
const int inf = 2e9 + 5;
const int maxn = 2e5 + 500;

int ans = 0;
vector<int> g[maxn];
int a[maxn];

vector<int> d[maxn], dp[maxn];
map<int, int> sot[maxn];

void dfs(int v, int p = -1) {
    dp[v].assign(d[a[v]].size(), 1);

    if (a[v] != 1) {
        ans = max(ans, 1);
    } else {
        assert(d[a[v]].size() == 0);
    }

    for (int to : g[v])
        if (to != p) {
            dfs(to, v);

            for (int i = 0; i < d[a[v]].size(); i++)
                if (sot[a[to]].count(d[a[v]][i])) {
                    ans = max(ans, dp[v][i] + dp[to][sot[a[to]][d[a[v]][i]]]);
                }

            for (int i = 0; i < d[a[v]].size(); i++)
                if (sot[a[to]].count(d[a[v]][i])) {
                    dp[v][i] = max(dp[v][i], 1 + dp[to][sot[a[to]][d[a[v]][i]]]);
                    ans = max(ans, dp[v][i]);
                }
        }
}

bool isp[maxn];

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    memset(isp, 1, sizeof(isp));

    for (int i = 2; i < maxn; i++)
        if (isp[i]) {
            for (int j = i; j < maxn; j += i) {
                isp[j] = 0;
                d[j].pb(i);
                sot[j][i] = d[j].size() - 1;
            }
        }

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i + 1 < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(0);

    cout << ans;
    return 0;
}