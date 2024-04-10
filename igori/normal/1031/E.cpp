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
ll n, m, k;
struct three{
    int x, y, z;
};

ll t[200000];
vector<int> res(11);
vector<three> p;
vector<three> sollutions[2048];

void upd(int a, int b, int c, int x)
{
    if (a >= x || b >= x || c >= x)
        return;
    res[a] ^= 1;
    res[b] ^= 1;
    res[c] ^= 1;
    p.pb({a, b, c});
    return;
}

void perebor(int x)
{
    for (int i = 0; i < (1 << 10); i++)
        sollutions[i].resize(0);
    for (int i = 0; i < (1 << 20); i++)
    {
        for (int j = 0; j < x; j++)
            res[j] = 0;
        p.resize(0);
        if ((i & (1 << 0))) upd(0, 1, 2, x);
        if ((i & (1 << 1))) upd(1, 2, 3, x);
        if ((i & (1 << 2))) upd(2, 3, 4, x);
        if ((i & (1 << 3))) upd(3, 4, 5, x);
        if ((i & (1 << 4))) upd(4, 5, 6, x);
        if ((i & (1 << 5))) upd(5, 6, 7, x);
        if ((i & (1 << 6))) upd(6, 7, 8, x);
        if ((i & (1 << 7))) upd(7, 8, 9, x);
        if ((i & (1 << 8))) upd(0, 2, 4, x);
        if ((i & (1 << 9))) upd(1, 3, 5, x);
        if ((i & (1 << 10))) upd(2, 4, 6, x);
        if ((i & (1 << 11))) upd(3, 5, 7, x);
        if ((i & (1 << 12))) upd(4, 6, 8, x);
        if ((i & (1 << 13))) upd(5, 7, 9, x);
        if ((i & (1 << 14))) upd(0, 3, 6, x);
        if ((i & (1 << 15))) upd(1, 4, 7, x);
        if ((i & (1 << 16))) upd(2, 5, 8, x);
        if ((i & (1 << 17))) upd(3, 6, 9, x);
        if ((i & (1 << 18))) upd(0, 4, 8, x);
        if ((i & (1 << 19))) upd(1, 5, 9, x);
        ll gen = 0;
        for (int j = 0; j < x; j++)
            gen = gen * 2 + res[j];
        if (p.size() < sollutions[gen].sz || sollutions[gen].sz == 0)
            sollutions[gen] = p;
    }
}

vector<int> ruines(11);
vector<three> ans;
vector<three> pre_ans;

void upd(int a, int b, int c)
{
    ruines[a] ^= 1;
    ruines[b] ^= 1;
    ruines[c] ^= 1;
    pre_ans.pb({a, b, c});
}

void sauce(int i)
{
    if (i == 1) upd(8, 9, 10);
    if (i == 2) upd(7, 8, 9);
    if (i == 3) upd(6, 7, 8);
    if (i == 4) upd(5, 6, 7);
    if (i == 5) upd(4, 5, 6);
    if (i == 6) upd(3, 4, 5);
    if (i == 7) upd(6, 8, 10);
    if (i == 8) upd(5, 7, 9);
    if (i == 9) upd(4, 6, 8);
    if (i == 10) upd(3, 5, 7);
    if (i == 11) upd(2, 4, 6);
    if (i == 12) upd(1, 3, 5);
    if (i == 13) upd(4, 7, 10);
    if (i == 14) upd(3, 6, 9);
    if (i == 15) upd(2, 5, 8);
    if (i == 16) upd(1, 4, 7);
    if (i == 17) upd(0, 3, 6);
    if (i == 18) upd(2, 6, 10);
    if (i == 19) upd(1, 5, 9);
    if (i == 20) upd(0, 4, 8);
    if (i == 21) upd(0, 5, 10);
}

void another(int pos)
{
    for (int i = 0; i < 22; i++)
    {
        for (int j = 0; j < 22; j++)
        {
            for (int i2 = 0; i2 < 11; i2++)
                ruines[i2] = 0;
            pre_ans.resize(0);
            sauce(i);
            sauce(j);
            if (t[pos] == ruines[5] &&
                t[pos + 1] == ruines[6] &&
                t[pos + 2] == ruines[7] &&
                t[pos + 3] == ruines[8] &&
                t[pos + 4] == ruines[9] &&
                t[pos + 5] == ruines[10])
            {
                t[pos - 1] ^= ruines[4];
                t[pos - 2] ^= ruines[3];
                t[pos - 3] ^= ruines[2];
                t[pos - 4] ^= ruines[1];
                t[pos - 5] ^= ruines[0];
                t[pos + 1] ^= ruines[6];
                t[pos + 2] ^= ruines[7];
                t[pos + 3] ^= ruines[8];
                t[pos + 4] ^= ruines[9];
                t[pos + 5] ^= ruines[10];
                t[pos] ^= ruines[5];
                for (int i2 = 0; i2 < pre_ans.sz; i2++)
                {
                    three F = pre_ans[i2];
                    F.x += pos - 4;
                    F.y += pos - 4;
                    F.z += pos - 4;
                    ans.pb(F);
                }
                return;
            }
        }
    }
}

int main()
{
    cin >> n;
    k = n;
    forn(i, n)
        cin >> t[i];
    if (n <= 10)
    {
        perebor(n);
        ll gen = 0;
        for (int i = 0; i < n; i++)
            gen = gen * 2 + t[i];
        if (gen != 0 && sollutions[gen].sz == 0)
        {
            cout << "NO";
            re 0;
        }
        else
        {
            cout << "YES\n";
            cout << sollutions[gen].sz << endl;
            for (int i = 0; i < sollutions[gen].sz; i++)
            {
                cout << 1 + sollutions[gen][i].x << " " << 1 + sollutions[gen][i].y << " " << 1 + sollutions[gen][i].z << "\n";
            }
            re 0;
        }
    }
    k = n - 6;
    while (k >= 5)
    {
        another(k);
        k -= 6;
    }
    perebor(10);
    ll gen = 0;
    for (int i = 0; i < 10; i++)
        gen = gen * 2 + t[i];
    for (int i = 0; i < sollutions[gen].sz; i++)
    {
        three F = sollutions[gen][i];
        F.x++;
        F.y++;
        F.z++;
        ans.pb(F);
    }
    cout << "YES\n";
    cout << ans.sz << "\n";
    for (int i = 0; i < ans.sz; i++)
    {
        cout << ans[i].x << " " << ans[i].y << " " << ans[i].z << "\n";
    }
}