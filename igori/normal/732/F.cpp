#pragma GCC optimize("O2")
//#pragma GCC optimize("O3")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
#include <bitset>


typedef long long ll;

using namespace std;

#define all(x) x.begin(), x.end()
const long long INF = 1e9;
#define int long long

ll n, m;
ll ans;

struct edge{
    int v, u;
    int id;
    int reversed;
    int bridge;
};

vector<edge> edges;
vector<int> g[500000];
int num[500000];
int t = 1;
int up[500000];
int c[500000];
int fl = 1;

vector<pair<int, pair<int, int> > > g2[500000];
int cnt[500000];

int can(int x)
{
    if (edges[x].bridge == 0)
        return 1;
    return 0;
}

int go(int v, int x)
{
    edge e = edges[x];
    if (v == e.v)
        return e.u;
    return e.v;
}

void dfs(int v, int p)
{
    if (num[v] != 0)
        return;
    num[v] = t++;
    up[v] = num[v];
    for (int i = 0; i < g[v].size(); i++)
    {
        int u = go(v, g[v][i]);
        dfs(u, v);
        if (u != p)
        {
            up[v] = min(up[v], up[u]);
        }
    }
}

void dfs2(int v)
{
    if (c[v] != 0)
        return;
    //cout << v << " ";
    c[v] = fl;
    for (int i = 0; i < g[v].size(); i++)
    {
        if (can(g[v][i]))
        {
            int u = go(v, g[v][i]);
            edge E = edges[g[v][i]];
            if (c[u] == 0)
            {
                if (E.reversed == 0)
                {
                    //cout << E.v << " " << E.u << endl;
                    if (E.v == v)
                        edges[g[v][i]].reversed = 1;
                    else
                        edges[g[v][i]].reversed = 2;
                }
            }
            else
            {
                if (E.reversed == 0)
                {
                    //cout << " 1 " << v << " " << E.v << " " << E.u << endl;
                    if (E.v == v)
                        edges[g[v][i]].reversed = 1;
                    else
                        edges[g[v][i]].reversed = 2;
                }
            }
            dfs2(u);
        }
    }
}

int vis[500000];

void dfs3(int r)
{
    vis[r] = 1;
    for (int i = 0; i < g2[r].size(); i++)
    {
        int u = g2[r][i].first;
        edge E = edges[g2[r][i].second.first];
        int ordered = g2[r][i].second.second;
        if (vis[u] == 0)
        {
            if (ordered == 1)
            {
                edges[g2[r][i].second.first].reversed = 1;
            }
            dfs3(u);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("prediction.in", "r", stdin);
    //freopen("prediction.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v, u;
        cin >> v >> u;
        edges.push_back({v, u, i, 0, 0});
        g[u].push_back(i);
        g[v].push_back(i);
    }
    fill(up, up + n + 1, INF);
    dfs(1, 0);
    for (int i = 0; i < m; i++)
    {
        edge E = edges[i];
        if (up[E.u] > num[E.v] || up[E.v] > num[E.u])
        {
            edges[i].bridge = 1;
            //cout << 1;
        }
        else
        {
            //cout << 0;
        }
    }
    //cout << endl;
    for (int i = 1; i <= n; i++)
    {
        if (c[i] == 0)
        {
            dfs2(i);
            fl++;
        }
    }
    for (int i = 0; i < m; i++)
    {
        edge E = edges[i];
        if (E.bridge == 1)
        {
            g2[c[E.u]].push_back({c[E.v], {i, 0}});
            g2[c[E.v]].push_back({c[E.u], {i, 1}});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cnt[c[i]]++;
    }
    ll ans = 0, rn = 0;
    for (int i = 1; i <= fl; i++)
    {
        ans = max(ans, cnt[i]);
        if (cnt[i] == ans)
            rn = i;
    }

    dfs3(rn);

    cout << ans << "\n";
    for (int i = 0; i < m; i++)
    {
        if (edges[i].reversed == 1)
            swap(edges[i].v, edges[i].u);
        cout << edges[i].v << " " << edges[i].u << "\n";
    }
}