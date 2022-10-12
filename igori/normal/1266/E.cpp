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
int n, m;
int a[500000];
int summ = 0;
map<pair<int, int>, int > g;
set<int> asks[500000];

int cur = 0;
int out = 0;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], summ += a[i];
    cin >> m;
    while (m--)
    {
        int v, t, u;
        cin >> v >> t >> u;
        int pu = g[{v, t}];
        if (pu != 0)
        {
            a[pu]++;
            if (a[pu] > 0) summ++;
            if (asks[pu].size())
            {
                auto it = asks[pu].begin();
                if (*it == a[pu]) out--;
            }
            asks[v].erase(t);
            if (t > a[v]) cur--;
            g[{v, t}] = 0;
        }
        if (u != 0)
        {
            a[u]--;
            if (a[u] >= 0) summ--;
            asks[v].insert(t);
            if (asks[u].size())
            {
                auto itu = asks[u].begin();
                if (*itu == a[u] + 1)
                {
                    out++;
                }
            }
            auto itv = asks[v].begin();
            if (*itv == t && *itv > a[v])
                out++;
            g[{v, t}] = u;
        }
        cout << summ << "\n";
    }
}