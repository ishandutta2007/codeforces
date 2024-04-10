#pragma GCC optimize("Ofast")
#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <math.h>
#include <string>
#include <set>
#include <iomanip>
#include <bitset>
#include <random>
#include <complex>
#include <random>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fdeg firdeg
#define snd second
#define ins insert
#define ld long double
#define mt make_tuple
#define fst first
const double PI = acos(-1);
// = 5e5 + 17;
ll MOD = 1e9 + 7;
const int INF = 1e9;
const int MaXN = 105;
const int N = 1e6 + 1000;
const int maxlog = 18;
ld ecr = 1e-8;
random_device rd;
mt19937 rnd(rd());
uniform_int_distribution<ll> nextRand(0,(ll)1e9);
template<class A, class B>
void sum(A &a, B b)
{
    a += b;
    if (a < 0LL) a += MOD;
    if (a >= MOD) a -= MOD;
}
ll add(ll a, ll b)
{
    a += b;
    if (a < 0) a += MOD;
    if (a >= MOD) a -= MOD;
    return a;
    
}
int to_i(char c)
{
    return c - 'a';
}
ll mult(ll a, ll b) {
    ll val = a * b - (ll) ((ld) a * b / MOD) * MOD;
    if (val < 0) {
        val += MOD;
    }
    if (val >= MOD) {
        val -= MOD;
    }
    return val;
}
ll gcd (ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
ll gcd_eu (ll a, ll b, ll & x, ll & y)
{
    if (a == 0)
    {
        x = 0LL; y = 1LL;
        return b;
    }
    ll x1, y1;
    ll d = gcd_eu (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
long long poww(long long a, long long b)
{
    long long val = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b % 2) val = mult(a, val);
        a = mult(a, a);
        b >>= 1;
    }
    return val % MOD;
}
ll inv(ll a)
{
    return poww(a , MOD - 2);
}

int a[12][2001];
// vector<int> cg[4100];
int g[4100];
// vector<pair<int, int>> order[2001];


int dp[13][4100], ndp[4100];

void upmax(int& x, int y) {
    if (y > x) x = y;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &a[i][j]);   
            }
        }
        for (int i = 0; i < (1 << n); i++) {
            ndp[i] = -INF;
            for (int j = 0; j <= n; j++) dp[j][i] = -INF;
            int mn = i;
            for (int j = 0; j < n; j++) {
                int rev = (i >> j) | ((i & ((1 << j) - 1)) << (n - j));
                if (rev < mn) {
                    mn = rev;
                }
            }
            g[i] = mn;
        }
        
        ndp[0] = 0;
        for (int j = 0; j < m; j++) {
            for (int j = 0; j <= n; j++) {
                for (int i = 0; i < (1 << n); i++) {
                    if (j == 0) {
                        dp[j][i] = ndp[i];
                    } else {
                        dp[j][i] = -INF;
                    }
                }
            }

            for (int pos = 0; pos < n; pos++) {
                for (int mask = 0; mask < (1 << n); mask++) {
                    upmax(dp[pos + 1][mask], dp[pos][mask]);
                    if ((mask & (1 << pos)) == 0) {
                        upmax(dp[pos + 1][mask | (1 << pos)], dp[pos][mask] + a[pos][j]);
                    }
                }
            }
            for (int i = 0; i < (1 << n); i++)
                ndp[i] = -INF;
            for (int i = 0; i < (1 << n); i++) {
                upmax(ndp[g[i]], dp[n][i]);
            }
            for (int i = 0; i < (1 << n); i++) {
                ndp[i] = ndp[g[i]];
            }
        }
        cout << ndp[(1 << n) - 1] << "\n";
    }
    return 0;
}