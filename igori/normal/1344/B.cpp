const int N = 400005;
const int LG = 21;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long long INFLL = 1e18;

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <time.h>
#include <unordered_set>
#include <bitset>
#include <deque>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second
#define re return
#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " " << #x << " " << x << endl
#define ln cerr << __LINE__ << endl
#else
#define dbg(x) void(0)
#define ln void(0)
#endif // LOCAL

int cx[4] = {-1, 0, 1, 0};
int cy[4] = {0, -1, 0, 1};

ll inq(ll x, ll y)
{
    if (!y) re 1 % MOD;
    ll l = inq(x, y / 2);
    if (y % 2) re l * l % MOD * x % MOD;
    re l * l % MOD;
}

ll rev(ll x)
{
    return inq(x, MOD - 2);
}

bool __precomputed_combinatorics = 0;
vector<ll> __fact, __ufact, __rev;

void __precompute_combinatorics()
{
    __precomputed_combinatorics = 1;
    __fact.resize(N);
    __ufact.resize(N);
    __rev.resize(N);
    __rev[1] = 1;
    for (int i = 2; i < N; i++) __rev[i] = MOD - __rev[MOD % i] * (MOD / i) % MOD;
    __fact[0] = 1, __ufact[0] = 1;
    for (int i = 1; i < N; i++) __fact[i] = __fact[i - 1] * i % MOD, __ufact[i] = __ufact[i - 1] * __rev[i] % MOD;
}

ll fact(int x)
{
    if (!__precomputed_combinatorics) __precompute_combinatorics();
    return __fact[x];
}

ll cnk(int n, int k)
{
    if (!__precomputed_combinatorics) __precompute_combinatorics();
    return __fact[n] * __ufact[n - k] % MOD * __ufact[k] % MOD;
}

int n, m;
string s[N];
int a[2000][2000];

int ok(int a, int b)
{
    return 0 <= a && a < n && 0 <= b && b < m;
}

signed main()
{
    srand(time(NULL));
    #ifdef ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // ONLINE_JUDGE
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int go1 = 0, go2 = 0;
    for (int i = 0; i < n; i++)
    {
        int si1 = 0, si2 = 0;
        for (int j = 0; j < m; j++)
        {
            if ((j == 0 || s[i][j - 1] == '.') && s[i][j] == '#') si1++;
            if ((j + 1 == m || s[i][j + 1] == '.') && s[i][j] == '#') si2++;
        }
        if (si1 == 1 && si2 == 1)
        {
            continue;
        }
        if (si1 == 0 && si2 == 0)
        {
            go1++;
            continue;
        }
        cout << -1, exit(0);
    }
    for (int j = 0; j < m; j++)
    {
        int si1 = 0, si2 = 0;
        for (int i = 0; i < n; i++)
        {
            if ((i == 0 || s[i - 1][j] == '.') && s[i][j] == '#') si1++;
            if ((i + 1 == n || s[i + 1][j] == '.') && s[i][j] == '#') si2++;
        }
        if (si1 == 1 && si2 == 1)
        {
            continue;
        }
        if (si1 == 0 && si2 == 0)
        {
            go2++;
            continue;
        }
        cout << -1, exit(0);
    }
    if (go1 && !go2) cout << -1, exit(0);
    if (!go1 && go2) cout << -1, exit(0);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '#' && a[i][j] == 0)
            {
                cnt++;
                vector<pair<int, int> > q = {{i, j}};
                a[i][j] = 1;
                for (int i = 0; i < q.size(); i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        int nx = q[i].first + cx[j];
                        int ny = q[i].second + cy[j];
                        if (ok(nx, ny) && a[nx][ny] == 0 && s[nx][ny] == '#')
                        {
                            a[nx][ny] = 1;
                            q.push_back({nx, ny});
                        }
                    }
                }
            }
        }
    }
    cout << cnt;
}

/* Note:
Check constants at the beginning of the code.
N is set to 4e5 but be careful in problems with large constant factor.
Check corner cases.
No def int long long for now.
*/