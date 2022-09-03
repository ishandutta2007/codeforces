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
#define rand_int (abs((rand() << 15) | rand()))
#define do_zero(massiv) memset(massiv, 0, sizeof(massiv))
#define forn(i, l, r) for (int i = l; i < r; i++)
#define str_to_int(stroka) atoi(stroka.c_str())
#define str_to_ll(stroka) atoll(stroka.c_str())
#define str_to_double(stroka) atof(stroka.c_str())
#define read_int(number) scanf("%d", &number)
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; forn(i, 0, number) solve()
#define solve_system_scanf int number; scanf("%d", &number); forn(i, 0, number) solve()
#define unique(v) v.resize(unique(all(v)) - v.begin())
#define bits(number) __builtin_popcount(number)

//easy functions
template< typename T >
T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template< typename T >
T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
string int_to_str_easy(ll n) { return n ? "" : int_to_str_easy(n / 10) + (char)('0' + n % 10); }
//template< typename T >
//T sum(vector<T> v) {T ans = 0; for (T i : v) ans += i; return ans; }
template< typename T >
bool is_prime_sqrt(T n)
{
    if (n == 1)
        return false;
    T k = trunc(sqrt(n));
    for (T i = 2; i <= k; i++)
        if (n % i == 0)
            return false;
    return true;
}
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
const ll sr = 31;
const ll MOD = 1000000007;
const int BIG = 1e9;
const int alf = 26;
const int MAX_N = 1e6 + 1234;
const int MAX_T = (1 << 20);
const int BLOCK = trunc(sqrt(MAX_N)) + 1;
const int MAX_LOG = 21;
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

ll power(ll a, ll b, ll m)
{
    if (b == 0)
        return 1;
    ll t = power(a, b >> 1LL, m);
    t = (t * t) % m;
    if (b & 1LL)
        t = (t * a) % m;
    return t;
}

ll c[MAX_N], pref[MAX_N], m, a, q, kol[MAX_N];
int n;

ll gett(int x)
{
    if (x > m)
        return pref[m];
    return pref[x];
}

ll how(int x, int p)
{
    ll ans = 0;
    while (x % p == 0)
    {
        x /= p;
        ans++;
    }
    return ans;
}

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    cin >> n >> m >> a >> q;
    ll phi = 1;
    ll qq = q;
    for (int i = 2; i * i <= q; i++)
        if (qq % i == 0)
        {
            phi *= (i - 1);
            qq /= i;
            while (qq % i == 0)
            {
                qq /= i;
                phi *= i;
            }
        }
    if (qq != 1)
        phi *= qq - 1;
    ll p = phi;
    for (ll i = 1; i * i <= q; i++)
        if (phi % i == 0)
        {
            if (power(a, i, q) == 1)
                p = min(p, i);
            ll w = phi / i;
            if (power(a, w, q) == 1)
                p = min(p, w);
        }
    c[0] = 1;
    kol[0] = 0;
    for (ll t = 1; t <= m; t++)
    {
        kol[t] = kol[t - 1];
        int a = t;
        while (a % p == 0)
        {
            kol[t]--;
            a /= p;
        }
        int b = m - t + 1;
        while (b % p == 0)
        {
            kol[t]++;
            b /= p;
        }
        c[t] = (((c[t - 1] * power(a, p - 2, p)) % p) * b) % p;
    }
    for (int i = 0; i <= m; i++)
        if (kol[i] > 0)
            c[i] = 0;
    pref[0] = c[0];
    for (int i = 0; i < m; i++)
        pref[i + 1] = (pref[i] + c[i + 1]) % p;
    for (int i = 0; i < n; i++)
        cout << power(a, gett(n - i - 1), q) << " ";
    return 0;
}