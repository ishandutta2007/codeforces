const int N = 1400005;
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

ll n, k;

ll f(ll n, ll k)
{
    return inq(k, n / 2) * (n % 2 ? k : 1) % MOD;
}

string s;

int sp[20][N];
int H[N];

int gmin(int l, int r)
{
    int len = r - l;
    int h = H[len];
    return min(sp[h][l], sp[h][r - (1 << h)]);
}

vector<int> pos[2 * N];

signed main()
{
    H[3] = 1;
    for (int i = 4; i < N; i++)
    {
        H[i] += H[i - 1];
        if (((i - 1) & i) == 0) H[i + 1]++;
    }
    srand(time(NULL));
    #ifdef ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // ONLINE_JUDGE
    cin >> s;
    int bala = 0;
    pos[N].push_back(-1);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(') bala++;
        else bala--;
        sp[0][i] = bala;
        pos[N + bala].push_back(i);
    }
    for (int j = 1; j < 20; j++)
    {
        for (int i = 0; i + (1 << j) - 1 < s.size(); i++)
        {
            sp[j][i] = gmin(i, i + (1 << j));
        }
    }
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int ss = i ? sp[0][i - 1] : 0;
        int L = 0, R = pos[N + ss].size();
        while (L + 1 < R)
        {
            int M = (L + R) / 2;
            if (pos[N + ss][M] <= i) L = M;
            else if (gmin(i, pos[N + ss][M]) >= ss) L = M;
            else R = M;
        }
        ans = max(ans, pos[N + ss][L] - i + 1);
    }
    cout << ans << " ";
    if (ans == 0)
    {
        cout << 1;
        return 0;
    }
    int cnt = 0;
    for (int i = 0; i + ans - 1 < s.size(); i++)
    {
        int ss = i ? sp[0][i - 1] : 0;
        if (sp[0][i + ans - 1] == ss)
        {
            if (gmin(i, i + ans) >= ss) cnt++;
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