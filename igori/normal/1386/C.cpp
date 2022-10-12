const int LG = 21;
const int N = 400005;
const long long MOD = 1e9 + 7;
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

string YES[2] = {"NO", "YES"};

int n, m, q;
int v[N], u[N];

int root[N], dist[N], sz[N];
int fl;

int cuts[N];
int cutssz = 0;

pii Root(int x)
{
    if (x == root[x]) return {x, 0};
    pii w = Root(root[x]);
    w.second ^= dist[x];
    return w;
}

void Merge(int v, int u)
{
    if (fl) return;
    pii x = Root(v), y = Root(u);
    int w = x.se ^ 1 ^ y.se;
    if (x.fi == y.fi)
    {
        if (w == 1) return (void)(fl = 1);
        return;
    }
    if (sz[x.fi] < sz[y.fi])
    {
        cuts[cutssz++] = x.fi;
        root[x.fi] = y.fi;
        sz[y.fi] += sz[x.fi];
        dist[x.fi] = w;
    }
    else
    {
        cuts[cutssz++] = y.fi;
        root[y.fi] = x.fi;
        sz[x.fi] += sz[y.fi];
        dist[y.fi] = w;
    }
}

void Cut()
{
    cutssz--;
    int v = cuts[cutssz];
    dist[v] = 0;
    sz[root[v]] -= sz[v];
    root[v] = v;
}

int res[N];

void solve(int L, int R, int l, int r)
{
    //cout << L << " " << R << " " << l << " " << r << " " << fl << endl;
    int M = (L + R) / 2;
    int cursz = cutssz;
    for (int i = L; i < M; i++)
    {
        Merge(v[i], u[i]);
    }
    res[M] = r;
    int m = r;
    for (int i = r - 1; i >= l; i--)
    {
        Merge(v[i], u[i]);
        if (fl)
        {
            break;
        }
        res[M] = i;
        m = i;
    }
    //cout << M << " : " << res[M] << "\n";
    fl = 0;
    while (cutssz > cursz) Cut();
    if (L + 1 == R)
    {
        return;
    }
    for (int i = r - 1; i >= m; i--)
    {
        Merge(v[i], u[i]);
    }
    solve(L, M, l, m);
    fl = 0;
    while (cutssz > cursz) Cut();
    for (int i = L; i < M; i++)
    {
        Merge(v[i], u[i]);
    }
    solve(M, R, max(M + 1, m), r);
    fl = 0;
    while (cutssz > cursz) Cut();
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++)
    {
        cin >> v[i] >> u[i];
        v[i]--, u[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        root[i] = i, sz[i] = 1;
    }
    solve(0, m, 0, m);
    while (cutssz) Cut();
    fl = 0;
    int lka = m;
    for (int i = 0; i < m; i++)
    {
        Merge(v[i], u[i]);
        if (fl)
        {
            lka = i;
            break;
        }
    }
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (lka < l)
        {
            cout << "YES\n";
            continue;
        }
        //cout << "We must sell " << l << "..." << res[l] - 1 << "\n";
        if (r >= res[l] - 1) cout << "NO\n";
        else cout << "YES\n";
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