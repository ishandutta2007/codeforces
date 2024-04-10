#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <iomanip>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::map;
using std::set;
using std::bitset;
using std::vector;
using std::string;
using std::multimap;
using std::multiset;
using std::deque;
using std::queue;
using std::stack;
using std::pair;
using std::iterator;

using std::sort;
using std::stable_sort;
using std::reverse;
using std::max_element;
using std::min_element;
using std::unique;
using std::ios_base;
using std::swap;
using std::min;
using std::max;
using std::fill;

using std::setprecision;
using std::fixed;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

namespace MySpace{

};

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()
#define int long long

struct Edge{
    int v, u;
    int is_bridge;
};

vector<Edge> edges;
vector<int> graph[500000];

int go(int v, int id)
{
    return edges[id].u + edges[id].v - v;
}

int n, m, s;
ll w[500000];

int In[500000];
int Out[500000];
int T = 1;
int Up[500000];
int H[500000];

void dfs(int v, int p, int h)
{
    H[v] = h;
    In[v] = T++;
    Up[v] = In[v];
    for (int i = 0; i < graph[v].size(); i++)
    {
        int u = go(v, graph[v][i]);
        if (u == p)
            continue;
        if (In[u] != 0)
        {
            Up[v] = min(Up[v], Up[u]);
        }
        else
        {
            dfs(u, v, h + 1);
            Up[v] = min(Up[v], Up[u]);
        }
    }
    Out[v] = T++;
}

int color[500000];
int paint = 1;

int cnt_of_color[500000];
ll values[500000];

void dfs(int v)
{
    if (color[v] != 0) return;
    color[v] = paint;
    for (int i = 0; i < graph[v].size(); i++)
    {
        int u = go(v, graph[v][i]);
        if (edges[graph[v][i]].is_bridge == 1) continue;
        dfs(u);
    }
}

vector<int> colored_graph[500000];

int dp1[500000];
ll kek[500000];
ll mark[500000];

void dfs2(int v)
{
    mark[v] = 1;
    kek[v] = values[v];
    if (cnt_of_color[v] > 1) dp1[v] = 1;
    for (int i = 0; i < colored_graph[v].size(); i++)
    {
        int u = colored_graph[v][i];
        if (mark[u] == 0)
        {
            dfs2(u);
            dp1[v] = max(dp1[v], dp1[u]);
            kek[v] = max(kek[v], kek[u] + values[v]);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 0; i < m; i++)
    {
        int v, u;
        cin >> v >> u;
        graph[v].push_back(i);
        graph[u].push_back(i);
        edges.push_back({v, u, 0});
    }
    cin >> s;
    dfs(s, -1, 1);
    for (int i = 0; i < m; i++)
    {
        if (H[edges[i].u] < H[edges[i].v])
        {
            swap(edges[i].u, edges[i].v);
        }
        int upp = Up[edges[i].u];
        int inn = In[edges[i].u];
        if (upp == inn)
        {
            edges[i].is_bridge = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
        {
            dfs(i);
            paint++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cnt_of_color[color[i]]++;
        values[color[i]] += w[i];
    }
    for (int i = 0; i < m; i++)
    {
        if (edges[i].u != edges[i].v)
        {
            colored_graph[color[edges[i].u]].push_back(color[edges[i].v]);
            colored_graph[color[edges[i].v]].push_back(color[edges[i].u]);
        }
    }
    dfs2(color[s]);
    ll ans = 0;
    for (int i = 1; i < paint; i++)
    {
        if (dp1[i] == 0)
        {
            ans = max(ans, kek[i]);
        }
    }
    //for (int i = 1; i < paint; i++) cout << kek[i] << " "; cout << endl;
    //for (int i = 1; i < paint; i++) cout << dp1[i] << " "; cout << endl;
    for (int i = 1; i < paint; i++)
    {
        if (dp1[i] == 1)
        {
            ans += values[i];
        }
    }
    cout << ans << endl;
}