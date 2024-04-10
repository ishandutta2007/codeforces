#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef complex<double> cd;

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

const int INF = 1e9;

void dfs(int v, int p, vvi &graph, vi &d1, vi &d2, vi &papa)
{
    papa[v] = p;
    for (auto u : graph[v]) if (u != p)
    {
        dfs(u, v, graph, d1, d2, papa);
        int d = d1[u] + 1;
        if (d > d1[v])
        {
            d2[v] = d1[v];
            d1[v] = d;
        }
        else if (d > d2[v])
        {
            d2[v] = d;
        }
    }
}

void solve()
{
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    vector<vector<int> > graph(n);
    for (int i = 0; i < n - 1; i++)
    {
        int v, u;
        cin >> v >> u;
        v--, u--;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    if (db < 2 * da + 1)
    {
        cout << "Alice\n";
        return;
    }
    a--, b--;
    db = 2 * da + 1;
    /*vector<int> d1(n), d2(n), papa(n);
    dfs(0, 0, graph, d1, d2);
    vector<int> dpup(n);
    dfs2(0, 0, graph, d1, d2, dpup);
    */
    vector<int> distA(n, INF), distB(n, INF);
    vector<int> q = {a};
    distA[a] = 0;
    for (int i = 0; i < q.size(); i++)
    {
        for (auto u : graph[q[i]])
        {
            if (distA[u] == INF)
            {
                distA[u] = distA[q[i]] + 1;
                q.push_back(u);
            }
        }
    }
    if (distA[b] <= da)
    {
        cout << "Alice\n";
        return;
    }
    /*
    q = {b};
    distB[b] = 0;
    for (int i = 0; i < q.size(); i++)
    {
        for (auto u : graph[q[i]])
        {
            if (distB[u] == INF)
            {
                distB[u] = distB[q[i]] + 1;
                q.push_back(u);
            }
        }
    }*/
    q = {0};
    vector<int> dist1(n, INF);
    dist1[0] = 0;
    for (int i = 0; i < q.size(); i++)
    {
        for (auto u : graph[q[i]])
        {
            if (dist1[u] == INF)
            {
                dist1[u] = dist1[q[i]] + 1;
                q.push_back(u);
            }
        }
    }
    int id = 0;
    for (int i = 0; i < n; i++)
    {
        if (dist1[i] > dist1[id])
        {
            id = i;
        }
    }
    fill(all(dist1), INF);
    dist1[id] = 0;
    q = {id};
    for (int i = 0; i < q.size(); i++)
    {
        for (auto u : graph[q[i]])
        {
            if (dist1[u] == INF)
            {
                dist1[u] = dist1[q[i]] + 1;
                q.push_back(u);
            }
        }
    }
    int mx = *max_element(all(dist1));
    if (mx >= db)
    {
        cout << "Bob\n";
    }
    else
    {
        cout << "Alice\n";
    }
}

signed main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

/* Note:
Check constants at the beginning of the code.
    N is set to 4e5 but be careful in problems with large constant factor.
    Setting N in every problem is more effective.
Check corner cases.
    N = 1
No def int long long for now.
Add something here.
*/