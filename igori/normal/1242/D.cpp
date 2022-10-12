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
using std::min;

#define int long long

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

const int N = 500000;
const int M = 36;
const int MOD = 998244353;

ll Left(ll b, ll k)
{
    return (k * k + 1) * b + 1;
}

ll Right(ll b, ll k)
{
    return (k * k + 1) * b + k * k;
}

ll get(ll se, ll k)
{
    if (se == 0)
    {
        return k * (k + 1) / 2;
    }
    ll v = get(se / k, k);
    ll l = Left(se / k, k);
    ll rem = se % k;
    ll le = l + rem * k;
    if (v <= le)
    {
        le++;
    }
    ll ri = le + k - 1;
    ll summ = (le + ri) * (ri - le + 1) / 2;
    if (le <= v && v <= ri)
    {
        summ -= v;
        ri++;
        summ += ri;
    }
    return summ;
}

ll solve2(ll n, ll k)
{
    ll se = (n - 1) / (k * k + 1);
    ll v = get(se, k);
    ll cnt = n - 1 - se - (v < n);
    ll created = se * k + (n - Left(se, k) - (v < n)) / k;
    return cnt + created + 1;
}

ll solve1(ll n, ll k)
{
    ll se = (n - 1) / (k * k + 1);
    ll v = get(se / k, k);
    if (n == get(se, k))
    {
        ll nn = Left(se / k, k) + (se % k) * k;
        if (v <= nn) nn++;
        return solve2(nn, k) + k;
    }
    else
    {
        return solve2(n, k);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (0)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n + 1);

        for (int i = 1; i <= 100000; i++)
        {
            int val = solve1(i, k);
            if (val <= n) v[val] = i;
        }
        for (int i = 1; i <= n; i++) cout << v[i] << " ";

        return 0;
    }

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        cout << solve1(n, k) << "\n";
    }
}