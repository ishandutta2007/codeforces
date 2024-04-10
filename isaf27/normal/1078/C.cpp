/*
    Author: isaf27 (Ivan Safonov)
*/

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0)
#define nul point(0, 0)
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; for (int i = 0; i < number; i++) solve()
#define solve_system_scanf int number; scanf("%d", &number); for (int i = 0; i < number; i++) solve()

//permanent constants
const ld pi = acos(-1.0);
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const ll prost = 239;
const int two = 2;
const int th = 3;
const ll MOD = 998244353; //1e9 + 7;
const ll MOD2 = MOD * MOD;
const int BIG = 1e9 + 239;
const int alf = 26;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxb[4] = {-1, 1, 1, -1};
const int dyb[4] = {-1, 1, -1, 1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dig = 10;
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const ll bt = 62;

//easy functions
template< typename T >
inline T gcd(T a, T b)
{
    while (a)
    {
        b %= a;
        swap(a, b);
    }
    return b;
}
template< typename T >
inline T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
inline bool is_down(char x) { return ('a' <= x && x <= 'z'); }
inline bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
inline bool is_digit(char x) { return ('0' <= x && x <= '9'); }

//random
//mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rnd(239);

//constants
const int M = 3e5 + 239;
const int N = 2e3 + 239;
const int L = 103;
const int T = (1 << 18);
const int B = trunc(sqrt(M)) + 1;
const int X = 1e4 + 239;

ll dp[two][M];
int n, kol;
vector<int> v[M];
ll pref[M], suf[M], now, fl[M];

void dfs(int p, int pr)
{
    for (int i : v[p])
        if (i != pr)
            dfs(i, p);
    dp[0][p] = 1;
    for (int i : v[p])
        if (i != pr)
            dp[0][p] = (dp[0][p] * (dp[0][i] + dp[1][i])) % MOD;
    dp[1][p] = 0;
    kol = 0;
    pref[0] = 1;
    for (int i : v[p])
        if (i != pr)
        {
            kol++;
            pref[kol] = (pref[kol - 1] * (2LL * dp[1][i] + dp[0][i])) % MOD;
        }
    reverse(v[p].begin(), v[p].end());
    suf[kol] = 1;
    for (int i : v[p])
        if (i != pr)
        {
            kol--;
            suf[kol] = (suf[kol + 1] * (2LL * dp[1][i] + dp[0][i])) % MOD;
        }
    reverse(v[p].begin(), v[p].end());
    for (int i : v[p])
        if (i != pr)
        {
            now = (pref[kol] * suf[kol + 1]) % MOD;
            kol++;
            now = (now * fl[i]) % MOD;
            dp[1][p] = (dp[1][p] + now) % MOD;
        }
    fl[p] = pref[kol];
    //cerr << (p + 1) << " " << dp[0][p] << " " << dp[1][p] << "!!\n";
}

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int s, f;
        cin >> s >> f;
        s--, f--;
        v[s].push_back(f);
        v[f].push_back(s);
    }
    dfs(0, -1);
    cout << (dp[0][0] + dp[1][0]) % MOD;
    return 0;
}