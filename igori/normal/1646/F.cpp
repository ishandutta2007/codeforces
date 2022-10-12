const long long MOD = 998244353;
const long long INF = 1e9;
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

int kuhn(int v, vector<vector<int> > &g, vector<int> &mp, vector<int> &vis)
{
    if (vis[v])
        return 0;
    vis[v] = 1;
    for (auto u : g[v])
    {
        if (mp[u] == -1 || kuhn(mp[u], g, mp, vis))
        {
            mp[u] = v;
            return 1;
        }
    }
    return 0;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int> > a(n, vector<int>(n));

    #ifdef GEN
    vector<int> d(n * n);
    for (int i = 0; i < n * n; i++) d[i] = i % n;
    random_shuffle(all(d));
    forn(i, n) forn(j, n) a[i][j] = d[i * n + j];
    #else
    forn(i, n) forn(j, n) cin >> a[i][j], a[i][j]--;
    #endif // GEN

    forn(col, n)
    {
        vector<vector<int> > g(n);
        forn(i, n)
        {
            vector<int> cnt(n);
            for (int j = col; j < n; j++)
            {
                cnt[a[i][j]]++;
                if (cnt[a[i][j]] == 1)
                    g[i].push_back(n + a[i][j]);
            }
        }

        vector<int> mp(2 * n, -1);
        vector<int> vis(n);
        forn(i, n)
        {
            fill(all(vis), 0);
            kuhn(i, g, mp, vis);
        }

        for (int i = n; i < 2 * n; i++)
        {
            assert(mp[i] != -1);
            int rowid = mp[i];
            for (int j = col; j < n; j++)
            {
                if (a[rowid][j] == i - n)
                {
                    swap(a[rowid][j], a[rowid][col]);
                    break;
                }
            }
        }
    }

    auto move_diagonal = [&](int id)
    {
        vector<int> x;
        for (int i = 0; i < n; i++)
        {
            x.push_back(a[i][id]);
            id--;
            if (id < 0)
                id = n - 1;
        }
        for (int i = 0; i < n; i++)
        {
            a[i][id] = x[(i + n - 1) % n];
            id--;
            if (id < 0)
                id = n - 1;
        }
        for (auto e : x) cout << e + 1 << " ";
        cout << "\n";
    };

    cout << n * (n - 1) << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i) % n; j++)
        {
            move_diagonal(i);
        }
    }

    for (int C = 0; C < n - 1; C++)
    {
        for (int st = n - 1 - C; st > 0; st--)
        {
            vector<int> x;
            for (int i = st; i < n; i++)
                x.push_back(i);
            for (int i = 0; i < st; i++)
                x.push_back(i);

            for (auto p : x) cout << p + 1 << " ";
            cout << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    srand(time(NULL));

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