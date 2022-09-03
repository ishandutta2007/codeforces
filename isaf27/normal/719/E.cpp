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
#define all(v) v.begin(), v.end()
#define random srand(time(NULL))
#define rand_int ((rand() << 15) | rand())
#define do_zero(massiv) memset(massiv, 0, sizeof(massiv))
#define forn(i, l, r) for (int i = l; i < r; i++)
#define str_to_int(stroka) atoi(stroka.c_str())
#define str_to_ll(stroka) atoll(stroka.c_str())
#define str_to_double(stroka) atof(stroka.c_str())
#define read_int(number) scanf("%d", &number)
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; forn(i, 0, number) solve()
#define ones(v) v.resize(unique(all(v)) - v.begin())

//easy functions
template< typename T >
T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template< typename T >
T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
string int_to_str_easy(ll n) { return n ? "" : int_to_str_easy(n / 10) + (char)('0' + n % 10); }
template< typename T >
T sum(vector<T> v) {T ans = 0; for (T i : v) ans += i; return ans; }
bool is_down(char x) { return ('a' <= x && x <= 'z'); }
bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
bool is_digit(char x) { return ('0' <= x && x <= '9'); }
string follow(string s) { for (int i = 0; i < s.length(); i++) if (is_upper(s[i])) s[i] += 'a' - 'A'; return s; }

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
const ll MOD = 1000000007;
const int BIG = 1e9;
const int alf = 26;
const int MAX_M = 2001;
const int MAX_N = 1e5 + 1;
const int km = (1 << 18) - 1;
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int bit_max = 32;
const int siz = 8 * MAX_N + 20000;

// Code starts here

void solve()
{
    return;
}

struct matrix
{
    ll a11, a12, a21, a22;

    matrix()
    {
        a11 = 0;
        a12 = 0;
        a21 = 0;
        a22 = 0;
    }

    matrix nul_matrix()
    {
        matrix ans;
        ans.a11 = 1;
        ans.a22 = 1;
        ans.a12 = 0;
        ans.a21 = 0;
        return ans;
    }

    matrix fib_matrix()
    {
        matrix ans;
        ans.a11 = 1;
        ans.a21 = 1;
        ans.a12 = 1;
        ans.a22 = 0;
        return ans;
    }

    matrix operator+(const matrix &t) const
    {
        matrix ans;
        ans.a11 = (a11 + t.a11) % MOD;
        ans.a21 = (a21 + t.a21) % MOD;
        ans.a12 = (a12 + t.a12) % MOD;
        ans.a22 = (a22 + t.a22) % MOD;
        return ans;
    }

    matrix operator*(const matrix &t) const
    {
        matrix ans;
        ans.a11 = ((a11 * t.a11) % MOD + (a12 * t.a21) % MOD) % MOD;
        ans.a21 = ((a21 * t.a11) % MOD + (a22 * t.a21) % MOD) % MOD;
        ans.a12 = ((a11 * t.a12) % MOD + (a12 * t.a22) % MOD) % MOD;
        ans.a22 = ((a21 * t.a12) % MOD + (a22 * t.a22) % MOD) % MOD;
        return ans;
    }
};

matrix power(matrix t, ll r)
{
    if (r == 0)
        return t.nul_matrix();
    if (r == 1)
        return t;
    matrix w = power(t, r / 2);
    w = w * w;
    if (r % 2 == 1)
        w = w * t;
    return w;
}

int n, m;
matrix a[siz], add[siz], un;
bool want[siz];

void push(int i, int l, int r)
{
    if (!want[i])
        return;
    a[i] = a[i] * add[i];
    if (r - l != 1)
    {
        add[2 * i + 1] = add[2 * i + 1] * add[i];
        add[2 * i + 2] = add[2 * i + 2] * add[i];
        want[2 * i + 1] = true;
        want[2 * i + 2] = true;
    }
    want[i] = false;
    add[i] = add[i].nul_matrix();
}

void upd_segment(int i, int l, int r, int ql, int qr, matrix t)
{
    push(i, l, r);
    if (l >= qr || r <= ql)
        return;
    if (l >= ql && r <= qr)
    {
        add[i] = t;
        want[i] = true;
        push(i, l, r);
        return;
    }
    int mid = (l + r) / 2;
    upd_segment(2 * i + 1, l, mid, ql, qr, t);
    upd_segment(2 * i + 2, mid, r, ql, qr, t);
    a[i] = a[2 * i + 1] + a[2 * i + 2];
}


matrix answer(int i, int l, int r, int ql, int qr)
{
    push(i, l, r);
    //a[i] = min(a[2 * i + 1], a[2 * i + 2]);
    if (l >= qr || r <= ql)
        return un;
    if (l >= ql && r <= qr)
        return a[i];
    int mid = (l + r) / 2;
    return answer(2 * i + 1, l, mid, ql, qr) + answer(2 * i + 2, mid, r, ql, qr);
}

void build(int i, int l, int r)
{
    if (r - l == 1)
    {
        a[i] = un.nul_matrix();
        return;
    }
    int mid = (l + r) / 2;
    build(2 * i + 1, l, mid);
    build(2 * i + 2, mid, r);
    a[i] = a[2 * i + 1] + a[2 * i + 2];
}

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    for (int i = 0; i < siz; i++)
        add[i] = un.nul_matrix();
    build(0, 0, km + 1);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int r;
        scanf("%d", &r);
        matrix go = power(un.fib_matrix(), (ll)(r - 1));
        upd_segment(0, 0, km + 1, i, i + 1, go);
    }
    for (int i = 0; i < m; i++)
    {
        int type;
        scanf("%d", &type);
        if (type == 1)
        {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            l--;
            matrix go = power(un.fib_matrix(), (ll)(x));
            upd_segment(0, 0, km + 1, l, r, go);
        }
        else
        {
            int l, r;
            scanf("%d%d", &l, &r);
            l--;
            matrix go = answer(0, 0, km + 1, l, r);
            cout << go.a11 << "\n";
        }
    }
    return 0;
}