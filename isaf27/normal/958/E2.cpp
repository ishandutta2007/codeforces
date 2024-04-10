//isaf27

#pragma GCC optimize("O3")
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
const int N = 5 * 1e3 + 239;
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

// Code starts here

int n, k, a[M], dp[two][two][N];
int r, b[M], now[M];

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    cin >> k >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    vector<pair<int, int> > v;
    for (int i = 1; i < n; i++)
        v.push_back(make_pair(a[i] - a[i - 1], i - 1));
    sort(v.begin(), v.end());
    memset(now, -1, sizeof(now));
    for (int i = 0; i < min((int)v.size(), 4 * k); i++)
    {
        int p = v[i].second;
        int x = v[i].first;
        now[p] = x;
        if (p != 0 && now[p - 1] == -1)
            now[p - 1] = BIG;
        if (p != n - 2 && now[p + 1] == -1)
            now[p + 1] = BIG;
    }
    int r = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (now[i] == -1) continue;
        b[r] = now[i];
        r++;
    }
    for (int d = 0; d < 2; d++)
        for (int x = 0; x <= k; x++)
            dp[0][d][x] = BIG;
    dp[0][0][0] = 0;
    for (int i = 1; i < r + 1; i++)
    {
        for (int x = 0; x <= k; x++)
            dp[i & 1][0][x] = min(dp[(i - 1) & 1][0][x], dp[(i - 1) & 1][1][x]);
        int pl = b[i - 1];
        for (int x = 1; x <= k; x++)
            dp[i & 1][1][x] = dp[(i - 1) & 1][0][x - 1] + pl;
    }
    cout << min(dp[r & 1][0][k], dp[r & 1][1][k]);
    return 0;
}