const int N = 4e5;
const int LG = 21;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;

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

void __fast_IO()
{
    #ifdef ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // ONLINE_JUDGE
}

//##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**
//##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**##**

int n, x;

struct STree{
    vector<ll> tree;
    vector<ll> push;
    STree(int _n)
    {
        tree.resize(4 * _n);
        push.resize(4 * _n);
    }
    void Push(int V)
    {
        tree[2 * V + 1] += push[V];
        push[2 * V + 1] += push[V];
        tree[2 * V + 2] += push[V];
        push[2 * V + 2] += push[V];
        push[V] = 0;
    }
    void Add(int l, int r, ll val, int L = 0, int R = n + 2, int V = 0)
    {
        if (r <= L || R <= l) return;
        if (l <= L && R <= r)
        {
            tree[V] += val;
            push[V] += val;
            return;
        }
        int M = (L + R) / 2;
        Push(V);
        Add(l, r, val, L, M, 2 * V + 1);
        Add(l, r, val, M, R, 2 * V + 2);
        tree[V] = max(tree[2 * V + 1], tree[2 * V + 2]);
    }
    ll Max(int l, int r, int L = 0, int R = n + 2, int V = 0)
    {
        if (r <= L || R <= l)
        {
            return 0;
        }
        if (l <= L && R <= r)
        {
            return tree[V];
        }
        int M = (L + R) / 2;
        Push(V);
        return max(Max(l, r, L, M, 2 * V + 1), Max(l, r, M, R, 2 * V + 2));
    }
};

vector<ll> solve(vector<ll> values)
{
    ll pref = 0;
    ll minpref = 0;
    vector<ll> opt(values.size());
    for (int i = 0; i < values.size(); i++)
    {
        pref += values[i];
        if (pref < minpref) minpref = pref;
        opt[i] = pref - minpref;
    }
    STree A(values.size());
    for (int i = 0; i < opt.size(); i++)
    {
        A.Add(i, i + 1, opt[i]);
    }
    vector<ll> res(values.size());
    for (int i = 0; i < opt.size(); i++)
    {
        A.Add(0, i, values[i] * x);
        res[i] = A.Max(0, i + 1);
    }
    return res;
}

signed main()
{
    __fast_IO();
    cin >> n >> x;
    vector<ll> a(n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<ll> f = solve(a);
    reverse(all(a));
    vector<ll> r = solve(a);
    reverse(all(r));
    ll ans = 0;
    for (int i = 0; i + 1 < a.size(); i++)
    {
        ans = max(ans, f[i] + r[i + 1]);
    }
    cout << ans;
}

/* Note:
Check constants at the beginning of the code.
N is set to 4e5 but be careful in problems with large constant factor.
Check corner cases.
No def int long long for now.
*/