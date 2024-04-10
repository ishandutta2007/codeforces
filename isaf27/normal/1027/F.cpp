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
const int MOD = 998244353; //1e9 + 7;
const ll MOD2 = MOD * MOD;
const int BIG = 2e9 + 239;
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
const int X = 1e6 + 239;
const int Y = 2e6 + 239;

bool used[Y];
int n, a[X], b[X], m, v[Y], mx, mx2, sum, num;
vector<int> g[Y];

void dfs(int p)
{
    used[p] = true;
    if (mx < p)
    {
        mx2 = mx;
        mx = p;
    }
    else if (mx2 < p)
        mx2 = p;
    sum += g[p].size();
    num++;
    for (int i : g[p])
        if (!used[i])
            dfs(i);
}

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fastIO;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    for (int i = 0; i < n; i++)
    {
        v[i] = a[i];
        v[i + n] = b[i];
    }
    sort(v, v + (2 * n));
    m = (unique(v, v + (2 * n)) - v);
    for (int i = 0; i < n; i++)
    {
        a[i] = lower_bound(v, v + m, a[i]) - v;
        b[i] = lower_bound(v, v + m, b[i]) - v;
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    memset(used, 0, sizeof(used));
    int ans = 0;
    for (int i = 0; i < m; i++)
        if (!used[i])
        {
            mx = -1;
            mx2 = -1;
            sum = 0;
            num = 0;
            dfs(i);
            sum /= 2;
            if (sum > num)
            {
                cout << "-1";
                return 0;
            }
            if (sum == num) ans = max(ans, mx);
            else ans = max(ans, mx2);
        }
    cout << v[ans];
    return 0;
}