/*
    Author: isaf27 (Ivan Safonov)
*/

//#pragma GCC optimize("O3")
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
const ll MOD = 1e9 + 7;
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
const int bt = 31;

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
mt19937 rnd(239);

//constants
const int M = 2e5 + 239;
const int N = 1e3 + 600;
const int L = 19;
const int T = (1 << 18);
const int B = trunc(sqrt(M)) + 1;
const int X = 1e4 + 239;

int n, s, m, k, a[N], la[N], ra[N], used[N], dp[N][N], gt[N];
vector<int> v;

inline bool ok(int t)
{
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > t)
            used[i] = -1;
        else
            used[i] = (r++);
    }
    if (r < k) return false;
    int sg = 0;
    for (int i = 0; i < r; i++)
        gt[i] = r;
    for (int i = 0; i < s; i++)
    {
        int lg = -1;
        int rg = -1;
        for (int x = la[i]; x <= ra[i]; x++)
            if (used[x] != -1)
            {
                if (lg == -1) lg = used[x];
                rg = used[x];
            }
        if (lg != -1) sg++;
        for (int x = lg; x <= rg; x++)
            gt[x] = min(gt[x], lg);
    }
    for (int i = 0; i <= sg; i++) dp[0][i] = 0;
    for (int i = 0; i <= r; i++) dp[i][0] = 0;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= sg; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (gt[i - 1] < i) dp[i][j] = max(dp[i][j], dp[gt[i - 1]][j - 1] + i - gt[i - 1]);
        }
    return (dp[r][min(m, sg)] >= k);
}

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(); cout.tie(0);
    cin >> n >> s >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < s; i++)
    {
        cin >> la[i] >> ra[i];
        la[i]--;
        ra[i]--;
    }
    for (int i = 0; i < n; i++)
        v.push_back(a[i]);
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    if (!ok(v.back()))
    {
        cout << "-1";
        return 0;
    }
    int l = -1;
    int r = (int)v.size() - 1;
    while (r - l > 1)
    {
        int h = (l + r) / 2;
        if (ok(v[h]))
            r = h;
        else
            l = h;
    }
    cout << v[r];
    return 0;
}