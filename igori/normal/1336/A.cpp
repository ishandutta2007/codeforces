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

const int N = 501000;

int n, k;
vector<int> graph[N];

int sz[N];
int par[N];
int suns[N];
int dist[N];

long long ans = 0;

void dfs(int v, int p, int depth)
{
    sz[v] = 1;
    par[v] = p;
    dist[v] = depth;
    for (auto u : graph[v]) if (u != p)
    {
        dfs(u, v, depth + 1);
        sz[v] += sz[u];
        suns[v]++;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0, 0);
    long long res = 0;
    set<pair<int, int> > q;
    for (int i = 1; i <= n; i++)
    {
        if (suns[i] == 0)
        {
            q.insert({dist[i] - sz[i] + 1, i});
        }
    }
    while (k-- && q.size())
    {
        auto it = q.end();
        it--;
        pair<int, int> v = *it;
        q.erase(it);
        ans += v.first;
        int U = par[v.second];
        suns[par[v.second]]--;
        if (suns[par[v.second]] == 0)
        {
            q.insert({dist[U] - sz[U] + 1, U});
        }
    }
    cout << ans;
}