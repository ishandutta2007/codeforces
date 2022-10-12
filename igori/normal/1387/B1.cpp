#include <bits/stdc++.h>

const int INF = 1e9;
const int N = 500000;

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

vector<int> child[N];

void dfs(int v, int p, vector<vi> &graph, vector<int> &papa, vector<int> &depth)
{
    depth[v] = depth[p] + 1;
    papa[v] = p;
    for (auto u : graph[v]) if (u != p)
    {
        child[v].push_back(u);
        dfs(u, v, graph, papa, depth);
    }
}

signed main()
{
    int n;
    cin >> n;
    vector<vi> graph(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    vector<int> papa(n), depth(n);
    int rt = 0;
    dfs(rt, rt, graph, papa, depth);
    set<pair<int, int> > s;
    for (int i = 0; i < n; i++)
    {
        s.insert({-depth[i], i});
    }
    vector<int> live(n, 1);
    vector<vector<int> > cycles;
    while (s.size())
    {
        if (s.size() == 1)
        {
            pair<int, int> x = *(s.begin());
            if (!live[x.se])
            {
                s.erase(s.begin());
                continue;
            }
            cycles[cycles.size() - 1].push_back(x.se);
            break;
        }
        pair<int, int> x = *(s.begin());
        if (!live[x.se])
        {
            s.erase(s.begin());
            continue;
        }
        int V = papa[x.se];
        vector<int> cycle = {V};
        for (auto u : child[V])
        {
            if (live[u])
            {
                cycle.push_back(u);
                live[u] = 0;
            }
        }
        live[V] = 0;
        cycles.push_back(cycle);
    }
    /*cout << cycles.size() << "\n";
    for (auto u : cycles)
    {
        for (auto x : u)
        {
            cout << x + 1 << " ";
        }
        cout << "\n";
    }*/
    int ans = 0;
    for (auto u : cycles)
    {
        ans += 2 * (u.size() - 1);
    }
    cout << ans << "\n";
    {
        vector<int> ans(n);
        for (auto u : cycles)
        {
            for (int i = 0; i < u.size(); i++)
            {
                ans[u[i]] = u[(i + 1) % u.size()];
            }
        }
        forn(i, n)
        {
            cout << ans[i] + 1 << " ";
        }
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