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

const int N = 51020;

int n;
vector<int> graph[N];
int v[N], u[N];

int d[N];
int interesting[N];
int par[N];

void dfs(int v, int p, int dep)
{
    d[v] = dep;
    par[v] = p;
    for (auto u : graph[v]) if (u != p) dfs(u, v, dep + 1);
}

void click(int v, int p)
{
    interesting[v] = 0;
    for (auto u : graph[v]) if (u != p) click(u, v);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> v[i] >> u[i];
        graph[v[i]].push_back(u[i]);
        graph[u[i]].push_back(v[i]);
    }
    fill(interesting, interesting + n + 1, 1);
    while (1)
    {
        for (int i = 1; i <= n; i++)
        {
            if (interesting[i])
            {
                int cnt = 0;
                for (auto u : graph[i]) if (interesting[u]) cnt++;
                if (cnt == 0)
                {
                    cout << "! " << i << endl;
                    return 0;
                }
                if (cnt != 1) continue;
                dfs(i, -1, 0);
                pair<int, int> s = {0, i};
                for (int u = 1; u <= n; u++)
                {
                    if (interesting[u] && d[u] > s.first)
                    {
                        s = {d[u], u};
                    }
                }
                if (i == s.second)
                {
                    cout << "! " << i << endl;
                    return 0;
                }
                cout << "? " << i << " " << s.second << endl;
                int x;
                cin >> x;
                if (x == i || x == s.second)
                {
                    cout << "! " << x << endl;
                    return 0;
                }
                int pap = par[x];
                dfs(s.second, -1, 0);
                int mam = par[x];
                click(mam, x);
                click(pap, x);
                break;
            }
        }
    }
}