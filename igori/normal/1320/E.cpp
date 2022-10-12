const int N = 405949; // 405949 is my favorite number, but it's less than 5e5
const int LG = 20;
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

int n;
int k;
int H[N];
vector<int> graph[N];
pair<int, int> sp[LG][N];
int L[N], R[N];
int t = 0;
int depth[N];

void dfs(int v, int p, int d)
{
    depth[v] = d;
    sp[0][t] = {d, v};
    L[v] = R[v] = t;
    t++;
    for (auto u : graph[v]) if (u != p)
    {
        dfs(u, v, d + 1);
        sp[0][t] = {d, v};
        R[v] = t;
        t++;
    }
}

pair<int, int> spmin(int l, int r)
{
    int h = H[r - l + 1];
    return min(sp[h][l], sp[h][r - (1 << h) + 1]);
}

int lca(int v, int u)
{
    return spmin(min(L[v], L[u]), max(R[v], R[u])).second;
}

struct infection{
    int day, id, power, vertex;
};

bool operator < (infection b, infection a)
{
    if (b.day != a.day) return b.day < a.day;
    if (b.id != a.id) return b.id < a.id;
    if (b.power != a.power) return b.power > a.power;
    return b.vertex < a.vertex;
}

bool operator == (infection b, infection a)
{
    return b.day == a.day && b.id == a.id && b.power == a.power && b.vertex == a.vertex;
}

bool operator > (infection b, infection a)
{
    return !(b > a) && !(b == a);
}

signed main()
{
    H[1] = 0, H[2] = 0, H[3] = 1;
    for (int i = 4; i < N; i++)
    {
        H[i] = H[i - 1];
        if (((i - 1) & (i - 2)) == 0) H[i]++;
    }
    #ifdef ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // ONLINE_JUDGE
    cin >> n;
    forn(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0, 0);
    for (int j = 1; j < LG; j++)
    {
        for (int i = 0; i + (1 << j) - 1 < t; i++)
        {
            sp[j][i] = spmin(i, i + (1 << j) - 1);
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int k, m;
        cin >> k >> m;
        vector<pair<int, int> > virus(k);
        vector<int> ask(m);
        for (int i = 0; i < k; i++) cin >> virus[i].first >> virus[i].second;
        for (int i = 0; i < m; i++) cin >> ask[i];
        vector<pair<int, int> > a;
        for (int i = 0; i < k; i++) a.push_back({L[virus[i].first], virus[i].first});
        for (int i = 0; i < m; i++) a.push_back({L[ask[i]], ask[i]});
        vector<pair<int, int> > b = a;
        sort(all(a));
        int x = a[0].second;
        for (int i = 0; i + 1 < a.size(); i++)
        {
            x = lca(a[i].second, a[i + 1].second);
            b.push_back({L[x], x});
        }
        //for (int i = 1; i <= n; i++) b.push_back({L[i], i});
        sort(all(b));
        b.resize(unique(all(b)) - b.begin());
        vector<int> st;
        map<int, vector<pair<int, int> > > g;
        for (int i = 0; i < b.size(); i++)
        {
            while (st.size() && lca(st.back(), b[i].second) != st.back()) st.pop_back();
            if (st.size())
            {
                int x = st.back(), y = b[i].second;
                if (lca(x, y) == x) ; else exit(10403);
                int len = depth[b[i].second] - depth[st.back()];
                g[x].push_back({y, len});
                g[y].push_back({x, len});
            }
            st.push_back(b[i].second);
        }
        set<infection> dj;
        map<int, infection> virus_map;
        for (int i = 0; i < b.size(); i++)
        {
            int v = b[i].second;
            virus_map[v] = {INF, INF, -INF, v};
        }
        for (int i = 0; i < k; i++) virus_map[virus[i].fi] = {0, i, 0, virus[i].fi}, dj.insert({0, i, 0, virus[i].fi});
        while (dj.size())
        {
            auto it = dj.begin();
            dj.erase(it);
            int day = (*it).day;
            int power = (*it).power;
            int v = (*it).vertex;
            int vir = (*it).id;
            for (int i = 0; i < g[v].size(); i++)
            {
                int u = g[v][i].fi;
                int len = g[v][i].se;
                int affect = 0;
                int exday = day;
                int expower = power;
                if (expower >= len)
                {
                    expower = expower - len;
                }
                else
                {
                    len -= (expower + 1);
                    expower = virus[vir].se - 1;
                    exday = day + 1;
                    int steps = len / virus[vir].se;
                    int rem = len % virus[vir].se;
                    exday += steps;
                    expower = (expower - rem + virus[vir].se) % virus[vir].se;
                }
                #ifdef LOCAL
                cout << "vertex " << v << " suggests to " << u << " {" << exday << ", " << vir << ", " << expower << ", " << u << "}\n";
                #endif // LOCAL
                infection nw = {exday, vir, expower, u};
                if (nw < virus_map[u])
                {
                    dj.erase(virus_map[u]);
                    virus_map[u] = nw;
                    dj.insert(virus_map[u]);
                }
            }
        }
        #ifdef LOCAL
            cout << "extended data:\n";
            for (int i = 0; i < b.size(); i++)
            {
                int v = b[i].se;
                cout << v << " " << virus_map[v].day << " " << virus_map[v].power << " " << virus_map[v].id << "\n";
            }
        #endif // LOCAL
        for (int i = 0; i < m; i++) cout << virus_map[ask[i]].id + 1 << " "; cout << "\n";
        #ifdef LOCAL
            cout << "case end.\n";
        #endif // LOCAL
    }
}

/* Note:
Check constants at the beginning of the code.
Check corner cases.
*/