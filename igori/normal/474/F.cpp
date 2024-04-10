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

#define double long double
#define y0 abra

const int N = 1e5 + 22;
const int INF = 1e9 + 1;

int n;
int t;
int a[N];
int mn[4 * N], gcd[4 * N], cntmn[4 * N];

void build(int l, int r, int v)
{
    if (l + 1 == r)
    {
        mn[v] = a[l];
        gcd[v] = a[l];
        cntmn[v] = 1;
        return;
    }
    int m = (l + r) / 2;
    build(l, m, 2 * v + 1);
    build(m, r, 2 * v + 2);
    gcd[v] = std::__gcd(gcd[2 * v + 1], gcd[2 * v + 2]);
    mn[v] = min(mn[2 * v + 1], mn[2 * v + 2]);
    if (mn[2 * v + 1] == mn[v]) cntmn[v] += cntmn[2 * v + 1];
    if (mn[2 * v + 2] == mn[v]) cntmn[v] += cntmn[2 * v + 2];
}

pair<int, pair<int, int> > get(int l, int r, int L = 0, int R = n, int V = 0)
{
    if (r <= L || R <= l)
    {
        return {0, {INF, 0}};
    }
    if (l <= L && R <= r)
    {
        return {gcd[V], {mn[V], cntmn[V]}};
    }
    int M = (L + R) / 2;
    pair<int, pair<int, int> > f1 = get(l, r, L, M, 2 * V + 1);
    pair<int, pair<int, int> > f2 = get(l, r, M, R, 2 * V + 2);
    f1.first = std::__gcd(f1.first, f2.first);
    int kek = min(f1.se.fi, f2.se.fi);
    if (kek != f1.se.fi) f1.se.se = 0;
    if (kek == f2.se.fi) f1.se.se += f2.se.se;
    f1.se.fi = kek;
    return f1;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    build(0, n, 0);
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        pair<int, pair<int, int> > res = get(l, r);
        if (res.fi != res.se.fi)
        {
            cout << r - l << "\n";
        }
        else
        {
            cout << r - l - res.se.se << "\n";
        }
    }
}