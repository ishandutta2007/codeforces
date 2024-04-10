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
const int MAX_M = 128;
const int MAX_N = 2 * 1e5 + 1;
const int km = (1 << 18) - 1;
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int bit_max = 32;
const int m = 10007;

// Code starts here

void solve()
{
    return;
}

typedef vector<vector<ld> > mtx;

ld a[MAX_M];
int n, x;
mtx e, our;

mtx transpose(mtx a)
{
    int n = a[0].size();
    mtx ans(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans[i].push_back(0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans[j][i] = a[i][j];
    return ans;
}

mtx multiply(mtx a, mtx b)
{
    mtx bt = transpose(b);
    int n = a[0].size();
    mtx ans(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans[i].push_back(0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                ans[i][j] += a[i][k] * bt[j][k];
    return ans;
}

mtx power(mtx a, int n)
{
    if (n == 0)
        return e;
    if (n == 1)
        return a;
    if (n % 2 == 0)
    {
        mtx g = power(a, n / 2);
        return multiply(g, g);
    }
    mtx g = power(a, n / 2);
    return multiply(multiply(g, g), a);
}

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    cin >> n >> x;
    x++;
    for (int i = 0; i < x; i++)
        cin >> a[i];
    e.resize(MAX_M);
    for (int i = 0; i < MAX_M; i++)
        for (int j = 0; j < MAX_M; j++)
            e[i].push_back((i == j));
    our.resize(MAX_M);
    for (int i = 0; i < MAX_M; i++)
        for (int j = 0; j < MAX_M; j++)
            our[i].push_back(a[i ^ j]);
    our = power(our, n - 1);
    ld ans = 1;
    for (int i = 0; i < MAX_M; i++)
        ans -= (our[0][i] * a[i]);
    PREX(25);
    cout << ans;
    return 0;
}