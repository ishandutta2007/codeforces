//Updated 29.09.18
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <bitset>
using namespace std;
#define sqr(z) (z) * (z)
#define ch_NO(x) cout << "NO\n"; x = 1 - x;
#define b_NO cout << "NO\n"; break;
#define r_NO cout << "NO\n"; return 0;
#define c_NO cout << "NO\n"; continue;
#define ch_YES(x) cout << "YES\n"; x = 1 - x;
#define b_YES cout << "YES\n"; break;
#define r_YES cout << "YES\n"; return 0;
#define c_YES cout << "YES\n"; continue;
#define sz size()
#define pb push_back
#define int_ "%d",
#define fi first
#define se second
#define mm(k) memset((k), -1, sizeof(k));
#define all(k) (k).begin(), (k).end()
#define forn(i, n) for (int (i) = 0; (i) != (n); i++)
#define nfor(i, n) for (int (i) = (n) - 1; (i) != -1; i--)
#define do_nothing cout << " Work_Error ";
#define erace erase
#define incert insert
#define reverce reverse
#define re return
#define prev prev1234
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld;
typedef pair<ll, ll> lpii;
typedef unsigned long long ull;
const int INF = 1e9;
const ll INFLL = 1e18 + 1;
const int MAX = 200001;
const ll MOD = 1000000007;
const int SZ = 300100;
const double PI = 3.14159265358979323846264338327;
ll inq(ll k, ll q, ll mod)
{
    if (q == 0)
        return 1;
    ll l = inq(k, q / 2, mod);
    if (q % 2 == 0)
        return l * l % mod;
    else
        return l * l % mod * k % mod;
}
ll gcd(ll a, ll b)
{
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll cubr(ll a)
{
    ll l = -1, r = 1e6 + 2;
    while (l < r - 1)
    {
        ll mid = (l + r) / 2;
        if (mid * mid * mid > a)
            r = mid;
        else
            l = mid;
    }
    return l;
}
ll max(ll a, ll b)
{
    if (a > b)
        return a;
    return b;
}
ll min(ll a, ll b)
{
    return -1 * max(-a, -b);
}
ll possible(ll q)
{
    if (q == INF)
        return -1;
    return q;
}
bool correct(int x, int xx)
{
    if (x < 0)
        return 0;
    if (x >= xx)
        return 0;
    return 1;
}
ll dsumm(ll x, ll k)
{
    ll y = 1;
    ll z = 0;
    for (int i = 0; y < 1e18; i++)
    {
        z += x / y % k;
        y *= k;
    }
    return z;
}
ll dcount(ll x)
{
    ll y = 1;
    ll z = 0;
    int c[100];
    for (int i = 0; i < 10; i++)
    c[i] = 0;
    for (int i = 0; x > 0; i++)
    {
        if (c[x / y % 10] == 0)
        z++;
        c[x / y % 10] = 1;
        x /= 10;
    }
    return z;
}
ll lg10(ll x)
{
    if (10000 <= x && x < 100000)
        re 5;
    if (x == 0)
        return 0;
    return lg10(x / 10) + 1;
}
ll g(ll x, ll mod)
{
    if (x == 0)
        re 0;
    return x / mod + g(x / mod, mod);
}
bool is_digit(char c)
{
    re ('0' <= c && c <= '9');
}

#define bitcount __builtin_popcount
#define bitcountl __builtin_popcountll

#define RA(n, arr) cin >> n; forn(i, n) cin >> (arr)[i];
#define WA(n, arr) cout << n << "\n"; forn(i, n) cout << (arr)[i] << " ";
#define WWA(n, arr) forn(i, n) cout << (arr)[i] << " ";
#define RSA(n, arr) cin >> n; forn(i, n) cin >> (arr)[i]; sort(arr, arr + n);
#define WSA(n, arr) cout << n << "\n"; sort(arr, arr + n); forn(i, n) cout << (arr)[i] << " ";
#define WWSA(n, arr) sort(arr, arr + n); forn(i, n) cout << (arr)[i] << " ";
#define WSV(vec) cout << vec.size() << "\n"; sort(all(vec)); forn(i, vec.sz) cout << (vec)[i] << " ";
#define WWSV(vec) sort(all(vec)); forn(i, vec.sz) cout << (vec)[i] << " ";
//string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
//int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//vi cx, cy;
//______________________
ll n;
ll a[101];
ll ans = 1;
bitset<10001> dp[102][101];
ll cnt[101];
ll b[101];

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int C = 0;
    for (int w = 1; w <= 100; w++)
    if (cnt[w])
        C++;
    if (C == 1 || C == 2)
    {
        cout << n;
        return 0;
    }
    for (int w = 1; w <= 100; w++)
    {
        if (cnt[w] <= ans)
            continue;
        vector<int> pos[101];
        int t = 1;
        for (int i = 1; i <= n; i++)
        {
            b[i] = a[i];
            if (a[i] == w)
            {
                b[i] = -1;
            }
        }
        for (int i = 0; i <= n; i++)
        {
            for (int cou = 0; cou <= i; cou++)
            {
                for (int j = 0; j <= 10000; j++)
                {
                    dp[i][cou][j] = 0;
                }
            }
        }
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int cou = 0; cou <= i; cou++)
            {
                for (int j = 0; j <= 10000; j++)
                {
                    if (dp[i - 1][cou][j])
                    {
                        dp[i][cou][j] = 1;
                        if (b[i] != -1)
                            dp[i][cou + 1][j + b[i]] = 1;
                    }
                }
            }
        }
        for (int c = 1; c <= n; c++)
        {
            for (int j = 0; j <= 10000; j++)
            {
                if (dp[n][c][j])
                {
                    pos[c].pb(j);
                }
            }
        }
        for (int c = 1; c <= cnt[w]; c++)
        {
            int t = 1;
            for (int use = 0; use <= c; use++)
            {
                int add = use * w;
                for (int j = 0; j < pos[c - use].sz; j++)
                {
                    if (add + pos[c - use][j] == c * w)
                        t = 0;
                }
            }
            if (t == 1)
                ans = max(ans, c);
        }
    }
    cout << ans;
}