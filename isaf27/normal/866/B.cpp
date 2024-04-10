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
#define solve_system_scanf int number; scanf("%d", &number); forn(i, 0, number) solve()
#define unique(v) v.resize(unique(all(v)) - v.begin())
#define bits(number) __builtin_popcount(number)

//easy functions
template< typename T >
T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template< typename T >
T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
//string int_to_str_easy(ll n) { return n ? "" : int_to_str_easy(n / 10) + (char)('0' + n % 10); }
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
const int MOD = 1e9 + 7;
const int BIG = 1e9 + 1;
const int alf = 26;
const int MAX_N = 1e5 + 1;
const int MAX_M = 2 * MAX_N + 100;
const int MAX_T = (1 << 20);
const int BLOCK = trunc(sqrt(MAX_N)) + 1;
const int MAX_LOG = 18;
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
const int bt = 31;

// Code starts here

vector<pair<ll, ll> > v[two], b;
ll ans;
int n;
ll w[MAX_N], a[MAX_N], be[MAX_N], s, m;

void bucket(int c)
{
    ll ls = 0;
    ll k = 0;
    for (pair<ll, ll> t : v[c])
    {
        ll p = t.first;
        ll kol = t.second;
        if (kol + k < s)
        {
            k += kol;
            ls += kol * p;
            continue;
        }
        ls += (s - k) * p;
        b.push_back(make_pair(ls, 1));
        kol -= (s - k);
        k = 0;
        ls = 0;
        if (kol >= s)
            b.push_back(make_pair(s * p, (kol / s)));
        kol %= s;
        ls = kol * p;
        k = kol;
    }
    b.push_back(make_pair(ls, 1));
}

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    ans = 0;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> w[i] >> a[i] >> be[i];
    for (int i = 0; i < n; i++)
        m += w[i];
    m = (m + s - 1) / s;
    for (int i = 0; i < n; i++)
        ans += w[i] * min(a[i], be[i]);
    for (int i = 0; i < n; i++)
    {
        if (a[i] > be[i])
            v[0].push_back(make_pair(a[i] - be[i], w[i]));
        else if (a[i] < be[i])
            v[1].push_back(make_pair(be[i] - a[i], w[i]));
    }
    sort(v[0].rbegin(), v[0].rend());
    sort(v[1].rbegin(), v[1].rend());
    bucket(0);
    bucket(1);
    sort(b.rbegin(), b.rend());
    for (int i = 0; i < b.size(); i++)
    {
        ll p = b[i].first;
        ll kol = b[i].second;
        if (m > kol)
        {
            m -= kol;
            ans += kol * p;
            continue;
        }
        ans += p * m;
        m = 0;
        break;
    }
    cout << ans;
    return 0;
}