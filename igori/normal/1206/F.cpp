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

ll n;
vector<int> graph[50000];
int sz[50000];
int centroid;
int way[50000];
int bigi;

void dfs(int v)
{
    sz[v] = 1;
    for (auto u : graph[v])
    {
        if (sz[u] == 0)
        {
            dfs(u);
            sz[v] += sz[u];
        }
    }
}

vector<int> ai;

void call(int v)
{
    if (v == centroid) return;
    way[v] = ai[bigi];
    bigi++;
    for (int i = 0; i < graph[v].size(); i++)
    {
        int u = graph[v][i];
        if (way[u] == -1)
        {
            call(u);
        }
    }
}

int mark[50000];

void description(int v, int p)
{
    if (p != -1)
    {
        cout << p << " " << v << " " << way[v] - way[p] << "\n";
    }
    mark[v] = 1;
    for (auto u : graph[v])
    {
        if (mark[u] != 1)
        {
            description(u, v);
        }
    }
}

signed main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    cin >> n;
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        cout << "1 2 1";
        return 0;
    }
    for (int i = 0; i + 1 < n; i++)
    {
        int v, u;
        cin >> v >> u;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    dfs(1);
    centroid = 0;
    for (int i = 1; i <= n; i++)
    {
        int all_sz = n - sz[i], t = 1;
        for (auto u : graph[i])
        {
            if (sz[u] > sz[i]) continue;
            if (sz[u] * 2 > n) t = 0;
        }
        if (all_sz * 2 > n) t = 0;
        if (t)
        {
            centroid = i;
            break;
        }
    }
    fill(sz, sz + n + 1, 0);
    fill(way, way + n + 1, -1);
    dfs(centroid);
    int r = (n + 2) / 3;
    set<pair<int, vector<int> > > s;
    for (auto u : graph[centroid])
    {
        s.insert({sz[u], {u}});
    }
    while (s.size() > 2)
    {
        auto it = s.begin();
        pair<int, vector<int> > d = *it;
        it++;
        pair<int, vector<int> > e = *it;
        s.erase(d);
        s.erase(e);
        int total = d.first + e.first;
        vector<int> all;
        for (int i = 0; i < d.second.size(); i++)
        {
            all.push_back(d.second[i]);
        }
        for (int i = 0; i < e.second.size(); i++)
        {
            all.push_back(e.second[i]);
        }
        s.insert({total, all});
    }
    auto it = s.begin();
    pair<int, vector<int> > d = *it;
    it++;
    pair<int, vector<int> > e = *it;
    bigi = 0;
    for (int i = 1; i <= d.first; i++)
    {
        ai.push_back(i);
    }
    for (int i = 0; i < d.second.size(); i++)
    {
        int u = d.second[i];
        call(u);
    }
    ai.resize(0);
    bigi = 0;
    for (int i = 1; i <= e.first; i++)
    {
        ai.push_back(i * (d.first + 1));
    }
    for (int i = 0; i < e.second.size(); i++)
    {
        int u = e.second[i];
        call(u);
    }
    way[centroid] = 0;
    description(centroid, -1);
}