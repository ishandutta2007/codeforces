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

const int N = 251020;
const int MOD = 1e9 + 7;
int n;
long long a[N];
int ans = 1e18;

void check(int x)
{
    vector<int> dv;
    for (int i = 2; i * i <= x; i++)
    {
        while (x % i == 0) dv.push_back(i), x /= i;
    }
    if (x > 1) dv.push_back(x);
    int res = 0;
    for (auto k : dv)
    {
        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            int x = a[i] % k;
            if (a[i] > x)
            {
                res += min(k - x, x);
            }
            else
            {
                res += k - x;
            }
            if (res > ans) break;
        }
        ans = min(ans, res);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int ch = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i) ch = (ch * MOD - a[i] ^ a[i - 1]) % MOD;
    }
    srand(time(NULL) + ch);
    std::random_shuffle(a, a + n);
    std::random_shuffle(a + max(0, n - 60000), a + n);
    std::random_shuffle(a, a + n);
    std::random_shuffle(a + max(0, n - 60000), a + n);
    std::random_shuffle(a, a + n);
    for (int i = 0; i < 50; i++)
    {
        if (a[i] - 1) check(a[i] - 1);
        check(a[i]);
        check(a[i] + 1);
    }
    cout << ans;
}