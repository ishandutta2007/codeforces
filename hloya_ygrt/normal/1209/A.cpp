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

map<vector<int>, ll> dp[N];

int brute(int l, int n)
{
    dp[0][vector<int>()] = 1;
    for (int i = 0; i < n; i++)
    {
        for (auto [e, val] : dp[i])
        {
            auto to = e;
            for (int j = 0; j < 4; j++)
            {
                to.pb(j);
                
                if (to.size() >= l)
                {
                    bool mda = true;
                    for (int j = (int)to.size() - 1; j >= (int)to.size() - l; j--)
                    {
                        if (to[j] != to.back())
                            mda = false;
                    }
                    if (mda)
                    {
                        auto toto = to;
                        for (int j = 0; j < l; j++)
                            toto.pop_back();
                        dp[i + 1][toto] += val;
                    }
                    else
                    {
                        dp[i + 1][to] += val;
                    }
                } else
                {
                    dp[i + 1][to] += val;
                }
                to.pop_back();
            }
        }
    }
    return dp[n][vector<int>()];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    
    int n;
    cin >> n;

    vector<int> a(n), used(n, 0);
    for (int i = 0; i < a.size(); i++) {
        cin >> a[i];
    }

    int ans = 0;
    while (true) {
        int mn = -1;
        for (int i = 0; i < n; i++) {
            if (!used[i] && (mn == - 1 || a[i] < a[mn])) {
                mn = i;
            }
        }
        if (mn == -1) break;
        ans++;
        for (int i = 0; i < n; i++)
            if (a[i] % a[mn] == 0)
                used[i] = 1;
    }
    cout << ans;
    return 0;
}