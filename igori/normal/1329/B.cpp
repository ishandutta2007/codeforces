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

const ll N = 501000;
const ll INF = (1LL << 40);

void solve()
{
    ll n, m;
    cin >> n >> m;
    map<ll, ll> ans;
    ans[1] = 1;
    if (n == 1)
    {
        cout << 1 % m << "\n";
        return;
    }
    for (ll x = 2; x < INF; x *= 2)
    {
        ans[x] = (ans[x - 1] * 2 + 1) % m;
        ll delta = (ans[x] - ans[x - 1] + m) % m;
        ans[2 * x - 1] = (ans[x] + (x - 1) % m * delta) % m;
        if (x <= n && n <= 2 * x - 1)
        {
            cout << (ans[x] + (n - x) * delta) % m << "\n";
            return;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}