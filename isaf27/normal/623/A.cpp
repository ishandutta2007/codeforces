/*
    Author: isaf27 (Ivan Safonov)
*/

//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0)
#define nul point(0, 0)
#define str_to_int(stroka) atoi(stroka.c_str())
#define str_to_ll(stroka) atoll(stroka.c_str())
#define str_to_double(stroka) atof(stroka.c_str())
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; for (int i = 0; i < number; i++) solve()
#define solve_system_scanf int number; scanf("%d", &number); for (int i = 0; i < number; i++) solve()

//permanent constants
const ld pi = 3.141592653589793238462643383279;
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const ll prost = 239;
const int two = 2;
const int th = 3;
const ll MOD = 1e9 + 7; // 998244353
const ll MOD2 = MOD * MOD;
const int BIG = 1e9 + 239;
const int alf = 26;
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
const int fr = 4;

//easy functions
template< typename T >
inline T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template< typename T >
inline T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
inline bool is_down(char x) { return ('a' <= x && x <= 'z'); }
inline bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
inline bool is_digit(char x) { return ('0' <= x && x <= '9'); }
inline int power(ll a, int b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

//random
mt19937 rnd(239);

//constants
const int M = 2 * 1e5 + 239;
const int N = 2 * 1e3 + 239;
const int L = 19;
const int T = (1 << 20);
const int B = trunc(sqrt(M)) + 1;
const int X = 510;

bool has[X][X], used[X];
int n, m;
string s;

void over()
{
    cout << "No\n";
    exit(0);
}

void dfs(int i, int c)
{
    used[i] = true;
    if (c == 0) s[i] = 'a';
    else s[i] = 'c';
    for (int x = 0; x < n; x++)
        if (has[i][x])
        {
            if (used[x])
            {
                if (s[i] == s[x]) over();
                continue;
            }
            dfs(x, 1 - c);
        }
}

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fastIO;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            has[i][j] = true;
    for (int i = 0; i < n; i++)
        has[i][i] = false;
    for (int x = 0; x < m; x++)
    {
        int s, f;
        cin >> s >> f;
        s--, f--;
        has[s][f] = false;
        has[f][s] = false;
    }
    for (int i = 0; i < n; i++)
        s += 'b';
    for (int i = 0; i < n; i++)
        if (!used[i])
        {
            int ans = 0;
            for (int x = 0; x < n; x++)
                ans += has[i][x];
            if (ans == 0) continue;
            dfs(i, 0);
        }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] == 'a' && s[j] == 'c')
            {
                if (!has[i][j])
                    over();
                continue;
            }
            if (s[i] == 'c' && s[j] == 'a')
            {
                if (!has[i][j])
                    over();
                continue;
            }
            if (has[i][j]) over();
        }
    cout << "Yes\n" << s;
    return 0;
}