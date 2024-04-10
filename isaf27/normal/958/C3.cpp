//isaf27

//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fast_read cin.sync_with_stdio(0)
#define PREX(number) cout << fixed << setprecision(number)
#define nul point(0, 0)
#define str_to_int(stroka) atoi(stroka.c_str())
#define str_to_ll(stroka) atoll(stroka.c_str())
#define str_to_double(stroka) atof(stroka.c_str())
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; for (int i = 0; i < number; i++) solve()
#define solve_system_scanf int number; scanf("%d", &number); forn(i, 0, number) solve()

//easy functions
template< typename T >
T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template< typename T >
T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
bool is_down(char x) { return ('a' <= x && x <= 'z'); }
bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
bool is_digit(char x) { return ('0' <= x && x <= '9'); }

//constants
const ld pi = 3.141592653589793238462643383279;
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const ll prost = 239;
const int two = 2;
const int th = 3;
const ll MOD = 1e9 + 7;
const ll MOD2 = MOD * MOD;
const int BIG = 1e9 + 239;
const int alf = 26;
const int M = 5 * 1e5 + 239;
const int N = 2 * 1e3 + 239;
const int L = 80;
const int T = (1 << 18);
const int B = trunc(sqrt(M)) + 1;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dig = 10;
const string str_alf = "abcdefghijklmnopqrstuvwxyz";
const string str_alf_big = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int bt = 31;
const int K = 102;
const int P = 102;

// Code starts here

int dp[two][K][P], kt[two][K];
int n, k, p, a[M];
int f1[K][P], f2[K][P];

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    cin >> n >> k >> p;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n <= 20100)
    {
        for (int i = 0; i <= k; i++)
            for (int j = 0; j < p; j++)
                dp[0][i][j] = BIG;
        dp[0][0][0] = 0;
        for (int i = 0; i <= k; i++)
            kt[0][i] = BIG;
        kt[0][0] = 0;
        for (int i = 0; i < n; i++)
        {
            a[i] %= p;
            for (int x = 1; x <= k; x++)
                for (int s = 0; s < p; s++)
                {
                    dp[(i + 1) & 1][x][s] = BIG;
                    if (s == a[i])
                    {
                        if (kt[i & 1][x - 1] != BIG)
                            dp[(i + 1) & 1][x][s] = kt[i & 1][x - 1] + a[i];
                    }
                    if (s >= a[i])
                    {
                        if (dp[i & 1][x][s - a[i]] != BIG)
                            dp[(i + 1) & 1][x][s] = min(dp[(i + 1) & 1][x][s], dp[i & 1][x][s - a[i]] + a[i]);
                    }
                    else if (s < a[i])
                    {
                        if (dp[i & 1][x][s + p - a[i]] != BIG)
                            dp[(i + 1) & 1][x][s] = min(dp[(i + 1) & 1][x][s], dp[i & 1][x][s + p - a[i]] + a[i] - p);
                    }
                }
            for (int s = 0; s < p; s++)
                dp[(i + 1) & 1][0][s] = BIG;
            for (int x = 0; x <= k; x++)
            {
                kt[(i + 1) & 1][x] = BIG;
                for (int s = 0; s < p; s++)
                    kt[(i + 1) & 1][x] = min(kt[(i + 1) & 1][x], dp[(i + 1) & 1][x][s]);
            }
        }
        int ans = BIG;
        for (int t = 0; t < p; t++)
            ans = min(ans, dp[n & 1][k][t]);
        cout << ans;
        return 0;
    }
    int N = 10000;
    for (int i = 0; i <= k; i++)
        for (int j = 0; j < p; j++)
            dp[0][i][j] = BIG;
    dp[0][0][0] = 0;
    for (int i = 0; i <= k; i++)
        kt[0][i] = BIG;
    kt[0][0] = 0;
    for (int i = 0; i < N; i++)
    {
        a[i] %= p;
        for (int x = 1; x <= k; x++)
            for (int s = 0; s < p; s++)
            {
                dp[(i + 1) & 1][x][s] = BIG;
                if (s == a[i])
                {
                    if (kt[i & 1][x - 1] != BIG)
                        dp[(i + 1) & 1][x][s] = kt[i & 1][x - 1] + a[i];
                }
                if (s >= a[i])
                {
                    if (dp[i & 1][x][s - a[i]] != BIG)
                        dp[(i + 1) & 1][x][s] = min(dp[(i + 1) & 1][x][s], dp[i & 1][x][s - a[i]] + a[i]);
                }
                else if (s < a[i])
                {
                    if (dp[i & 1][x][s + p - a[i]] != BIG)
                        dp[(i + 1) & 1][x][s] = min(dp[(i + 1) & 1][x][s], dp[i & 1][x][s + p - a[i]] + a[i] - p);
                }
            }
        for (int s = 0; s < p; s++)
            dp[(i + 1) & 1][0][s] = BIG;
        for (int x = 0; x <= k; x++)
        {
            kt[(i + 1) & 1][x] = BIG;
            for (int s = 0; s < p; s++)
                kt[(i + 1) & 1][x] = min(kt[(i + 1) & 1][x], dp[(i + 1) & 1][x][s]);
        }
    }
    for (int i = 1; i <= k; i++)
        for (int s = 0; s <= p; s++)
            f1[i][s] = dp[N & 1][i][s];
    reverse(a, a + n);
    for (int i = 0; i <= k; i++)
        for (int j = 0; j < p; j++)
            dp[0][i][j] = BIG;
    dp[0][0][0] = 0;
    for (int i = 0; i <= k; i++)
        kt[0][i] = BIG;
    kt[0][0] = 0;
    for (int i = 0; i < N; i++)
    {
        a[i] %= p;
        for (int x = 1; x <= k; x++)
            for (int s = 0; s < p; s++)
            {
                dp[(i + 1) & 1][x][s] = BIG;
                if (s == a[i])
                {
                    if (kt[i & 1][x - 1] != BIG)
                        dp[(i + 1) & 1][x][s] = kt[i & 1][x - 1] + a[i];
                }
                if (s >= a[i])
                {
                    if (dp[i & 1][x][s - a[i]] != BIG)
                        dp[(i + 1) & 1][x][s] = min(dp[(i + 1) & 1][x][s], dp[i & 1][x][s - a[i]] + a[i]);
                }
                else if (s < a[i])
                {
                    if (dp[i & 1][x][s + p - a[i]] != BIG)
                        dp[(i + 1) & 1][x][s] = min(dp[(i + 1) & 1][x][s], dp[i & 1][x][s + p - a[i]] + a[i] - p);
                }
            }
        for (int s = 0; s < p; s++)
            dp[(i + 1) & 1][0][s] = BIG;
        for (int x = 0; x <= k; x++)
        {
            kt[(i + 1) & 1][x] = BIG;
            for (int s = 0; s < p; s++)
                kt[(i + 1) & 1][x] = min(kt[(i + 1) & 1][x], dp[(i + 1) & 1][x][s]);
        }
    }
    for (int i = 1; i <= k; i++)
        for (int s = 0; s <= p; s++)
            f2[i][s] = dp[N & 1][i][s];
    int s = 0;
    for (int i = N; i < n - N; i++)
        s = (s + a[i]) % p;
    int ans = BIG;
    for (int i1 = 1; i1 <= k; i1++)
        for (int i2 = 1; i2 <= k; i2++)
            for (int s1 = 0; s1 < p; s1++)
                for (int s2 = 0; s2 < p; s2++)
                {
                    if (i1 + i2 == k - 1)
                        ans = min(ans, f1[i1][s1] + f2[i2][s2] + s);
                    if (i1 + i2 == k)
                        ans = min(ans, f1[i1][s1] + f2[i2][s2] - s1 + ((s + s1) % p));
                    if (i1 + i2 == k)
                        ans = min(ans, f1[i1][s1] + f2[i2][s2] - s2 + ((s + s2) % p));
                    if (i1 + i2 == k + 1)
                        ans = min(ans, f1[i1][s1] + f2[i2][s2] - s1 - s2 + ((s + s1 + s2) % p));
                }
    cout << ans;
    return 0;
}