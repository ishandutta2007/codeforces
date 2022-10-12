const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long long INFLL = 1e18;

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef complex<double> cd;

#define forn(i, n) for (int i = 0; (i) != (n); (i)++)
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

void dfs(int v, vector<vector<pii> > &g, string &ori, char c)
{
    if (ori[v] != '.' && ori[v] != c)
    {
        cout << "NO\n";
        exit(0);
    }
    if (ori[v] == c) return;
    ori[v] = c;
    for (auto e : g[v]) dfs(e.first, g, ori, 'L' + 'R' - c);
}

struct graph_scc{
    // Finds Strongly Connected Components of given graph
    //
    // Correctness tested on the following problem:
    // https://atcoder.jp/contests/arc069/tasks/arc069_d
    //
    int n;
    vector<vector<int> > graph;
    vector<vector<int> > inv_graph;
    vector<int> fr, to;
    vector<int> fn;
    vector<int> vis;
    vector<int> component;
    int col;
    void inv_dfs(int v)
    {
        vis[v] = 1;
        for (auto id : inv_graph[v])
        {
            int u = fr[id];
            if (!vis[u])
            {
                inv_dfs(u);
            }
        }
        fn.push_back(v);
    }
    void dfs(int v)
    {
        component[v] = col;
        for (auto id : graph[v])
        {
            int u = to[id];
            if (component[u] == -1)
            {
                dfs(u);
            }
        }
    }
    graph_scc(int _n)
    {
        n = _n;
        graph = vector<vector<int> >(n);
        inv_graph = vector<vector<int> >(n);
    }
    void add_edge(int v, int u)
    {
        graph[v].push_back(fr.size());
        inv_graph[u].push_back(fr.size());
        fr.push_back(v);
        to.push_back(u);
    }
    vector<vector<int> > scc()
    {
        vis = vector<int>(n);
        component = vector<int>(n, -1);
        fn = {};
        col = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                inv_dfs(i);
            }
        }
        reverse(fn.begin(), fn.end());
        for (auto i : fn)
        {
            if (component[i] == -1)
            {
                dfs(i);
                col++;
            }
        }
        vector<vector<int> > res(col);
        for (int i = 0; i < n; i++)
        {
            res[component[i]].push_back(i);
        }
        return res;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pii> > g(n);
    forn(i, m)
    {
        int t, v, u;
        cin >> t >> v >> u;
        v--, u--;
        g[v].push_back({u, t});
        g[u].push_back({v, t});
    }
    string ori(n, '.');
    for (int i = 0; i < n; i++)
    {
        if (ori[i] == '.')
        {
            dfs(i, g, ori, 'L');
        }
    }
    graph_scc G(n);
    for (int v = 0; v < n; v++)
    {
        if (ori[v] == 'R')
        {
            for (auto e : g[v])
            {
                if (e.second == 2)
                    G.add_edge(e.first, v);
                else
                    G.add_edge(v, e.first);
            }
        }
    }
    vector<vector<int> > scc = G.scc();
    vector<int> pos(n);
    for (int i = 0; i < scc.size(); i++) if (scc[i].size() >= 2)
    {
        #ifdef LOCAL
        cout << "no\n";
        #else
        cout << "NO\n";
        #endif
        return;
    }
    else
    {
        pos[scc[i][0]] = i;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
        cout << ori[i] << " " << pos[i] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifdef LOCAL
    cout << "\n";
    #endif // LOCAL

    int t = 1;
    #ifdef tests
    cin >> t;
    #endif // tests
    while (t--)
    {
        solve();
    }
}