// Code it, hate me?
// .................
// WA 138 or TL 109?
// Hope, Accepted...

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
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
#define pre pre1234
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld;
typedef pair<ll, ll> lpii;
const ll INF = 1e18 + 1;
const int MAX = 200001;
const ll MOD = 1000000007;
ll inq(ll k, ll q)
{
    if (q == 0)
        return 1;
    ll l = inq(k, q / 2);
    if (q % 2 == 0)
        return l * l % MOD;
    else
        return l * l * k % MOD;
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
ll dsumm(ll x)
{
    ll y = 1;
    ll z = 0;
    for (int i = 0; i < 18; i++)
    {
        z += x / y % 10;
        y *= 10;
    }
    return z;
}
ll dsumm2(ll x)
{
    ll y = 1;
    ll z = 0;
    for (int i = 0; i < 64; i++)
    {
        z += x / y % 2;
        y *= 2;
    }
    return z;
}
string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//______________________
ll a, b, c, d;
ll n, m;
char ans[50][50];
int main()
{
    n = 48;
    cin >> a >> b >> c >> d;
    forn(i, n)
    {
        forn(j, n)
        {
            ans[i][j] = 'A';
        }
    }
    a--;
    if (a != 0)
        b--;
    for (int i = 0; i < n; i += 4)
    {
        for (int j = 0; j < n; j += 4)
        {
            if (a > 0)
            {
                ans[i + 3][j + 3] = 'B';
                ans[i + 2][j + 3] = 'B';
                ans[i + 1][j + 3] = 'B';
                ans[i + 0][j + 3] = 'B';
                ans[i + 3][j + 2] = 'B';
                ans[i + 3][j + 1] = 'B';
                ans[i + 3][j + 0] = 'B';
                a--;
            }
        }
    }
    for (int i = 1; i < n; i += 4)
    {
        for (int j = 1; j < n; j += 4)
        {
            if (b > 0)
            {
                ans[i][j] = 'B';
                b--;
            }
        }
    }
    for (int i = 1; i < n; i += 4)
    {
        for (int j = 0; j < n; j += 4)
        {
            if (c > 0)
            {
                ans[i][j] = 'C';
                c--;
            }
        }
    }
    for (int i = 0; i < n; i += 4)
    {
        for (int j = 0; j < n; j += 4)
        {
            if (d > 0)
            {
                ans[i][j] = 'D';
                d--;
            }
        }
    }
    cout << 48 << " " << 48 << endl;
    forn(i, n)
    {
        forn(j, n)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
}