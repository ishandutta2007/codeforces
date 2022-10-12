#include <bits/stdc++.h>

const int INF = 1e9;

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

void dfs(int v, int p, vector<vi> &graph, vi &sz)
{
    sz[v] = 1;
    for (auto u : graph[v]) if (u != p)
    {
        dfs(u, v, graph, sz);
        sz[v] += sz[u];
    }
}

void dfs(int v, int p, vector<vi> &graph, vi &c, int C)
{
    c[v] = C;
    for (auto u : graph[v]) if (u != p)
    {
        dfs(u, v, graph, c, C);
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
    vector<int> sz(n);
    dfs(0, 0, graph, sz);
    vector<int> cen;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if ((n - sz[i]) * 2 <= n)
        {
            int t = 1;
            for (auto u : graph[i])
            {
                if (sz[u] < sz[i])
                {
                    if (2 * sz[u] <= n) continue;
                    t = 0;
                }
            }
            if (t) cen.push_back(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        ans += 2 * min(sz[i], n - sz[i]);
    }
    cout << ans << "\n";
    if (cen.size() == 2)
    {
        int v = cen[0], u = cen[1];
        vector<int> c(n);
        dfs(v, u, graph, c, 0);
        dfs(u, v, graph, c, 1);
        vector<int> p0, p1;
        for (int i = 0; i < n; i++)
        {
            if (c[i] == 0) p0.push_back(i);
            if (c[i] == 1) p1.push_back(i);
        }
        vector<int> ans(n);
        for (int i = 0; i < n / 2; i++)
        {
            ans[p0[i]] = p1[i];
            ans[p1[i]] = p0[i];
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] + 1 << " ";
        }
        return 0;
    }
    else
    {
        dfs(cen[0], cen[0], graph, sz);
        int C = 0, idC = 0;
        vector<int> c(n);
        c[cen[0]] = -1;
        int maxsz = 0;
        for (auto u : graph[cen[0]])
        {
            dfs(u, cen[0], graph, c, C);
            maxsz = max(maxsz, sz[u]);
            if (maxsz == sz[u]) idC = C;
            C++;
        }
        vector<pair<int, int> > q;
        for (int i = 0; i < n; i++)
        {
            if (i != cen[0] && c[i] != idC)
                q.push_back({c[i], i});
        }
        for (int i = 0; i < n; i++)
        {
            if (i != cen[0] && c[i] == idC)
                q.push_back({INF, i});
        }
        q.push_back({INF + 1, cen[0]});
        sort(all(q));
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[q[i].se] = q[(i + maxsz) % q.size()].se;
        }
        for (int i = 0; i < n; i++)
        {
            assert(c[ans[i]] != c[i]);
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