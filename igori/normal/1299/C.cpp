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

const int MOD = 1e9 + 7;

long long inq(long long a, long long b)
{
    if (b == 0) return 1;
    long long l = inq(a, b / 2);
    if (b % 2) return l * l % MOD * a % MOD;
    return l * l % MOD;
}

int n;
long long a[1500000];
long long p[1500000];

double before[1500000];
double after[1500000];
int active[1500000];
double res[1500000];
double ans[1500000];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    p[0] = a[0];
    for (int i = 1; i < n; i++) p[i] = p[i - 1] + a[i];
    for (int i = 0; i < n; i++) before[i] = i - 1, after[i] = i + 1, active[i] = 1, res[i] = a[i];
    set<pair<double, int> > ss;
    for (int i = 0; i < n; i++) ss.insert({a[i], i});
    while (ss.size())
    {
        pair<double, int> kek = *ss.begin();
        ss.erase(kek);
        int we = kek.second;
        if (active[we] == 0) continue;
        int b = before[we];
        if (b == -1 || res[b] < res[we]) continue;
        int bb = before[b];
        double nw = (res[we] * (we - b) + res[b] * (b - bb)) / (we - bb);
        res[we] = nw;
        after[bb] = we;
        before[we] = bb;
        ss.insert({nw, we});
        active[b] = 0;
    }
    double x = res[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        if (active[i]) x = res[i];
        res[i] = x;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%.9f\n", res[i]);
    }
}