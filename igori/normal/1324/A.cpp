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

long long min(long long a, long long b) {return a < b ? a : b;}
long long min(int a, long long b) {return a < b ? a : b;}
long long min(long long a, int b) {return a < b ? a : b;}
long long min(int a, int b) {return a < b ? a : b;}

long long max(long long a, long long b) {return a > b ? a : b;}
long long max(int a, long long b) {return a > b ? a : b;}
long long max(long long a, int b) {return a > b ? a : b;}
long long max(int a, int b) {return a > b ? a : b;}

#define int long long

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()

const int N = 500000;
const int MOD = 1e9 + 7;
const double eps = 1e-8;

int n;
int a[N], cnt[N];

void solve()
{
    cin >> n;
    cnt[0] = 0, cnt[1] = 0;
    for (int i = 0; i < n; i++) cin >> a[i], cnt[a[i] % 2]++;
    if (cnt[0] == n || cnt[1] == n) cout << "YES\n";
    else cout << "NO\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}