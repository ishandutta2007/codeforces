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

string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vi cx, cy;
//______________________
ll n, m;
ll x[50];
ll y[50];
ll x2[50];
ll y2[50];
ll a[52][52];
ll b[52][52];
vector<pair<pii, pii>> ans1, ans2, ans3;

void Move_left_p1(int num)
{
    int i = 0;
    int j = 0;
    for (int i1 = 1; i1 <= n; i1++)
    {
        for (int j1 = 1; j1 <= n; j1++)
        {
            if (a[i1][j1] == num)
            {
                i = i1;
                j = j1;
                break;
            }
        }
    }
    while (j > 1)
    {
        if (a[i][j - 1] == 0)
        {
            ans1.pb({{i, j}, {i, j - 1}});
            j--;
            a[i][j] = num;
            a[i][j + 1] = 0;
        }
        else
            break;
    }
}

void Move_right_p1(int num)
{
    int i = 0;
    int j = 0;
    for (int i1 = 1; i1 <= n; i1++)
    {
        for (int j1 = 1; j1 <= n; j1++)
        {
            if (a[i1][j1] == num)
            {
                i = i1;
                j = j1;
                break;
            }
        }
    }
    while (j < n)
    {
        if (a[i][j + 1] == 0)
        {
            ans1.pb({{i, j}, {i, j + 1}});
            j++;
            a[i][j] = num;
            a[i][j - 1] = 0;
        }
        else
            break;
    }
}

void Move_up_p1(int num)
{
    int i = 0;
    int j = 0;
    for (int i1 = 1; i1 <= n; i1++)
    {
        for (int j1 = 1; j1 <= n; j1++)
        {
            if (a[i1][j1] == num)
            {
                i = i1;
                j = j1;
                break;
            }
        }
    }
    while (i > 1)
    {
        if (a[i - 1][j] == 0)
        {
            ans1.pb({{i, j}, {i - 1, j}});
            i--;
            a[i][j] = num;
            a[i + 1][j] = 0;
        }
        else
            break;
    }
}

void collectA()
{
    for (int i = 1; i <= 1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] != 0)
            {
                Move_left_p1(a[i][j]);
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = n; j >= 1; j--)
        {
            if (a[i][j] != 0)
            {
                int id = a[i][j];
                Move_right_p1(id);
                Move_up_p1(id);
                Move_left_p1(id);
            }
        }
    }
}

void Move_left_p3(int num)
{
    int i = 0;
    int j = 0;
    for (int i1 = 1; i1 <= n; i1++)
    {
        for (int j1 = 1; j1 <= n; j1++)
        {
            if (b[i1][j1] == num)
            {
                i = i1;
                j = j1;
                break;
            }
        }
    }
    while (j > 1)
    {
        if (b[i][j - 1] == 0)
        {
            ans3.pb({{i, j}, {i, j - 1}});
            j--;
            b[i][j] = num;
            b[i][j + 1] = 0;
        }
        else
            break;
    }
}

void Move_right_p3(int num)
{
    int i = 0;
    int j = 0;
    for (int i1 = 1; i1 <= n; i1++)
    {
        for (int j1 = 1; j1 <= n; j1++)
        {
            if (b[i1][j1] == num)
            {
                i = i1;
                j = j1;
                break;
            }
        }
    }
    while (j < n)
    {
        if (b[i][j + 1] == 0)
        {
            ans3.pb({{i, j}, {i, j + 1}});
            j++;
            b[i][j] = num;
            b[i][j - 1] = 0;
        }
        else
            break;
    }
}

void Move_up_p3(int num)
{
    int i = 0;
    int j = 0;
    for (int i1 = 1; i1 <= n; i1++)
    {
        for (int j1 = 1; j1 <= n; j1++)
        {
            if (b[i1][j1] == num)
            {
                i = i1;
                j = j1;
                break;
            }
        }
    }
    while (i > 1)
    {
        if (b[i - 1][j] == 0)
        {
            ans3.pb({{i, j}, {i - 1, j}});
            i--;
            b[i][j] = num;
            b[i + 1][j] = 0;
        }
        else
            break;
    }
}

void collectB()
{
    for (int i = 1; i <= 1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (b[i][j] != 0)
            {
                Move_left_p3(b[i][j]);
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = n; j >= 1; j--)
        {
            if (b[i][j] != 0)
            {
                int id = b[i][j];
                Move_right_p3(id);
                Move_up_p3(id);
                Move_left_p3(id);
            }
        }
    }
}

void Move_right_p2(int num)
{
    int i = 0;
    int j = 0;
    for (int i1 = 1; i1 <= n; i1++)
    {
        for (int j1 = 1; j1 <= n; j1++)
        {
            if (a[i1][j1] == num)
            {
                i = i1;
                j = j1;
                break;
            }
        }
    }
    while (j < n)
    {
        if (a[i][j + 1] == 0)
        {
            ans2.pb({{i, j}, {i, j + 1}});
            j++;
            a[i][j] = num;
            a[i][j - 1] = 0;
        }
        else
            break;
    }
}

void Move_left_p2(int num)
{
    int i = 0;
    int j = 0;
    for (int i1 = 1; i1 <= n; i1++)
    {
        for (int j1 = 1; j1 <= n; j1++)
        {
            if (a[i1][j1] == num)
            {
                i = i1;
                j = j1;
                break;
            }
        }
    }
    while (j > 1)
    {
        if (a[i][j - 1] == 0)
        {
            ans2.pb({{i, j}, {i, j - 1}});
            j--;
            a[i][j] = num;
            a[i][j + 1] = 0;
        }
        else
            break;
    }
}

void Move_right_all(int line)
{
    for (int i = n; i >= 1; i--)
    {
        if (a[line][i] != 0)
        {
            int id = a[line][i];
            Move_right_p2(id);
        }
    }
}

void Push(int id)
{
    for (int i = 1; i <= n; i++)
    {
        if (a[2][i] == id)
        {
            a[1][i] = id;
            a[2][i] = 0;
            ans2.pb({{2, i}, {1, i}});
            Move_left_p2(id);
        }
    }
}

void reOrder()
{
    for (int i = 1; i <= m; i++)
    {
        a[2][i] = a[1][i];
        a[1][i] = 0;
        ans2.pb({{1, i}, {2, i}});
    }
    Move_right_all(2);
    for (int i = 1; i <= m; i++)
    {
        int id = b[1][i];
        Push(id);
        Move_right_all(2);
    }
}

int main()
{
    cin >> n >> m;
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    forn(i, m)
    {
        cin >> x[i] >> y[i];
        a[x[i]][y[i]] = i + 1;
    }
    collectA();
    forn(i, m)
    {
        cin >> x2[i] >> y2[i];
        b[x2[i]][y2[i]] = i + 1;
    }
    collectB();
    reOrder();
    if (ans1.sz + ans2.sz + ans3.sz < 10800) {
        cout << ans1.sz + ans2.sz + ans3.sz << "\n";
        forn(i, ans1.sz)
        {
            cout << ans1[i].fi.fi << " " << ans1[i].fi.se << " " << ans1[i].se.fi << " " << ans1[i].se.se << "\n";
        }
        forn(i, ans2.sz)
        {
            cout << ans2[i].fi.fi << " " << ans2[i].fi.se << " " << ans2[i].se.fi << " " << ans2[i].se.se << "\n";
        }
        nfor(i, ans3.sz)
        {
            cout << ans3[i].se.fi << " " << ans3[i].se.se << " " << ans3[i].fi.fi << " " << ans3[i].fi.se << "\n";
        }
    }
    else
    {
        for (int i = 1; i <= 50; i++)
        {
            for (int j = 1; j <= 50; j++)
            {
                a[i][j] = 0;
                b[i][j] = 0;
            }
        }
        ans1.resize(0);
        ans2.resize(0);
        ans3.resize(0);
        forn(i, m)
        {
            a[n + 1 - x[i]][y[i]] = i + 1;
        }
        collectA();
        forn(i, m)
        {
            b[n + 1 - x2[i]][y2[i]] = i + 1;
        }
        collectB();
        reOrder();
        if (ans1.sz + ans2.sz + ans3.sz < 10800) {
            cout << ans1.sz + ans2.sz + ans3.sz << "\n";
            forn(i, ans1.sz)
            {
                cout << n + 1 - ans1[i].fi.fi << " " << ans1[i].fi.se << " " << n + 1 - ans1[i].se.fi << " " << ans1[i].se.se << "\n";
            }
            forn(i, ans2.sz)
            {
                cout << n + 1 - ans2[i].fi.fi << " " << ans2[i].fi.se << " " << n + 1 - ans2[i].se.fi << " " << ans2[i].se.se << "\n";
            }
            nfor(i, ans3.sz)
            {
                cout << n + 1 - ans3[i].se.fi << " " << ans3[i].se.se << " " << n + 1 - ans3[i].fi.fi << " " << ans3[i].fi.se << "\n";
            }
        }
        else
        {
            for (int i = 1; i <= 50; i++)
            {
                for (int j = 1; j <= 50; j++)
                {
                    a[i][j] = 0;
                    b[i][j] = 0;
                }
            }
            ans1.resize(0);
            ans2.resize(0);
            ans3.resize(0);
            forn(i, m)
            {
                a[y[i]][x[i]] = i + 1;
            }
            collectA();
            forn(i, m)
            {
                b[y2[i]][x2[i]] = i + 1;
            }
            collectB();
            reOrder();
            if (ans1.sz + ans2.sz + ans3.sz < 10800) {
                cout << ans1.sz + ans2.sz + ans3.sz << "\n";
                forn(i, ans1.sz)
                {
                    cout << ans1[i].fi.se << " " << ans1[i].fi.fi << " " << ans1[i].se.se << " " << ans1[i].se.fi << "\n";
                }
                forn(i, ans2.sz)
                {
                    cout << ans2[i].fi.se << " " << ans2[i].fi.fi << " " << ans2[i].se.se << " " << ans2[i].se.fi << "\n";
                }
                nfor(i, ans3.sz)
                {
                    cout << ans3[i].se.se << " " << ans3[i].se.fi << " " << ans3[i].fi.se << " " << ans3[i].fi.fi << "\n";
                }
            }
            else
            {
                for (int i = 1; i <= 50; i++)
                {
                    for (int j = 1; j <= 50; j++)
                    {
                        a[i][j] = 0;
                        b[i][j] = 0;
                    }
                }
                ans1.resize(0);
                ans2.resize(0);
                ans3.resize(0);
                forn(i, m)
                {
                    a[n + 1 - y[i]][x[i]] = i + 1;
                }
                collectA();
                forn(i, m)
                {
                    b[n + 1 - y2[i]][x2[i]] = i + 1;
                }
                collectB();
                reOrder();
                if (ans1.sz + ans2.sz + ans3.sz < 10800) {
                    cout << ans1.sz + ans2.sz + ans3.sz << "\n";
                    forn(i, ans1.sz)
                    {
                        cout << n + 1 - ans1[i].fi.se << " " << ans1[i].fi.fi << " " << n + 1 - ans1[i].se.se << " " << ans1[i].se.fi << "\n";
                    }
                    forn(i, ans2.sz)
                    {
                        cout << n + 1 - ans2[i].fi.se << " " << ans2[i].fi.fi << " " << n + 1 - ans2[i].se.se << " " << ans2[i].se.fi << "\n";
                    }
                    nfor(i, ans3.sz)
                    {
                        cout << n + 1 - ans3[i].se.se << " " << ans3[i].se.fi << " " << n + 1 - ans3[i].fi.se << " " << ans3[i].fi.fi << "\n";
                    }
                }
            }
        }
    }
}