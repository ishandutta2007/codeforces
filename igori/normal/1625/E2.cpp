const long long MOD = 998244353;
const long long INF = 1e9 + 10;
const long long INFLL = 1e18;

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef complex<double> cd;

#define forn(i, n) for (int i = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second
#define re return
#define pb push_back
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
string Yes[2] = {"No\n", "Yes\n"};
string YES[2] = {"NO\n", "YES\n"};
string Possible[2] = {"Impossible\n", "Possible\n"};
string POSSIBLE[2] = {"IMPOSSIBLE\n", "POSSIBLE\n"};

#define ok(x, n) (0 <= (x) && (x) < (n))
#define withBit(mask, i) ((mask & (1 << i)) > 0)

ll log10(ll x)
{
    if (x < 10) re 1;
    re 1 + log10(x / 10);
}

ll ds(ll x)
{
    if (x < 10) return x;
    re x % 10 + ds(x / 10);
}

double sqr(double x)
{
    return x * x;
}

bool inmask(int bit, int mask)
{
    return (mask & (1 << bit)) > 0;
}

void Del(vector<int> &v, int pos)
{
    swap(v[pos], v[v.size() - 1]);
    v.pop_back();
}

long long g(vector<long long> &p, int pos)
{
    if (ok(pos, p.size())) return p[pos];
    if (pos < 0 || p.size() == 0) return 0;
    return p.back();
}

int g(vector<int> &p, int pos)
{
    if (ok(pos, p.size())) return p[pos];
    if (pos < 0 || p.size() == 0) return 0;
    return p.back();
}

ll binpow(ll x, ll y)
{
    if (!y) re 1 % MOD;
    ll l = binpow(x, y / 2);
    if (y % 2) re l * l % MOD * x % MOD;
    re l * l % MOD;
}

ll rev(ll x)
{
    return binpow(x, MOD - 2);
}

int __precomputed_combinatorics = 0;
vector<ll> __fact, __ufact, __rev;

inline void __precompute_combinatorics(int __n)
{
    if (__n < 2) __n = 2;
    if (__precomputed_combinatorics >= __n)
        return;
    __fact.resize(__n);
    __ufact.resize(__n);
    __rev.resize(__n);
    __rev[1] = 1;
    for (int i = max(2, __precomputed_combinatorics); i < __n; i++)
        __rev[i] = MOD - __rev[MOD % i] * (MOD / i) % MOD;
    __fact[0] = 1, __ufact[0] = 1;
    for (int i = max(1, __precomputed_combinatorics); i < __n; i++)
        __fact[i] = __fact[i - 1] * i % MOD, __ufact[i] = __ufact[i - 1] * __rev[i] % MOD;
    __precomputed_combinatorics = __n;
}

ll fact(int x)
{
    if (__precomputed_combinatorics <= x)
        __precompute_combinatorics(x + 1);
    return __fact[x];
}

ll cnk(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    if (__precomputed_combinatorics <= n)
        __precompute_combinatorics(n + 1);
    return __fact[n] * __ufact[n - k] % MOD * __ufact[k] % MOD;
}

template<typename T> istream& operator>>(istream& in, vector<T>& a)
{
    for (int i = 0; i < a.size(); i++)
        in >> a[i];
    return in;
}

template<typename T> ostream& operator<<(ostream& out, const vector<T>& a)
{
    for (auto e : a)
    {
        out << e << " ";
        if (typeid(T) != typeid(int) && typeid(T) != typeid(ll))
            out << "\n";
    }
    return out;
}

template<class T> void add(int pos, T x, vector<T> &fenw)
{
    // Performs add query on Fenwick tree
    //
    // Tested on the following problem:
    // https://atcoder.jp/contests/practice2/tasks/practice2_b
    //
    while (pos < (int)fenw.size())
    {
        fenw[pos] += x;
        pos |= (pos + 1);
    }
}

template<class T> T get(int pos, vector<T> &fenw)
{
    // Performs get query on Fenwick tree
    //
    // Tested on the following problem:
    // https://atcoder.jp/contests/practice2/tasks/practice2_b
    //
    ll res = 0;
    while (pos >= 0)
    {
        res += fenw[pos];
        pos = (pos & (pos + 1)) - 1;
    }
    return res;
}

void solve(int v, int d, vvi &g, vll &dp, vi &sz, vector<pii> &pos, vi &szv)
{
    szv[v] = g[v].size();
    for (auto u : g[v]) solve(u, d + 1, g, dp, sz, pos, szv);
    dp[v] += 1ll + 1ll * (g[v].size() - 1) * g[v].size() / 2;
    pos[v] = {d, sz[d]};
    sz[d]++;
}

void dfs(int v, vvi &g, vll &dp, vll &euler, vi &L, vi &R)
{
    L[v] = euler.size();
    R[v] = euler.size();
    euler.push_back(dp[v]);
    for (auto u : g[v]) dfs(u, g, dp, euler, L, R), R[v] = R[u];
}

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int Lminb = 0;
    int x = 0;
    for (int i = 0; i < s.size(); i++)
        x += s[i] == '(' ? 1 : -1, Lminb = min(Lminb, x);

    Lminb *= -1;
    x = 0;
    s = string(Lminb, '(') + s;

    int Rminb = 0;
    for (int i = s.size() - 1; i >= 0; i--)
        x += s[i] == ')' ? 1 : -1, Rminb = min(Rminb, x);

    Rminb *= -1;
    s = s + string(Rminb, ')');

    s = "(" + s + ")";

    cerr << s << "\n";

    int C = 0;
    vector<int> st;
    vector<int> id(s.size());
    vector<vector<int> > g(s.size() / 2);
    vector<int> sz(s.size(), 1);
    vector<int> szv(s.size());
    vector<vi> klen(s.size());
    vector<pii> pos(s.size() / 2);
    vector<int> papa(s.size() / 2);

    vector<ll> euler;
    vector<int> L(s.size() / 2), R(s.size() / 2);

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push_back(C);
            id[i] = C;
            C++;
        }
        else
        {
            id[i] = st.back();
            st.pop_back();
            if (st.size())
            {
                g[st.back()].push_back(id[i]);
                sz[st.back()]++;
                papa[id[i]] = st.back();
            }
        }
    }

    vector<ll> dp(s.size() / 2);
    solve(0, 0, g, dp, sz, pos, szv);
    dfs(0, g, dp, euler, L, R);

    ln;

    vector<ll> fenw(euler.size());
    for (int i = 0; i < euler.size(); i++)
        add(i, euler[i], fenw);

    cerr << euler << "\n";
    ln;

    for (int i = 0; i < s.size(); i++)
    {
        klen[i] = vector<int>(sz[i] + 1);
        for (int j = 1; j < sz[i]; j++)
        {
            add(j, 1, klen[i]);
        }
    }

    ln;

    for (int i = 0; i < q; i++)
    {
        int t, l, r;
        cin >> t >> l >> r;
        l += Lminb, r += Lminb;
        if (t == 2)
        {
            int idl = id[l], idr = id[r];
            int len = get(pos[idr].second, klen[pos[idr].first]) - get(pos[idl].second - 1, klen[pos[idl].first]);
            dbg(len);
            int cntdel = pos[idr].second - pos[idl].second + 1 - len;
            cout << 1ll * (len - 1) * len / 2 + get(R[idr], fenw) - get(L[idl] - 1, fenw) - cntdel << "\n";
        }
        else
        {
            int Id = id[l];
            int p = papa[Id];
            int x = szv[p];
            szv[p]--;
            add(pos[Id].second, -1, klen[pos[Id].first]);
            add(L[p], -1ll * x, fenw);
            dbg(L[p]), dbg(x);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifdef LOCAL
    cout << "\n";
    #endif // LOCAL

    int t = 1;
    #ifdef tests
    cin >> t;
    #endif // tests
    while (t--)
    {
        solve();
    }
}