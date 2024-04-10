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
string int_to_str_easy(ll n) { return n ? "" : int_to_str_easy(n / 10) + (char)('0' + n % 10); }
template< typename T >
T sum(vector<T> v) {T ans = 0; for (T i : v) ans += i; return ans; }
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
const int MAX_N = 3 * 1e5 + 10;
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
const int bt = 31;

// Code starts here

ll dp[bit_max][two][two][two], kol[bit_max][two][two][two];

int answer(int l, int r, int k)
{
    if (l == 0 || r == 0)
        return 0;
    l--, r--, k--;
    ll ans = 0;
    memset(dp, 0, sizeof(dp));
    memset(kol, 0, sizeof(kol));
    kol[bt][1][1][1] = 1;
    for (int s = bt - 1; s >= 0; s--)
        for (int pl = 0; pl < two; pl++)
            for (int pr = 0; pr < two; pr++)
                for (int px = 0; px < two; px++)
    {
        for (int nl = 0; nl < two; nl++)
            for (int nr = 0; nr < two; nr++)
                for (int nx = 0; nx < two; nx++)
        {
            if (pl == 1 && nl == 0)
                continue;
            if (pr == 1 && nr == 0)
                continue;
            if (px == 1 && nx == 0)
                continue;
            int bl = -1, br = -1, bx = -1;
            if (pl == 1)
                bl = (l >> s) & 1;
            if (pr == 1)
                br = (r >> s) & 1;
            if (px == 1)
                bx = (k >> s) & 1;
            if (pl == 0 && nl == 1)
                if (((l >> s) & 1) == 0)
                    continue;
            if (pr == 0 && nr == 1)
                if (((r >> s) & 1) == 0)
                    continue;
            if (px == 0 && nx == 1)
                if (((k >> s) & 1) == 0)
                    continue;
            if (pl == 0 && nl == 1)
                bl = 0;
            if (pr == 0 && nr == 1)
                br = 0;
            if (px == 0 && nx == 1)
                bx = 0;
            if (bx != -1 && bl != -1 && br != -1)
                if (bx != (bl ^ br))
                    continue;
            if (bx == -1 && bl != -1 && br != -1)
                bx = bl ^ br;
            if (bl == -1 && br != -1 && bx != -1)
                bl = br ^ bx;
            if (br == -1 && bx != -1 && bl != -1)
                br = bx ^ bl;
            if (bx == -1 && bl == -1 && br == -1)
            {
                kol[s][pl][pr][px] = (kol[s][pl][pr][px] + 4 * kol[s + 1][nl][nr][nx]) % MOD;
                dp[s][pl][pr][px] = (dp[s][pl][pr][px] + 4 * dp[s + 1][nl][nr][nx] + 2LL * (1LL << (ll)s) * kol[s + 1][nl][nr][nx]) % MOD;
                continue;
            }
            if (bl != -1 && br != -1 && bx != -1)
            {
                kol[s][pl][pr][px] = (kol[s][pl][pr][px] + kol[s + 1][nl][nr][nx]) % MOD;
                dp[s][pl][pr][px] = (dp[s][pl][pr][px] + dp[s + 1][nl][nr][nx] + 1LL * (bx == 1) * (1LL << (ll)s) * kol[s + 1][nl][nr][nx]) % MOD;
                continue;
            }
            if (bx != -1)
            {
                kol[s][pl][pr][px] = (kol[s][pl][pr][px] + 2LL * kol[s + 1][nl][nr][nx]) % MOD;
                dp[s][pl][pr][px] = (dp[s][pl][pr][px] + 2 * dp[s + 1][nl][nr][nx] + 2LL * (bx == 1) * (1LL << (ll)s) * kol[s + 1][nl][nr][nx]) % MOD;
                continue;
            }
            if (bl != -1 || br != -1)
            {
                kol[s][pl][pr][px] = (kol[s][pl][pr][px] + 2LL * kol[s + 1][nl][nr][nx]) % MOD;
                dp[s][pl][pr][px] = (dp[s][pl][pr][px] + 2 * dp[s + 1][nl][nr][nx] + (1LL << (ll)s) * kol[s + 1][nl][nr][nx]) % MOD;
                continue;
            }
        }
    }
    for (int pl = 0; pl < two; pl++)
        for (int pr = 0; pr < two; pr++)
            for (int px = 0; px < two; px++)
                ans = (ans + dp[0][pl][pr][px] + kol[0][pl][pr][px]) % MOD;
    return ans;
}

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    //fast_read;
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int x1, x2, y1, y2, k;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &k);
        x1--, y1--;
        ll ans = (ll)answer(x2, y2, k) + (ll)answer(x1, y1, k) - (ll)answer(x1, y2, k) - (ll)answer(x2, y1, k);
        ans %= MOD;
        if (ans < 0) ans += MOD;
        cout << ans << "\n";
    }
    return 0;
}