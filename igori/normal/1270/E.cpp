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
#include <stdio.h>
#include <string.h>
#include <random>
#include <functional>

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
using std::fill;

using std::setprecision;
using std::fixed;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

ll min(ll a, ll b) {return a < b ? a : b;}
ll min(int a, ll b) {return a < b ? a : b;}
ll min(ll a, int b) {return a < b ? a : b;}
ll min(int a, int b) {return a < b ? a : b;}

ll max(ll a, ll b) {return a > b ? a : b;}
ll max(int a, ll b) {return a > b ? a : b;}
ll max(ll a, int b) {return a > b ? a : b;}
ll max(int a, int b) {return a > b ? a : b;}

namespace MySpace{

};

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()
#define NAME ""
#define int long long

int n, x[50000], y[50000];
int d[1500][1500];
int ans[1500];
vector<int> graph[5000];
int color[1500];
int fl = 0;

void dfs(int v)
{
    if (color[v]) return;
    color[v] = fl;
    for (auto u : graph[v]) dfs(u);
}

int root[1500000];
int sz[1500000];
int select[1500000];
int res[1500000];

int g(int a, int b)
{
    if (a > b) swap(a, b);
    return a * 1007 + b;
}

int Root(int v)
{
    if (v == root[v]) return v;
    return root[v] = Root(root[v]);
}

void Merge(int a, int b)
{
    a = Root(a), b = Root(b);
    if (sz[a] < sz[b])
    {
        sz[b] += sz[a];
        root[a] = b;
    }
    else
    {
        sz[a] += sz[b];
        root[b] = a;
    }
}

signed main()
{
    //if (NAME != "") { freopen(NAME ".in", "r", stdin); freopen(NAME ".out", "w", stdout); }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int CNT = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        if ((x[i] + y[i]) % 2 == 0) CNT++;
    }
    int r = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[i][j] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
    for (int i = 0; i < n; i++)
    {
        vector<pair<int, int> > v;
        for (int j = 0; j < n; j++)
        {
            if (i != j) v.push_back({d[i][j], j});
        }
        sort(v.begin(), v.end());
        for (int j = 0; j + 1 < v.size(); j++)
        {
            if (v[j].first == v[j + 1].first)
            {
                graph[v[j].second].push_back(v[j + 1].second);
                graph[v[j + 1].second].push_back(v[j].second);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (color[i] == 0)
        {
            fl++;
            dfs(i);
        }
    }
    vector<pair<int, pii> > v;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (i != j) v.push_back({d[i][j], {color[i], color[j]}});
    sort(all(v));
    for (int i = 0; i < 1500000; i++) root[i] = i, sz[i] = 1;
    for (int i = 0; i + 1 < v.size(); i++)
    {
        if (v[i].first == v[i + 1].first)
        {
            Merge(g(v[i].se.fi, v[i].se.se), g(v[i + 1].se.fi, v[i + 1].se.se));
            //cout << v[i].se.fi << " " << v[i].se.se << " -> " << v[i + 1].se.fi << " " << v[i + 1].se.se << endl;
            //cout << g(v[i].se.fi, v[i].se.se) << " " << g(v[i + 1].se.fi, v[i + 1].se.se) << endl;
        }
    }
    select[1] = 1;
    for (int i = 2; i <= fl; i++)
    {
        int should_take = 0;
        for (int j = 1; j < i; j++)
        {
            if (res[Root(g(i, j))] == 1 && select[j] == 1) should_take = 1;
            if (res[Root(g(i, j))] == 1 && select[j] == 2) should_take = 2;
            if (res[Root(g(i, j))] == 2 && select[j] == 2) should_take = 1;
            if (res[Root(g(i, j))] == 2 && select[j] == 1) should_take = 2;
        }
        if (should_take == 0 || should_take == 2)
        {
            select[i] = 2;
            for (int j = 1; j < i; j++)
            {
                if (select[j] == 1) {res[Root(g(i, j))] = 2;}
                if (select[j] == 2) {res[Root(g(i, j))] = 1;}
            }
        }
        else
        {
            select[i] = 1;
            for (int j = 1; j < i; j++)
            {
                if (select[j] == 2) {res[Root(g(i, j))] = 2;}
                if (select[j] == 1) {res[Root(g(i, j))] = 1;}
            }
        }
    }

    vector<int> ans;
    //for (int i = 0; i < n; i++) cout << color[i] << " ";
    //cout << endl;
    //for (int i = 0; i < n; i++) cout << select[color[i]] << " ";
    //cout << endl;
    for (int i = 0; i < n; i++) if (select[color[i]] == 1) ans.push_back(i + 1);
    cout << ans.size() << "\n";
    for (auto e : ans) cout << e << " ";
}