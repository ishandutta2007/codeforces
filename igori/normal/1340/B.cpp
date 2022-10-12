const int N = 1405949; // 405949 is my favorite number, but it's less than 5e5
const int LG = 21;
const int MOD = 1e9 + 7;
const int INF = 1e9;

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

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " " << #x << " " << x << endl
#define ln cerr << __LINE__ << endl
#else
#define dbg(x) void(0)
#define ln void(0)
#endif // LOCAL

ll inq(ll x, ll y)
{
    if (!y) re 1 % MOD;
    ll l = inq(x, y / 2);
    if (y % 2) re l * l % MOD * x % MOD;
    re l * l % MOD;
}

ll inv(ll x)
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

int n, k;
string d[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
string s[3000];
int cost[3000][10];

int into(string s, string t)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0' && t[i] == '1') return -1;
    }
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != t[i]) cnt++;
    }
    return cnt;
}

bitset<2001> dp[2001];

signed main()
{
    srand(time(NULL));
    #ifdef ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // ONLINE_JUDGE
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int x = 0; x < 10; x++)
        {
            cost[i][x] = into(d[x], s[i]);
        }
    }
    dp[n][0] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int dig = 0; dig < 10; dig++)
        {
            if (cost[i][dig] != -1)
            {
                dp[i] |= (dp[i + 1] << cost[i][dig]);
            }
        }
    }
    if (dp[0][k] == 0)
    {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int place = 9; place >= 0; place--)
        {
            if (cost[i][place] != -1 && cost[i][place] <= k && dp[i + 1][k - cost[i][place]] == 1)
            {
                cout << place;
                k -= cost[i][place];
                break;
            }
        }
    }
}

/* Note:
Check constants at the beginning of the code.
N is set to 1.4e6 but be careful in problems with large constant factor.
Check corner cases.
No def int long long for now.
*/