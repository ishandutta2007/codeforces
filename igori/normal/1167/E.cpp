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
#define int long long
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
//______________________

ll n, x;
ll a[1500001];
ll leftpos[1500001];
ll rightpos[1500001];
ll ends_min_x[1500001];
ll begins_max_x[1500001];
ll ans;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i <= 1e6 + 1; i++)
    {
        leftpos[i] = 1e9;
    }
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        leftpos[a[i]] = min(leftpos[a[i]], i);
        rightpos[a[i]] = max(rightpos[a[i]], i);
    }
    ll p = -2;
    for (int j = 1; j <= x; j++)
    {
        ll segmS = leftpos[j];
        ll segmE = rightpos[j];
        //cout << j << ": " << leftpos[j] << " " << rightpos[j] << endl;
        if (leftpos[j] != 1e9)
        if (segmS <= p)
        {
            p = 1e9;
        }
        else
        {
            p = segmE;
        }
        ends_min_x[j] = p;
        //cout << ends_min_x[j] << " ";
    }
    //cout << endl;
    ll p2 = 1e9;
    for (int j = x; j >= 1; j--)
    {
        ll segmS = leftpos[j];
        ll segmE = rightpos[j];
        if (leftpos[j] != 1e9)
        if (segmE >= p2)
        {
            p2 = -2;
        }
        else
        {
            p2 = segmS;
        }
        begins_max_x[j] = p2;
    }
    for (int j = 1; j <= x; j++)
    {
        ;//cout << begins_max_x[j] << " ";
    }
    //cout << endl;
    ends_min_x[0] = -1;
    begins_max_x[x + 1] = 1e8;

    /*if (x <= 30000)
    {
        for (int l_minus = 0; l_minus < x; l_minus++)
        {
            for (int r_plus = 2; r_plus <= x + 1; r_plus++)
            {
                if (ends_min_x[l_minus] <= begins_max_x[r_plus] && l_minus + 1 <= r_plus - 1)
                {
                    ans++;
                }
            }
        }
        cout << ans;
        return 0;
    }*/

    ll r_plus = 0;

    for (int l_minus = 0; l_minus < x; l_minus++)
    {
            //cout << l_minus << " " << r_plus << endl;
            //if (begins_max_x[l_minus] == 1e9)
            //    break;
            r_plus = max(r_plus, l_minus + 2);
            while (!(ends_min_x[l_minus] < begins_max_x[r_plus]))
            {
                r_plus++;
                if (r_plus >= x + 2)
                {
                    cout << ans;
                    return 0;
                }
            }
            //cout << l_minus << " " << r_plus << endl;
            ans += x + 2 - r_plus;
    }
    cout << ans;
}