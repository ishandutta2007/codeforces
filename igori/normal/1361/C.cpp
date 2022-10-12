const int LG = 21;
const int FN = 400005;
const long long MOD = 998244353;
const long long INF = 1e9;
const long long INFLL = 1e18;

#include <bits/stdc++.h>

const double PI = acos(-1);

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > G;

#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
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
string Yes[2] = {"No", "Yes"};
string YES[2] = {"NO", "YES"};
string Psb[2] = {"Impossible", "Possible"};
string psb[2] = {"impossible", "possible"};

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
    __fact.resize(FN);
    __ufact.resize(FN);
    __rev.resize(FN);
    __rev[1] = 1;
    for (int i = 2; i < FN; i++) __rev[i] = MOD - __rev[MOD % i] * (MOD / i) % MOD;
    __fact[0] = 1, __ufact[0] = 1;
    for (int i = 1; i < FN; i++) __fact[i] = __fact[i - 1] * i % MOD, __ufact[i] = __ufact[i - 1] * __rev[i] % MOD;
}

ll fact(int x)
{
    if (!__precomputed_combinatorics) __precompute_combinatorics();
    return __fact[x];
}

ll cnk(int n, int k)
{
    if (k < 0 || k > n) return 0;
    if (!__precomputed_combinatorics) __precompute_combinatorics();
    return __fact[n] * __ufact[n - k] % MOD * __ufact[k] % MOD;
}

void bfs(int v, vi &dist, vector<vector<pii> > &graph)
{
    fill(all(dist), -1);
    dist[v] = 0;
    vi q = {v};
    for (int i = 0; i < q.size(); i++)
    {
        for (auto x : graph[q[i]])
        {
            int u = x.first;
            if (dist[u] == -1)
            {
                dist[u] = dist[q[i]] + 1;
                q.push_back(u);
            }
        }
    }
}

void Eracer(vector<pii> &vec, int pos)
{
    swap(vec[vec.size() - 1], vec[pos]);
    vec.pop_back();
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vll a(n), b(n);
    forn(i, n)
    {
        cin >> a[i] >> b[i];
    }
    for (int j = 20; j > 0; j--)
    {
        vector<int> cnt((1 << j));
        ll byte = (1 << j) - 1;
        for (int i = 0; i < n; i++)
        {
            cnt[a[i] & byte]++;
            cnt[b[i] & byte]++;
        }
        int t = 1;
        for (int i = 0; i < cnt.size(); i++)
        {
            if (cnt[i] % 2 != 0) t = 0;
        }
        if (t)
        {
            vector<vector<pair<int, int> > > graph(cnt.size());
            for (int i = 0; i < n; i++)
            {
                graph[a[i] & byte].push_back({b[i] & byte, 2 * i});
                graph[b[i] & byte].push_back({a[i] & byte, 2 * i + 1});
            }
            int root = 0;
            for (int i = 0; i < cnt.size(); i++)
            {
                if (cnt[i] > 0)
                {
                    root = i;
                }
            }
            vector<int> d(cnt.size());
            bfs(root, d, graph);
            int t = 1;
            for (int i = 0; i < cnt.size(); i++)
            {
                if (cnt[i] > 0 && d[i] == -1) t = 0;
            }
            if (t == 0) continue;
            vector<int> ray;
            vector<pii> st;
            st.push_back({root, -1});
            vector<int> free(n, 1);
            while (st.size())
            {
                int v = st.back().first;
                int t = 0;
                for (int j = 0; j < graph[v].size(); j++)
                {
                    int id = graph[v][j].second;
                    int u = graph[v][j].first;
                    if (free[id / 2])
                    {
                        free[id / 2] = 0;
                        st.push_back({u, id});
                        Eracer(graph[v], j);
                        t = 1;
                        break;
                    }
                    else
                    {
                        Eracer(graph[v], j);
                        j--;
                    }
                }
                if (t == 0)
                {
                    if (st.back().second != -1) ray.push_back(1 ^ st.back().second);
                    st.pop_back();
                }
            }
            cout << j << "\n";
            for (int i = 0; i < ray.size(); i++)
            {
                if (ray[i] % 2)
                {
                    cout << ray[i] + 1 << " " << ray[i] << " ";
                }
                else
                {
                    cout << ray[i] + 1 << " " << ray[i] + 2 << " ";
                }
            }
            return 0;
            cout << "\n";
            for (int i = 0; i < ray.size(); i++)
            {
                if (ray[i] % 2)
                {
                    cout << (b[ray[i] / 2] & byte) << " " << (a[ray[i] / 2] & byte) << " ";
                }
                else
                {
                    cout << (a[ray[i] / 2] & byte) << " " << (b[ray[i] / 2] & byte) << " ";
                }
            }
            return 0;
        }
    }
    cout << 0 << "\n";
    for (int i = 0; i < 2 * n; i++)
    {
        cout << i + 1 << " ";
    }
}

/* Note:
Check constants at the beginning of the code.
    N is set to 4e5 but be careful in problems with large constant factor.
    Setting N in every problem is more effective.
Check corner cases.
    N = 1
No def int long long for now.
Add something here.
*/