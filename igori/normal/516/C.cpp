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

const int N = 4e5;
const long long INF = N * N;

int n, m;
long long d[N], h[N];
long long dist_to[N], dist_from[N];
long long sp1[20][N];
long long sp2[20][N];
long long H[N];
long long res[20][N];

long long getsp1(int l, int r)
{
    int len = r - l + 1;
    int hh = H[len];
    return max(sp1[hh][l], sp1[hh][r - (1 << hh) + 1]);
}

long long getsp2(int l, int r)
{
    int len = r - l + 1;
    int hh = H[len];
    return max(sp2[hh][l], sp2[hh][r - (1 << hh) + 1]);
}

int cnt = 0;

long long get(int l, int r)
{
    if (l == r) return 0;
    if (l + 1 == r)
    {
        return 2 * h[l] + 2 * h[r] + d[l];
    }
    int hh = H[r - l + 1];
    int end = l + (1 << hh) - 1;
    if (end == r)
    {
        hh--;
        end = l + (1 << hh) - 1;
    }
    int m = end + 1;
    long long ans = max(res[hh][l], get(m, r));
    long long rp = getsp1(m, r) - dist_to[m];
    long long lp = getsp2(l, m - 1) - dist_from[m - 1];
    return max(ans, lp + rp + d[m - 1]);
}

signed main()
{
    H[1] = 0, H[2] = 0, H[3] = 1;
    for (int i = 4; i < N; i++)
    {
        H[i] = H[i - 1];
        if (((i - 1) & (i - 2)) == 0) H[i]++;
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> d[i];
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) d[i + n] = d[i];
    for (int i = 0; i < n; i++) h[i + n] = h[i];
    for (int i = 1; i < 2 * n; i++)
    {
        dist_to[i] = dist_to[i - 1] + d[i - 1];
    }
    for (int i = 2 * n - 2; i >= 0; i--)
    {
        dist_from[i] = dist_from[i + 1] + d[i];
    }
    for (int i = 0; i < 2 * n; i++)
    {
        sp1[0][i] = dist_to[i] + 2 * h[i];
        sp2[0][i] = dist_from[i] + 2 * h[i];
    }
    for (int j = 1; j < 20; j++)
    {
        for (int i = 0; i + (1 << j) - 1 < 2 * n; i++)
        {
            sp1[j][i] = getsp1(i, i + (1 << j) - 1);
            sp2[j][i] = getsp2(i, i + (1 << j) - 1);
        }
    }
    for (int j = 1; j < 20; j++)
    {
        for (int i = 0; i + (1 << j) - 1 < 2 * n; i++)
        {
            res[j][i] = get(i, i + (1 << j) - 1);
        }
    }
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (a <= b)
        {
            cout << get(b + 1, a + n - 1) << "\n";
        }
        else
        {
            cout << get(b + 1, a - 1) << "\n";
        }
    }
}