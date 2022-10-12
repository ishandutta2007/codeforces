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

const long long inf = 1e18;
const long long infsmart = 1e12;

void Set(int l, int r, int L, int R, int V, int val)
{
    if (l <= L && R <= r)
    {
        //Tree[V] = max(val, Tree[V]);
        return;
    }
    if (r <= L || R <= l)
        return;
}

long long Get(int l, int r, int L, int R, int V)
{
    if (l <= L && R <= r)
    {
        //return Tree[V];
    }
    if (r <= L || R <= l)
    {
        return 0;
    }
}

const long long MOD = 1e9 + 7;
const int MX = 5e5;

int n, m, ans[MX], called[10][MX];
int dist[MX];
vector<pair<int, int> > graph[MX];

int Free;

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.se < b.se;
}

vector<int> go[10 * MX];
int Open = 1;

void dfs(int link, long long res)
{
    if (go[link].size() == 0)
        return;
    for (int i = 0; i < go[link].size(); i++)
    {
        if (ans[go[link][i]] == -1)
            ans[go[link][i]] = res;
    }
    for (int i = 0; i < go[link].size(); i++)
    {
        int v = go[link][i];
        for (int j = 0; j < graph[v].size(); j++)
        {
            int u = graph[v][j].first;
            int d = graph[v][j].second;
            if (called[d][u] == 0 && dist[u] == dist[v] + 1 && ans[u] == -1)
            {
                called[d][u]++;
                go[Open + d].push_back(u);
            }
        }
    }
    int curd = Open;
    Open = Open + 10;
    for (int d = 0; d < 10; d++)
    {
        dfs(curd + d, (res * 10 + d) % MOD);
        go[curd + d].shrink_to_fit();
    }
}

signed main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    cin >> n >> m;
    Free = n + 1;
    for (int i = 1; i <= m; i++)
    {
        vector<int> DigitRepresentation;
        int j = i;
        //cin >> j;
        while (j > 0)
        {
            DigitRepresentation.push_back(j % 10);
            j /= 10;
        }
        reverse(DigitRepresentation.begin(), DigitRepresentation.end());
        int v, u;
        cin >> v >> u;
        vector<int> k;
        k.push_back(v);
        for (int j = 0; j < DigitRepresentation.size() - 1; j++)
        {
            k.push_back(Free);
            Free++;
        }
        k.push_back(u);
        for (int j = 0; j + 1 < k.size(); j++)
        {
            graph[k[j]].push_back({k[j + 1], DigitRepresentation[j]});
        }
        swap(k[0], k[k.size() - 1]);
        for (int j = 0; j + 1 < k.size(); j++)
        {
            graph[k[j]].push_back({k[j + 1], DigitRepresentation[j]});
        }
    }
    int N = Free - 1;
    for (int i = 1; i <= N; i++) sort(graph[i].begin(), graph[i].end());
    for (int i = 1; i <= N; i++) dist[i] = 1e9;
    for (int i = 1; i <= N; i++) ans[i] = -1;
    dist[1] = 0;
    vector<int> q = {1};
    for (int i = 0; i < q.size(); i++)
    {
        int v = q[i];
        for (int j = 0; j < graph[q[i]].size(); j++)
        {
            int u = graph[q[i]][j].first;
            if (dist[u] == 1e9)
            {
                dist[u] = dist[v] + 1;
                q.push_back(u);
            }
        }
    }
    go[0] = {1};
    dfs(0, 0);
    for (int i = 2; i <= n; i++)
    {
        cout << ans[i] << "\n";
    }
}