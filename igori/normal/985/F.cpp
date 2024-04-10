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
ll inq(ll k, ll q, ll mod)
{
    if (q == 0)
        return 1;
    ll l = inq(k, q / 2, mod);
    if (q % 2 == 0)
        return l * l % mod;
    else
        return (l * l) % mod * k % mod;
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
string s;
int n;
int m;
ll c[210000][27];
struct hasher{
    ll h1, h2;
};
const ll XA = 1000003;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 998244353;
hasher C[210000][27];
hasher S[26], F[26];

ll s1[210000];
ll s2[210000];

hasher solve(int i1, int i2, int j)
{
    hasher a = C[i1][j];
    hasher b = C[i2][j];
    hasher c;
    c.h1 = ((b.h1 - a.h1 * s1[i2 - i1]) % MOD1 + MOD1) % MOD1;
    c.h2 = ((b.h2 - a.h2 * s2[i2 - i1]) % MOD2 + MOD2) % MOD2;
    return c;
}

bool comp(hasher g, hasher h)
{
    if (g.h1 < h.h1)
        return 1;
    if (g.h1 == h.h1 && g.h2 < h.h2)
        return 1;
    return 0;
}

bool operator != (hasher g, hasher h)
{
    return (g.h1 != h.h1 || g.h2 != h.h2);
}

signed main()
{
    //freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    s1[0] = 1;
    s2[0] = 1;
    for (int i = 1; i <= 200000; i++)
    {
        s1[i] = (s1[i - 1] * XA) % MOD1;
        s2[i] = (s2[i - 1] * XA) % MOD2;
    }
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
    {
        c[i][s[i - 1] - 'a'] = 1;
        forn(j, 26)
        {
            C[i][j].h1 = (C[i - 1][j].h1 * XA + c[i][j]) % MOD1;
            C[i][j].h2 = (C[i - 1][j].h2 * XA + c[i][j]) % MOD2;
        }
    }
    forn(i, m)
    {
        ll x, y, l;
        cin >> x >> y >> l;
        ll l1, r1, l2, r2;
        l1 = x, l2 = y;
        r1 = x + l - 1;
        r2 = y + l - 1;
        l1--;
        l2--;
        forn(j, 26)
        {
            S[j] = solve(l1, r1, j);
            F[j] = solve(l2, r2, j);
        }
        sort(S, S + 26, comp);
        sort(F, F + 26, comp);
        int t = 1;
        forn(j, 26)
        {
            if (S[j] != F[j])
                t = 0;
        }
        if (t == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}