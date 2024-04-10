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

#define int long long
typedef long long ll;

namespace MySpace{

};

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()

const ll N = 5 * 1501000;
const ll INF = (1LL << 40);

vector<int> ans;
int h, g;
int a[N];
int depth[N];

void d(int v, int dist)
{
    depth[v] = dist;
    int x = 2 * v, y = 2 * v + 1;
    if (x < N)
        d(x, dist + 1);
    if (y < N)
        d(y, dist + 1);
}

void solve(int v)
{
    if (a[v] == 0) return;
    while (1)
    {
        int id = v;
        int take_from = depth[id];
        while (1)
        {
            if (a[2 * id] == 0 && a[2 * id + 1] == 0)
            {
                take_from = depth[id];
                break;
            }
            if (a[2 * id] > a[2 * id + 1])
            {
                id = 2 * id;
            }
            else
            {
                id = 2 * id + 1;
            }
        }
        if (take_from >= g)
        {
            ans.push_back(v);
            int id = v;
            while (1)
            {
                if (a[2 * id] == 0 && a[2 * id + 1] == 0)
                {
                    a[id] = 0;
                    break;
                }
                if (a[2 * id] > a[2 * id + 1])
                {
                    a[id] = a[2 * id];
                    id = 2 * id;
                }
                else
                {
                    a[id] = a[2 * id + 1];
                    id = 2 * id + 1;
                }
            }
        }
        else
        {
            break;
        }
    }
    solve(2 * v);
    solve(2 * v + 1);
}

void solve()
{
    cin >> h >> g;
    for (int i = 1; i < (1 << h); i++) cin >> a[i];
    ans.clear();
    solve(1);
    long long si = 0;
    for (int i = 1; i < (1 << g); i++) si += a[i];
    cout << si << "\n";
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << "\n";
    for (int i = 0; i < (1 << h); i++) a[i] = 0;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    d(1, 0);
    while(t--)
    {
        solve();
    }
}