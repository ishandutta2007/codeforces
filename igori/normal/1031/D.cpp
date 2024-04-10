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
const int INF = 1e9;
const ll INFLL = 1e18 + 1;
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
        return (l * l) % MOD * k % MOD;
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
    if (x == 0)
        return 0;
    return lg10(x / 10) + 1;
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

#define cnks(l) for (int i = 0; i < l; i++) cnk[i][0] = 1; for (int i = 0; i < l; i++) cnk[0][i] = 1; for (int i = 0; i < l; i++) for (int j = 1; j < i; j++) cnk[i][j] = cnk[i - 1][j] + cnk[i - 1][j - 1];
#define facts(l) fact[0] = 1; for (int i = 1; i < l; i++) fact[i] = fact[i - 1] * i;
#define stirling_2s(l) stirling_2[0][0] = 1; for (int i = 1; i < l; i++) stirling_2[i][0] = 0; for (int i = 0; i < l; i++) for (int j = 1; j <= i; j++) stirling_2[i][j] = stirling_2[i - 1][j - 1] + j * stirling_2[i - 1][j];

//string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
//int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//vi cx, cy;
//______________________
ll n, k;
char c[3000][3000];
ll dp[3000][3000];
ll used[3000][3000];

bool ok(int i, int j)
{
    re (0 <= i && i < n && 0 <= j && j < n);
}

vector<char> ans;

signed main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ll a = 9999, b = 9999;
            if (ok(i - 1, j))
                a = dp[i - 1][j];
            if (ok(i, j - 1))
                b = dp[i][j - 1];
            dp[i][j] = min(a, b) + (c[i][j] != 'a');
            dp[0][0] = (c[0][0] != 'a');
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    ll mmax = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (dp[i][j] <= k)
            {
                mmax = max(mmax, i + j + 1);
            }
        }
    }
    //cout << mmax << endl;
    for (int i = 0; i < mmax; i++)
        ans.pb('a');
    vector<pair<pii, int>> qq;
    if (ans.sz == 0)
    {
        ans.pb(c[0][0]);
        qq.pb({{0, 0}, 0});
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j + 1 == mmax && dp[i][j] <= k)
            {
                //cout << i << " " << j << endl;
                qq.pb({{i, j}, 0});
            }
        }
    }
    for (int i2 = 0; i2 < qq.size(); i2++)
    {
        ll d = qq[i2].second;
        char charmin = 'z';
        int j2 = i2;
        for (j2 = i2; j2 < qq.size(); j2++)
        {
            if (qq[j2].second != d)
            {
                j2--;
                break;
            }
            ll i = qq[j2].fi.fi;
            ll j = qq[j2].fi.se;
            if (ok(i, j + 1))
            {
                //used[i][j + 1] = 1;
                //qq.pb({{i, j + 1}, d + 1});
                charmin = min(charmin, c[i][j + 1]);
            }
            if (ok(i + 1, j))
            {
                //used[i + 1][j] = 1;
                //qq.pb({{i + 1, j}, d + 1});
                charmin = min(charmin, c[i + 1][j]);
            }
        }
        for (j2 = i2; j2 < qq.size(); j2++)
        {
            if (qq[j2].second != d)
            {
                j2--;
                break;
            }
            ll i = qq[j2].fi.fi;
            ll j = qq[j2].fi.se;
            if (ok(i, j + 1) && !used[i][j + 1] && c[i][j + 1] == charmin)
            {
                used[i][j + 1] = 1;
                qq.pb({{i, j + 1}, d + 1});
                charmin = min(charmin, c[i][j + 1]);
            }
            if (ok(i + 1, j) && !used[i + 1][j] && c[i + 1][j] == charmin)
            {
                used[i + 1][j] = 1;
                qq.pb({{i + 1, j}, d + 1});
                charmin = min(charmin, c[i + 1][j]);
            }
        }
        if (ans.sz < 2 * n - 1)
            ans.pb(charmin);
        i2 = j2;
    }
    cout << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i];
}