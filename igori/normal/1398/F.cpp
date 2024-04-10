const int LG = 21;
const int N =208;
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

int Root(int v, vi &root)
{
    if (root[v] == v) return v;
    return root[v] = Root(root[v], root);
}

void Merge(int v, int u, vector<int> &root, vector<int> &sz, vector<int> &mx)
{
    v = Root(v, root), u = Root(u, root);
    if (v == u) assert(0);
    if (sz[v] > sz[u]) swap(v, u);
    mx[u] = max(mx[u], mx[v]);
    sz[u] += sz[v];
    root[v] = u;
}

signed main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector<int> go(n);
    int lst = n;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '1') lst = i;
        go[i] = max(go[i], lst - i);
    }
    lst = n;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '0') lst = i;
        go[i] = max(go[i], lst - i);
    }
    vector<int> can_go(n, 1);
    vector<pair<int, int> > de;
    forn(i, n) de.push_back({go[i], i});
    sort(all(de));
    int j = 0;
    vector<int> root(n + 1), sz(n + 1, 1), mx(n + 1);
    iota(all(root), 0);
    iota(all(mx), 0);
    for (int k = 1; k <= n; k++)
    {
        while (j < de.size() && de[j].first < k)
        {
            Merge(de[j].second, de[j].second + 1, root, sz, mx);
            j++;
        }
        int ans = 0;
        for (int i = 0; i < n; )
        {
            int fr = mx[Root(i, root)];
            if (fr == n) break;
            i = fr + k;
            ans++;
        }
        cout << ans << " ";
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