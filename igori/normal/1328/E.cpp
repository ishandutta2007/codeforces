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
#define int long long

const int N = 510200;

int n, m;
vector<int> graph[N];
int In[N], Out[N], p[N], d[N];
int T = 1;

void dfs(int v, int par)
{
    d[v] = d[par] + 1;
    p[v] = par;
    In[v] = T++;
    for (auto u : graph[v])
    {
        if (In[u] == 0)
        {
            dfs(u, v);
        }
    }
    Out[v] = T++;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i + 1 < n; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0);
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        vector<int> a(k);
        int max_d = 0, id = 0;
        for (int j = 0; j < k; j++)
        {
            cin >> a[j];
            if (d[a[j]] > max_d)
            {
                max_d = d[a[j]];
                id = a[j];
            }
        }
        int t = 1;
        for (int j = 0; j < k; j++)
        {
            int v = a[j];
            int u = id;
            if (In[v] <= In[u] && Out[u] <= Out[v])
            {
                continue;
            }
            v = p[v];
            if (In[v] <= In[u] && Out[u] <= Out[v])
            {
                continue;
            }
            t = 0;
        }
        if (!t)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
}