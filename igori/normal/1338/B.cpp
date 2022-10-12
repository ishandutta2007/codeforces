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
int n;
vector<int> graph[N];
int val[N];

void dfs1(int v, int p)
{
    if (p != 0) val[v] = (val[p] ^ 1);
    for (auto u : graph[v]) if (u != p)
    {
        dfs1(u, v);
    }
}

vector<int> child[N];

void dfs2(int v, int p)
{
    for (auto u : graph[v]) if (u != p)
    {
        child[v].push_back(u);
        dfs2(u, v);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int root = 0;
    for (int i = 1; i <= n; i++)
    {
        if (graph[i].size() == 1)
        {
            root = i;
            break;
        }
    }
    dfs1(root, 0);
    int t = 1;
    for (int i = root + 1; i <= n; i++)
    {
        if (graph[i].size() == 1 && val[i] == 1)
        {
            t = 0;
        }
    }
    if (t)
    {
        cout << "1 ";
    }
    else
    {
        cout << "3 ";
    }
    dfs2(root, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int t = 0;
        for (auto u : child[i])
        {
            if (child[u].size() == 0)
            {
                if (t == 0) ans++;
                t = 1;
            }
            else
            {
                ans++;
            }
        }
    }
    int gift = child[root][0];
    for (auto u : child[gift])
    {
        if (child[u].size() == 0)
        {
            ans--;
            break;
        }
    }
    cout << ans;
}