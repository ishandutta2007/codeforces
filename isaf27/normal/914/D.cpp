#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <time.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stdlib.h>
#include <deque>
#include <iomanip>
#include <complex>
//#include <ext/rope>

using namespace std;
//using namespace __gnu_cxx;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fast_read cin.sync_with_stdio(0)
#define PREX(number) cout << fixed << setprecision(number)
#define nul point(0, 0)
#define random srand(time(NULL))
#define rand_int abs((rand() << 15) | rand())
#define str_to_int(stroka) atoi(stroka.c_str())
#define str_to_ll(stroka) atoll(stroka.c_str())
#define str_to_double(stroka) atof(stroka.c_str())
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; forn(i, 0, number) solve()
#define solve_system_scanf int number; scanf("%d", &number); forn(i, 0, number) solve()

//easy functions
//template< typename T >
//T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template< typename T >
T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
bool is_down(char x) { return ('a' <= x && x <= 'z'); }
bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
bool is_digit(char x) { return ('0' <= x && x <= '9'); }

//constants
const ld pi = 3.141592653589793238462643383279;
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-8;
const ld zero = 0;
const ll INF = 1e18;
const int COUT = 30;
const int prost = 239;
const ll prost64 = 239;
const int two = 2;
const int thr = 3;
const ll sr = 31;
const int MOD = 1e9 + 7;
const int BIG = 2 * 1e9 + 1;
const int alf = 26;
const int MAX_N = 5 * 1e5 + 10;
const int MAX_M = 1011;
const int MAX_T = (1 << 20);
const int BLOCK = trunc(sqrt(MAX_N)) + 1;
const int MAX_LOG = 19;
const int km = (1 << 18);
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int bit_max = 32;
const int dig = 10;
const string str_alf = "abcdefghijklmnopqrstuvwxyz";
const string str_alf_big = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int bt = 31;

// Code starts here

int gcd(int a, int b)
{
    return a ? gcd(b % a, a) : b;
}

int a[MAX_T];
int n, st[MAX_N], q;

void build(int i, int l, int r)
{
    if (r - l == 1)
    {
        a[i] = st[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * i + 1, l, mid);
    build(2 * i + 2, mid, r);
    a[i] = gcd(a[2 * i + 1], a[2 * i + 2]);
}

void upd(int i, int l, int r, int p, int x)
{
    if (p < l || r <= p)
        return;
    if (l <= p && p < r && r - l == 1)
    {
        a[i] = x;
        return;
    }
    int mid = (l + r) >> 1;
    upd(2 * i + 1, l, mid, p, x);
    upd(2 * i + 2, mid, r, p, x);
    a[i] = gcd(a[2 * i + 1], a[2 * i + 2]);
}

int func(int i, int l, int r, int ql, int qr, int x)
{
    if (r <= ql || qr <= l)
        return -1;
    if (ql <= l && r <= qr)
    {
        if (a[i] % x == 0)
            return -1;
        if (r - l == 1)
            return l;
        if (a[2 * i + 1] % x == 0)
            return func(2 * i + 2, (l + r) >> 1, r, ql, qr, x);
        return func(2 * i + 1, l, (l + r) >> 1, ql, qr, x);
    }
    int mid = (l + r) >> 1;
    int t = func(2 * i + 1, l, mid, ql, qr, x);
    if (t == -1)
        return func(2 * i + 2, mid, r, ql, qr, x);
    return t;
}

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    //fast_read;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &st[i]);
    build(0, 0, n);
    scanf("%d", &q);
    for (int z = 0; z < q; z++)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            l--, r--;
            int p = func(0, 0, n, l, r + 1, x);
            //cerr << p << "\n";
            if (p == -1)
                cout << "YES\n";
            else if (p == r)
                cout << "YES\n";
            else
            {
                int u = func(0, 0, n, p + 1, r + 1, x);
                //cerr << u << "\n";
                if (u == -1)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        }
        else
        {
            int p, x;
            scanf("%d%d", &p, &x);
            p--;
            upd(0, 0, n, p, x);
        }
    }
    return 0;
}