const int N = 208001;
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

#define int long long
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

int n, m, t;
int ok(int i, int j)
{
    return 0 <= i && i < n && 0 <= j && j < m;
}
int dist[1010][1010];

signed main()
{
    srand(time(NULL));
    //#ifdef ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    //#endif // ONLINE_JUDGE
    cin >> n >> m >> t;
    vector<string> s(n);
    forn(i, n)
    {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) forn(j, m) dist[i][j] = INF;
    int chinese_board = 1;
    vector<pair<int, int> > q;
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < m; b++)
        {
            int tr = 1;
            for (int k = 0; k < 4; k++)
            {
                if (ok(a + cx[k], b + cy[k]) && s[a + cx[k]][b + cy[k]] == s[a][b]) tr = 0;
            }
            if (tr == 0) chinese_board = 0, dist[a][b] = 0, q.push_back({a, b});
        }
    }
    if (chinese_board)
    {
        while (t--)
        {
            int x, y, tm;
            cin >> x >> y >> tm;
            x--, y--;
            cout << s[x][y] << "\n";
        }
        return 0;
    }
    for (int i = 0; i < q.size(); i++)
    {
        int x = q[i].first, y = q[i].second;
        for (int k = 0; k < 4; k++)
        {
            if (ok(x + cx[k], y + cy[k]) && dist[x + cx[k]][y + cy[k]] == INF)
            {
                dist[x + cx[k]][y + cy[k]] = dist[x][y] + 1;
                q.push_back({x + cx[k], y + cy[k]});
            }
        }
    }
    while (t--)
    {
        int x, y, tm;
        cin >> x >> y >> tm;
        x--, y--;
        if (tm <= dist[x][y])
        {
            cout << s[x][y] << "\n";
        }
        else
        {
            int p = (tm - dist[x][y]) % 2;
            if (p % 2 == 1) cout << (char)('1' + '0' - s[x][y]) << "\n";
            else cout << s[x][y] << "\n";
        }
    }
}

/* Note:
Check constants at the beginning of the code.
N is set to 4e5 but be careful in problems with large constant factor.
Check corner cases.
No def int long long for now.
*/