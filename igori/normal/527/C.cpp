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
#include <stdio.h>
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
//______________________
ll k, w, h;
ll ansh, answ;
vector<pair<char, int>> q;
ll h1[500000], w1[500000];
vector<int> s1, s2;
ll root1[500000], root2[500000];
ll h1_[500000], h2[500000];
ll sz1[500000], sz2[500000];

int Root1(int x)
{
    if (root1[x] == x)
    {
        re x;
    }
    re (root1[x] = Root1(root1[x]));
}

int Root2(int x)
{
    if (root2[x] == x)
    {
        re x;
    }
    re (root2[x] = Root2(root2[x]));
}

void Merge1(int x, int y)
{
    x = Root1(x);
    y = Root1(y);
    if (x == y)
    re;
    if (h1_[x] == h1_[y])
    {
        h1_[x]++;
    }
    if (h1_[x] < h1_[y])
    {
        root1[x] = y;
        sz1[y] += sz1[x];
        ansh = max(sz1[y], ansh);
    }
    else
    {
        root1[y] = x;
        sz1[x] += sz1[y];
        ansh = max(sz1[x], ansh);
    }
}

void Merge2(int x, int y)
{
    x = Root2(x);
    y = Root2(y);
    if (x == y)
    re;
    if (h2[x] == h2[y])
    {
        h2[x]++;
    }
    if (h2[x] < h2[y])
    {
        root2[x] = y;
        sz2[y] += sz2[x];
        answ = max(sz2[y], answ);
    }
    else
    {
        root2[y] = x;
        sz2[x] += sz2[y];
        answ = max(sz2[x], answ);
    }
}

int main()
{
    cin >> h >> w >> k;
    for (int i = 0; i < k; i++)
    {
        char c;
        int x;
        cin >> c >> x;
        q.pb({c, x});
        if (c == 'H')
        {
            w1[x] = 1;
        }
        else
        {
            h1[x] = 1;
        }
    }
    int now = 1;
    int cnt = 1;
    answ = 1;
    ansh = 1;
    for (int i = 1; i < h; i++)
    {
        //cout << h1[i] << " ";
        if (h1[i] == 1)
        {
            h1[i] = cnt;
            ansh = max(ansh, now);
            s1.pb(now);
            now = 0;
            cnt++;
        }
        else
        {
            h1[i] = cnt;
        }
        now++;
    }
    s1.pb(now);
    h1[h] = cnt;
    ansh = max(ansh, now);
    now = 1;
    cnt = 1;
    for (int i = 1; i < w; i++)
    {
        if (w1[i] == 1)
        {
            w1[i] = cnt;
            answ = max(answ, now);
            s2.pb(now);
            cnt++;
            now = 0;
        }
        else
        {
            w1[i] = cnt;
        }
        now++;
    }
    s2.pb(now);
    w1[w] = cnt;
    answ = max(answ, now);
    for (int i = 1; i <= s1.sz; i++)
    {
        sz1[i] = s1[i - 1];
    }
    for (int i = 1; i <= s2.sz; i++)
    {
        sz2[i] = s2[i - 1];
    }
    forn(i, 500000)
    {
        root1[i] = i;
        root2[i] = i;
    }
    vector<ll> ans;
    ans.pb(answ * ansh);
    for (int i = k - 1; i >= 0; i--)
    {
        char c = q[i].fi;
        int x = q[i].se;
        if (c == 'H')
        {
            //cout << "mV : " << w1[x] << " " << w1[x + 1] << endl;
            Merge2(w1[x], w1[x + 1]);
        }
        else
        {
            //cout << "mH : " << h1[x] << " " << h1[x + 1] << endl;
            Merge1(h1[x], h1[x + 1]);
        }
        if (i > 0)
        ans.pb(answ * ansh);
    }
    reverse(all(ans));
    for (int i = 0; i < ans.sz; i++)
    {
        printf("%I64d\n", ans[i]);
    }
}