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

struct Edge{
    int v, u, w;
};

struct Case{
    int n, m, a, b;
    vector<Edge> g;
};

pair<ll, string> solve_bruteforce(Case C)
{
    int n = C.n, m = C.m;
    ll opt = 1e18;
    string ans;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (int sub = mask; ; sub = (sub - 1) & mask)
        {
            if (withBit(sub, C.a) && withBit(mask - sub, C.b))
            {
                ll score = 0;
                string z(n, '.');
                for (int i = 0; i < n; i++)
                {
                    if (withBit(sub, i)) z[i] = 'A';
                    else if (withBit(mask - sub, i)) z[i] = 'B';
                    else z[i] = 'C';
                }
                for (int i = 0; i < m; i++)
                {
                    if (z[C.g[i].u] == 'A' && z[C.g[i].v] == 'A') score += 2 * C.g[i].w;
                    if (z[C.g[i].u] == 'B' && z[C.g[i].v] == 'B') score += 2 * C.g[i].w;
                    if (z[C.g[i].u] == 'A' && z[C.g[i].v] == 'C') score += C.g[i].w;
                    if (z[C.g[i].u] == 'C' && z[C.g[i].v] == 'A') score += C.g[i].w;
                    if (z[C.g[i].u] == 'B' && z[C.g[i].v] == 'C') score += C.g[i].w;
                    if (z[C.g[i].u] == 'C' && z[C.g[i].v] == 'B') score += C.g[i].w;
                }
                if (score < opt)
                {
                    opt = score;
                    ans = z;
                }
            }
            if (sub == 0)
                break;
        }
    }
    return {opt, ans};
}

struct maxflow{
    vector<vector<int> > g;
    vector<int> fr, to;
    vector<long long> cap, fl;
    vector<int> dist;
    vector<int> pnt;
    int S, T;
    maxflow(int n, int _s, int _t)
    {
        g.resize(n);
        pnt.resize(n);
        dist.resize(n);
        S = _s;
        T = _t;
    }
    void add_edge(int f, int t, long long c, int both_directions)
    {
        //cout << f << " " << t << " " << c << endl;
        g[f].push_back(fr.size());
        fr.push_back(f), to.push_back(t), cap.push_back(c), fl.push_back(0);
        //cout << "cap -> " << cap.back() << endl;

        g[t].push_back(fr.size());
        fr.push_back(t), to.push_back(f), cap.push_back(c * both_directions), fl.push_back(0);
        //cout << "cap <- " << cap.back() << endl;
    }
    long long dfs(int v, long long want)
    {
        if (v == T || want == 0) return want;
        for (; pnt[v] < g[v].size(); pnt[v]++)
        {
            int eid = g[v][pnt[v]];
            if (dist[to[eid]] == dist[v] + 1 && fl[eid] < cap[eid])
            {
                long long can = cap[eid] - fl[eid];
                long long res = dfs(to[eid], min(want, can));
                if (res > 0)
                {
                    fl[eid] += res;
                    fl[eid ^ 1] -= res;
                    return res;
                }
            }
        }
        return 0;
    }
    long long flow()
    {
        fill(all(dist), INF);
        fill(all(pnt), 0);
        dist[S] = 0;
        vector<int> q = {S};
        for (int i = 0; i < q.size(); i++)
        {
            for (auto eid : g[q[i]])
            {
                int To = to[eid];
                if (dist[To] == INF && fl[eid] < cap[eid])
                {
                    dist[To] = dist[q[i]] + 1;
                    q.push_back(To);
                }
            }
        }
        if (dist[T] == INFLL)
            return 0;
        long long z = dfs(S, INFLL);
        long long res = 0;
        while (z > 0)
        {
            res += z;
            z = dfs(S, INFLL);
        }
        return res;
    }
    long long calc()
    {
        long long z = flow();
        long long res = 0;
        while (z > 0)
        {
            res += z;
            z = flow();
        }
        return res;
    }
};

pair<ll, string> solve(Case C)
{
    int n = C.n, m = C.m;
    maxflow G(2 * n + 2, 2 * n, 2 * n + 1);
    for (int i = 0; i < m; i++)
    {
        G.add_edge(2 * C.g[i].u, 2 * C.g[i].v + 1, C.g[i].w, 1);
        G.add_edge(2 * C.g[i].u + 1, 2 * C.g[i].v, C.g[i].w, 1);
    }
    G.add_edge(2 * n, 2 * C.a, INFLL, 0);
    G.add_edge(2 * n, 2 * C.b + 1, INFLL, 0);
    G.add_edge(2 * C.a + 1, 2 * n + 1, INFLL, 0);
    G.add_edge(2 * C.b, 2 * n + 1, INFLL, 0);
    long long res = G.calc();
    G.calc();
    vector<int> color(n);
    for (int i = 0; i < n; i++)
    {
        if (G.dist[2 * i] != INF) color[i] |= (1 << 0);
        if (G.dist[2 * i + 1] != INF) color[i] |= (1 << 1);
    }
    string ans(n, 'C');
    for (int i = 0; i < n; i++)
    {
        if (color[i] == 1) ans[i] = 'A';
        if (color[i] == 2) ans[i] = 'B';
    }
    return {res, ans};
}

Case gen()
{
    Case C;
    int n = 10;
    int m = 15;
    C.n = n;
    C.m = m;
    C.a = rand() % n;
    C.b = rand() % n;
    while (C.b == C.a) C.b = rand() % n;
    //cout << C.a << " " << C.b << "\n";
    vector g(n, vector(n, 0));
    for (int i = 0; i < m; i++)
    {
        int f = rand() % n, t = rand() % n;
        while (f == t || g[f][t] == 1)
        {
            f = rand() % n, t = rand() % n;
        }
        int w = rand() % 20;
        g[f][t] = 1, g[t][f] = 1;
        C.g.push_back({f, t, w});
        //cout << f << " " << t << " " << w << "\n";
    }
    //cout << "\n";
    return C;
}

Case read()
{
    Case C;
    cin >> C.n >> C.m;
    cin >> C.a >> C.b;
    C.a--, C.b--;
    C.g = vector<Edge>(C.m);
    for (int i = 0; i < C.m; i++)
    {
        cin >> C.g[i].u >> C.g[i].v >> C.g[i].w;
        C.g[i].u--;
        C.g[i].v--;
    }
    return C;
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
        Case C = read();
        pair<ll, string> x = solve(C);
        //pair<ll, string> y = solve_bruteforce(C);
        cout << x.first << " " << x.second << endl;
        //cout << y.first << " " << y.second << endl;
        //assert(x.first == y.first);
    }
}