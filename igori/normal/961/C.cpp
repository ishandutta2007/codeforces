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
#define pre pre1234
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld;
typedef pair<ll, ll> lpii;
const ll INF = 1e18 + 1;
const int MAX = 200001;
const ll MOD = 1000000007;
struct trio{
    int first;
    int second;
    int third;
};
struct long_trio{
    ll first;
    ll second;
    ll third;
};
double dist_point_line(int x1, int y1, int x2, int y2, int x3, int y3)
{
    double distance = abs((y3 - y1) * x2 - (x3 - x1) * y2 + x3 * y1 - x1 * y3) / (2 * sqrt(sqr(x3 - x1) + sqr(y3 - y1)));
    return distance;
}
double dist_point_point(int x1, int y1, int x2, int y2)
{
    double distance = sqrt(sqr(x1 - y1) + sqr(x2 - y2));
    return distance;
}
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
string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
ll fact[13] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362280, 3622800, 39916800, 479001600};
int cx[6] = {1, -1, 0, 0, 0, 0};
int cy[6] = {0, 0, 1, -1, 0, 0};
int cz[6] = {0, 0, 0, 0, 1, -1};
//___________BAZE_________________
ll n, m, k, ans = INF, l, r;
string s[5][300];
vi perm;
int used[50];

void check()
{
    string ss[300];
    for (int i = 0; i < n; i++)
    {
        ss[i] = s[perm[0]][i] + s[perm[1]][i];
        //cout << ss[i] << endl;
    }
    for (int i = 0; i < n; i++)
    {
        ss[i + n] = s[perm[2]][i] + s[perm[3]][i];
        //cout << ss[i + n] << endl;
    }
    int type1 = 0, type2 = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            if ((i + j) % 2 == 0 && ss[i][j] == '1')
            {
                type1++;
            }
            if ((i + j) % 2 == 1 && ss[i][j] == '0')
            {
                type1++;
            }
            if ((i + j) % 2 == 1 && ss[i][j] == '1')
            {
                type2++;
            }
            if ((i + j) % 2 == 0 && ss[i][j] == '0')
            {
                type2++;
            }
        }
    }
    ans = min(ans, min(type1, type2));
    //cout << endl;
    return;
}

void rec(int x)
{
    if (x == 0)
    {
        check();
        return;
    }
    for (int i = 1; i <= 4; i++)
    {
        if (used[i] == 0)
        {
            used[i] = 1;
            perm.pb(i);
            rec(x - 1);
            perm.pop_back();
            used[i] = 0;
        }
    }
    return;
}

int main()
{
    cin >> n;
    forn(i, n)
    cin >> s[1][i];
    forn(i, n)
    cin >> s[2][i];
    forn(i, n)
    cin >> s[3][i];
    forn(i, n)
    cin >> s[4][i];
    rec(4);
    cout << ans;
}