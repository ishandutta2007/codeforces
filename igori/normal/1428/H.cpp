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

int draw(int m, vector<int> state, int silent_mode = 1)
{
    int n = state.size();
    vector<string> s(n, string(n * m, '.'));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            s[n - 1 - i][(state[i] + j) % (n * m)] = '#';
    }
    if (silent_mode == 0)
    {
        for (int i = 0; i < n; i++)
        {
            cout << s[i] << endl;
        }
    }
    int cnt = 0;
    for (int j = 0; j < n * m; j++)
    {
        int f = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i][j] == '#')
                f = 1;
        }
        if (f == 0)
            cnt++;
    }
    if (silent_mode == 0)
    {
        cout << cnt << endl;
    }
    return cnt;
}

int solve(int n, int m, vector<int> state)
{
    int asks = 0;
    if (state.size() != 0) draw(m, state);

    vector<int> lst;

    auto ask = [&](int id, int dir)
    {
        asks++;
        if (state.size() == 0)
        {
            cout << "? " << id << " " << dir << endl;
            int x;
            cin >> x;
            lst.push_back(x);
            return x;
        }
        state[id] = (state[id] + n * m + dir) % (n * m);
        int x = draw(m, state);
        lst.push_back(x);
        return x;
    };

    vector<int> pos(n, -1);
    pos[0] = 0;

    auto recognize = [&](int pos0)
    {
        vector<int> exp;
        for (int i = 1; i < n; i++) if (pos[i] == -1) exp.push_back(i);

        //cout << "START SEARCH" << endl;
        int L = 0, R = exp.size();
        int fl = 0;
        while (L + 1 < R)
        {
            int M = (L + R) / 2;
            int t = 0;
            if (fl == 0)
            {
                for (int i = L; i < M; i++) ask(exp[i], -1);
                int cur = lst.back();
                if (ask(0, -1) >= cur)
                    t = 1;
                ask(0, 1);
                if (t)
                {
                    fl = 1;
                    R = M;
                }
                else
                {
                    fl = 0;
                    for (int i = L; i < M; i++) ask(exp[i], 1);
                    L = M;
                }
            }
            else
            {
                for (int i = M; i < R; i++) ask(exp[i], 1);
                int cur = lst.back();
                if (ask(0, -1) >= cur)
                    t = 1;
                ask(0, 1);
                if (t)
                {
                    fl = 1;
                    R = M;
                }
                else
                {
                    fl = 0;
                    L = M;
                }
            }
        }
        if (fl) ask(exp[L], 1);
        pos[exp[L]] = pos0;
        //cout << "FOUND HERE " << exp[L] << " " << pos0 << endl;
        return exp[L];
    };

    ask(0, 1);
    ask(0, 1);
    ask(0, 1);
    while (*min_element(all(pos)) == -1)
    {
        int val = ask(0, 1);
        pos[0] = (pos[0] + 1) % (n * m);
        //cout << "brr " << val << endl;

        int sz = lst.size();
        if (lst[sz - 3] < lst[sz - 2] && lst[sz - 2] >= lst[sz - 1])
        {
            ask(0, -1);
            pos[0] = (pos[0] + n * m - 1) % (n * m);

            int e = recognize(pos[0]);

            for (int j = 0; j < m + 1; j++)
                ask(e, -1), pos[e] = (pos[e] + n * m - 1) % (n * m);
            ask(0, -1);
            pos[0] = (pos[0] + n * m - 1) % (n * m);
        }
    }
    for (int i = n - 1; i >= 0; i--) pos[i] = (pos[i] + n * m - pos[0]) % (n * m);
    if (state.size()) for (int i = n - 1; i >= 0; i--) state[i] = (state[i] + n * m - state[0]) % (n * m);

    cout << "! ";
    for (int i = 1; i < n; i++) cout << pos[i] << " "; cout << endl;

    if (state.size() != 0)
    {
        for (int i = 0; i < n; i++) cout << state[i] << " "; cout << endl;
        assert(pos == state);
    }
    return asks;
}

void solve()
{
    int n, m; cin >> n >> m; solve(n, m, {}); return;

    int m_asks = 0, t_asks = 0;
    for (int T = 0; T < 125; T++)
    {
        int n = 100, m = 20;
        if (T < 100) n = 10, m = 10;
        vector<int> state(n);
        forn(i, n) state[i] = rand() % (n * m);
        state[0] = 0;
        int asks = solve(n, m, state);
        m_asks = max(m_asks, asks);
        t_asks += asks;
    }
    cout << m_asks << " " << t_asks << endl;
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