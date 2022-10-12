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
using std::min;
using std::max;
using std::fill;

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
#define int long long

const long long inf = 1e18;
const long long infsmart = 1e12;

void Set(int l, int r, int L, int R, int V, int val)
{
    if (l <= L && R <= r)
    {
        //Tree[V] = max(val, Tree[V]);
        return;
    }
    if (r <= L || R <= l)
        return;
}

long long Get(int l, int r, int L, int R, int V)
{
    if (l <= L && R <= r)
    {
        //return Tree[V];
    }
    if (r <= L || R <= l)
    {
        return 0;
    }
}

const long long MOD = 1e9 + 7;

long long a, b, p, x, ans;

long long inq(long long x, long long y)
{
    if (y == 0) return 1;
    ll l = inq(x, y / 2);
    if (y % 2) return l * l % p * x % p;
    return l * l % p;
}

long long compared(long long r1, long long m1, long long r2, long long m2)
{
    // a = x * m1 + r1 = y * m2 + r2
    // y * m2 - x * m1 = r1 - r2
    long long y = 1;
    long long x = 1;
    y *= r1 - r2;
    x *= r1 - r2;
    long long a = x * m1 + r1;
    a = (a + 4 * m1 * m2) % (m1 * m2);
    return a;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> p >> x;
    long long A = 1;
    for (ll d = 0; d < p - 1; d++)
    {
        long long r = inq(A, p - 2) * b % p;
        r = compared(d, p - 1, r, p);
        ll m = p * (p - 1);
        long long blocks = x / m;
        ans += blocks;
        if (x % m >= r) ans++;
        A = A * a % p;
    }
    cout << ans;
}