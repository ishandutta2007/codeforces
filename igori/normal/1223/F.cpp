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

using std::min;
using std::max;

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

inline int nextInt()
{
    int x = 0;
    char c = getchar();
    int mi = (c == '-');
    if (c == '-') c = getchar();
    while ('0' <= c && c <= '9')
    {
        x = 10 * x + c - '0';
        c = getchar();
    }
    if (mi) return x * -1;
    return x;
}

const long long MOD = 1000009081;
const long long MOD2 = 1e9 + 7;
const ll M = 1e6 + 3;
ll ANTIM, ANTIM2;

ll inq(ll a, ll x, ll mod)
{
    if (x == 0) return 1;
    ll l = inq(a, x / 2, mod);
    if (x % 2) return l * l % mod * a % mod;
    return l * l % mod;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    F(i, n) cin >> a[i];
    map<pair<ll, ll>, ll> mm;
    vector<int> b;
    ll r = 0, r2 = 0;
    for (int i = 0; i < n; i++)
    {
        mm[{r, r2}]++;
        //cout << r << endl;
        if (b.size() && b[b.size() - 1] == a[i])
        {
            r = (r - a[i] + MOD) % MOD;
            r = r * ANTIM % MOD;
            r2 = (r2 - a[i] + MOD2) % MOD2;
            r2 = r2 * ANTIM2 % MOD2;
            b.pop_back();
        }
        else
        {
            b.push_back(a[i]);
            r = (r * M + a[i]) % MOD;
            r2 = (r2 * M + a[i]) % MOD2;
        }
    }
    mm[{r, r2}]++;
    //cout << r << endl;
    ll ans = 0;
    for (auto it : mm)
    {
        ans = ans + it.second * (it.second - 1) / 2;
    }
    cout << ans << "\n";
}

signed main()
{
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    ANTIM = inq(M, MOD - 2, MOD);
    ANTIM2 = inq(M, MOD2 - 2, MOD2);
    while (q--)
    {
        solve();
    }
}