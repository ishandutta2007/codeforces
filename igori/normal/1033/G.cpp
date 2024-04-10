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
ll n, m;
ll t[500];
ll v[500];
ll cnt[5];
ll A, B, F, S;

struct change{
    int f;
    int t;
    int x;
};
change C[506];
ll cnt_;

bool comp(change A, change B)
{
    re A.x < B.x;
}

ll solve(int a, int b)
{
    if (a < b) {
        //cout << a << " " << a + b << endl;
        ll t1 = 0, t2 = 0, t3 = 0, t4 = 0;
        for (int i = 0; i < n; i++)
        {
            if (0 <= v[i] && v[i] < a)
                t1++;
            if (a <= v[i] && v[i] < b)
                t2++;
            if (b <= v[i] && v[i] < 2 * a)
                t3++;
        }
        t4 = n - t1 - t2 - t3;
        cnt[1] = t1;
        cnt[2] = t2;
        cnt[3] = t3;
        cnt[4] = t4;
        if (t2 > 0 || t4 > 1)
        {
            //A++;
            //B++;
            re 0;
        }
        else
        if ((t3 + t4) % 2 == 0)
        {
            //S+=2;
            re 2;
        }
        else
        {
            //F+=2;
            re 1;
        }
    }
    re 4;
}

ll solve2()
{
    if (cnt[2] > 0 || cnt[4] > 1)
    {
        re 0;
    }
    if (cnt[4] == 1 && cnt[3] % 2 == 1)
        re 0;
    if ((cnt[3] + cnt[4]) % 2 == 0)
       re 2;
    re 1;
}

void use_change(int i)
{
    cnt[C[i].f]--;
    cnt[C[i].t]++;
}

ll tp(int summ, int val, int a)
{
    int b = summ - a;
    if (0 <= val && val < a)
        re 1;
    if (a <= val && val < b)
        re 2;
    if (b <= val && val < 2 * a)
        re 3;
    re 4;
}

ll findA[50];
ll cnst;

void predict_changes(int summ, int val)
{
    ll now = tp(summ, val, max(summ - m, 1));
    int a;
    //for (int a = max(1, summ - m) + 1; a < summ / 2 + summ % 2; a++)
    //    findA.pb(a);
    cnst = 0;
    findA[cnst] = val + 1;
    cnst++;
    //for (int i = 1; i <= summ; i++)
    //    findA.pb(i);
    //findA.pb(val / 2 + 0);
    //findA.pb(summ / 2 + 0);
    findA[cnst] = summ - val + 0;
    cnst++;
    findA[cnst] = val / 2 + 1;
    cnst++;
    //findA.pb(summ / 2 + 1);
    //findA.pb(summ - val + 1);
    sort(findA, findA + cnst);
    for (int i = 0; i < cnst; i++)
    {
        a = findA[i];
        //cout << a << " ";
        if (a < max(1, summ - m) || a > summ / 2 + summ % 2)
            continue;
        if (tp(summ, val, a) != now)
        {
            change CC;
            CC.f = now;
            CC.t = tp(summ, val, a);
            CC.x = a;
            C[cnt_] = CC;
            cnt_++;
            //cerr << "summ, value, from, to, a :" << summ << " " << val << " " << CC.f << " " << CC.t << " " << a << endl;
            now = tp(summ, val, a);
        }
    }
    a = summ / 2 + summ % 2;
    change CC;
    CC.f = now;
    CC.t = 0;
    CC.x = a;
    C[cnt_] = CC;
    cnt_++;
    return;
}

void predict_changes(int summ)
{
    for (int i = 0; i < n; i++)
    {
        predict_changes(summ, v[i]);
    }
    sort(C, C + cnt_, comp);
}

void work(int summ)
{
    //cerr << "case summ : " << summ << endl;
    cnt_ = 0;
    for (int i = 0; i < n; i++)
    {
        v[i] = t[i] % summ;
        //cerr << v[i] << " ";
    }
    //cerr << endl;
    if (summ % 2 == 0)
    {
        ll g = 0;
        for (int i = 0; i < n; i++)
        {
            g += v[i] / (summ / 2);
        }
        if (g % 2 == 0)
        {
            S++;
        }
        else
        {
            F++;
        }
    }
    int a = max(1, summ - m);
    if (a >= summ / 2 + summ % 2)
        re;
    ll last = solve(a, summ - a);
    //cerr << "Start : " << a << " " << endl;
    ll fixed_to = a;
    /*for (a = max(1, summ - m) + 1; a < summ / 2 + summ % 2; a++)
    {
        int b = summ - a;
        ll t = solve(a, b);
        if (t == -9)
            break;
        if (t != last)
        {
            cerr << "General changes : " << a << " " << last << " " << t << endl;
            last = t;
        }
    }*/
    predict_changes(summ);
    for (int i = 0; i < cnt_; i++)
    {
        if (solve2() == 0)
        {
            A += C[i].x - fixed_to;
            B += C[i].x - fixed_to;
        }
        if (solve2() == 1)
        {
            F += 2 * (C[i].x - fixed_to);
        }
        if (solve2() == 2)
        {
            S += 2 * (C[i].x - fixed_to);
        }
        use_change(i);
        fixed_to = C[i].x;

        if (cnt[1] + cnt[2] + cnt[3] + cnt[4] != n)
        {
            break;
        }
    }
    //cerr << "Finish : " << fixed_to << endl;
    //cerr << endl;
}

signed main()
{
    //freopen("conspiracy.in", "r", stdin);
    //freopen("conspiracy.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    forn(i, n) cin >> t[i];
    for (int j = 2; j <= 2 * m; j++)
    {
        work(j);
    }
    cout << A << " " << B << " " << F << " " << S << endl;
    //cerr << A + B + F + S << endl;
    return 0;
}