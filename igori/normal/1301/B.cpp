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
#define y1 y1337

const long long MOD = 998244353;

long long inq(long long x, long long y)
{
    if (y == 0) return 1;
    long long l = inq(x, y / 2);
    if (y % 2) return l * l % MOD * x % MOD;
    return l * l % MOD;
}

const long long INF = 1e14;

int n;
int a[500000];


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int ii = 0; ii < t; ii++)
    {
        cin >> n;
        F(i, n) cin >> a[i];
        vector<int> x;
        F(i, n) if (a[i] != -1 && ((i > 0 && a[i - 1] == -1) || (i + 1 < n && a[i + 1] == -1))) x.push_back(a[i]);
        if (x.size() == 0)
        {
            cout << 0 << " " << 1 << "\n";
            continue;
        }
        sort(all(x));
        int ans = 0;
        for (int j = 0; j + 1 < n; j++) if (a[j] != -1 && a[j + 1] != -1) ans = max(ans, abs(a[j] - a[j + 1]));
        int r = x.back() - x[0];
        int e = x[0] + r / 2;
        cout << max(ans, max(x.back() - e, e - x[0])) << " " << e << "\n";
    }
}