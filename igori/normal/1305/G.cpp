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

const int N = 550129;

int n, a, cnt[N];
long long ans, si;

vector<pair<int, int> > g[N];

int d[N];

int Root(int x)
{
    if (d[x] < 0) return x;
    return d[x] = Root(d[x]);
}

void Merge(int v, int u)
{
    int x = Root(v), y = Root(u);
    //while (d[x] >= 0) x = d[x];
    //while (d[y] >= 0) y = d[y];
    if (x == y) return;
    if (d[x] < d[y]) swap(x, y), swap(v, u);
    ans = ans + 1LL * (v + u) * ((d[u] == -1 ? cnt[u] : 1) + (d[v] == -1 ? cnt[v] : 1) - 1);
    d[y] += d[x];
    d[x] = y;
    int sv = 0;
    //while (d[v] >= 0) sv = d[v], d[v] = y, v = sv;
    //while (d[u] >= 0) sv = d[u], d[u] = y, u = sv;
    return;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < N; i++) d[i] = -1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        cnt[a]++;
        si += a;
    }
    cnt[0]++;
    for (int upmask = (1 << 18); upmask >= 0; upmask--)
    {
        for (int mask = upmask; ; mask = (mask - 1) & upmask)
        {
            int x = upmask - mask;
            if (cnt[mask] && cnt[x]) Merge(mask, x);
            if (mask == 0) break;
        }
    }
    cout << ans - si;
}