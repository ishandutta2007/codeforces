#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef complex<double> cd;

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

const int N = 1450400;

vector<int> graph[N];

void dfs(int v, vi &col, int color)
{
    col[v] = color;
    for (auto u : graph[v])
    {
        if (col[u] == 0)
        {
            dfs(u, col, 3 - color);
        }
    }
}

signed main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << "First" << endl;
        for (int i = 1; i <= n; i++) cout << i << " ";
        for (int i = 1; i <= n; i++) cout << i << " ";
        cout << endl;
        return 0;
    }
    cout << "Second" << endl;
    vector<vector<int> > c(n);
    for (int i = 1; i <= 2 * n; i++)
    {
        int x;
        cin >> x;
        x--;
        c[x].push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        graph[c[i][0]].push_back(c[i][1]);
        graph[c[i][1]].push_back(c[i][0]);
        graph[i + 1].push_back(i + n + 1);
        graph[i + n + 1].push_back(i + 1);
    }
    vector<int> col(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++)
    {
        if (col[i] == 0)
        {
            dfs(i, col, 1);
        }
    }
    ll si = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        if (col[i] == 1) si += i;
    }
    if (si % (2 * n) == 0)
    {
        for (int i = 1; i <= 2 * n; i++)
            if (col[i] == 1) cout << i << " ";
        cout << endl;
        return 0;
    }
    else
    {
        for (int i = 1; i <= 2 * n; i++)
            if (col[i] == 2) cout << i << " ";
        cout << endl;
        return 0;
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