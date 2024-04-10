const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 22;
const long long INFLL = 1e18;

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;

#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second
#define re return
#define pb push_back
#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " " << #x << " " << x << endl
#define ln cerr << __LINE__ << endl
#else
#define dbg(x) void(0)
#define ln void(0)
#endif // LOCAL

int cx[4] = {-1, 0, 1, 0};
int cy[4] = {0, -1, 0, 1};
string Yes[2] = {"No\n", "Yes\n"};
string YES[2] = {"NO\n", "YES\n"};
string Possible[2] = {"Impossible\n", "Possible\n"};
string POSSIBLE[2] = {"IMPOSSIBLE\n", "POSSIBLE\n"};

signed main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int> > > g(n, vvi(2));
    for (int i = 0; i < m; i++)
    {
        int v, u, c;
        cin >> v >> u >> c;
        v--, u--;
        if (v == u) continue;
        g[u][c].push_back(v);
    }
    vector<int> d0(n, INF), d1(n, INF);
    d0[n - 1] = 0;
    d1[n - 1] = 0;
    vector<int> q = {n - 1};
    string s(n, '0');
    vector<int> pos(n);
    for (int i = 0; i < q.size(); i++)
    {
        int v = q[i];
        if (i != pos[v]) continue;
        int dist = max(d0[v], d1[v]) + 1;
        if (dist >= INF) continue;
        for (auto u : g[v][0]) if (d0[u] == INF)
        {
            d0[u] = dist;
            pos[u] = q.size();
            q.push_back(u);
        }
        for (auto u : g[v][1]) if (d1[u] == INF)
        {
            d1[u] = dist;
            pos[u] = q.size();
            q.push_back(u);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (d0[i] > d1[i]) s[i] = '0';
        else s[i] = '1';
    }
    /*for (int i = 0; i < n; i++)
    {
        cout << d0[i] << " " << d1[i] << "\n";
    }
    for (int i = 0; i < q.size(); i++)
    {
        cout << q[i] << " ";
    }
    cout << endl;*/
    for (int i = 0; i < n; i++)
    {
        int d = max(d0[i], d1[i]);
        for (auto u : g[i][0])
        {
            assert(d0[u] <= d + 1);
        }
        for (auto u : g[i][1])
        {
            assert(d1[i] <= d + 1);
        }
    }
    if (max(d0[0], d1[0]) >= INF) cout << -1 << "\n";
    else cout << max(d0[0], d1[0]) << "\n";
    cout << s;
}

/* Note:
Check constants at the beginning of the code (MOD, INF, INFLL)
Check corner cases.
    N = 1
No def int long long for now.
Add something here.
*/