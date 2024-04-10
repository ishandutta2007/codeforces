//Updated 29.09.18
//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("O2")
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
#define forn(i, n) for (int (i) = 0; (i) != (n); i+=1)
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
const int MAX = 100001;
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
    for (int i = 0; y < 1e18; i+=1)
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
    for (int i = 0; i < 10; i+=1)
    c[i] = 0;
    for (int i = 0; x > 0; i+=1)
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
//#define int long long
string s;
struct gs{
    char c1, c2, c3;
};
bool operator < (gs a1, gs a2)
{
    if (a1.c1 < a2.c1)
        return 1;
    if (a1.c1 == a2.c1 && a1.c2 < a2.c2)
        return 1;
    if (a1.c1 == a2.c1 && a1.c2 == a2.c2 && a1.c3 < a2.c3)
        return 1;
    return 0;
}
vector<gs> c;
vector<gs> c2;
map<gs, int> pos;

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    for (char c1 = 'a'; c1 <= 'z'; c1++)
    {
        for (char c2 = 'a'; c2 <= 'z'; c2++)
        {
            for (char c3 = 'a'; c3 <= 'z'; c3++)
            {
                c.push_back({c1, c2, c3});
                if (c.size() == s.size())
                    break;
            }
            if (c.size() == s.size())
                break;
        }
        if (c.size() == s.size())
            break;
    }
    vector<char> s1, s2, s3;
    string t1, t2, t3;
    for (int i = 0; i < s.size(); i++)
    {
        s1.push_back(c[i].c1);
        s2.push_back(c[i].c2);
        s3.push_back(c[i].c3);
    }
    cout << "? ";
    for (int i = 0; i < s.size(); i++)
    {
        cout << s1[i];
    }
    cout << endl;
    cin >> t1;
    cout << "? ";
    for (int i = 0; i < s.size(); i++)
    {
        cout << s2[i];
    }
    cout << endl;
    cin >> t2;
    cout << "? ";
    for (int i = 0; i < s.size(); i++)
    {
        cout << s3[i];
    }
    cout << endl;
    cin >> t3;
    for (int i = 0; i < s.size(); i++)
    {
        c2.push_back({t1[i], t2[i], t3[i]});
        pos[c2[i]] = i;
    }
    cout << "! ";
    for (int i = 0; i < s.size(); i++)
    {
        gs x = c[i];
        int p = pos[x];
        cout << s[p];
    }
    cout << endl;
}