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

int cx[5] = {-1, 0, 1, 0, -1};
int cy[5] = {0, -1, 0, 1, 0};

vector<int> graph[2 * 205 * 205];
int vis[2 * 205 * 205];
int paired[2 * 205 * 205];
int activated[2 * 205 * 205];

bool kuhn(int v)
{
    if (vis[v]) return 0;
    vis[v] = 1;
    for (auto u : graph[v])
    {
        if (paired[u] == -1 || kuhn(paired[u]))
        {
            paired[u] = v;
            return 1;
        }
    }
    return 0;
}

signed main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    forn(i, n) cin >> s[i];
    int q = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '#')
            {
                q++;
                for (int k = 0; k < 4; k++)
                {
                    int nx = cx[k] + i, ny = cy[k] + j;
                    int mx = cx[k + 1] + i, my = cy[k + 1] + j;
                    if (0 <= nx && nx < n && 0 <= ny && ny < m && s[nx][ny] == '#')
                    {
                        if (0 <= mx && mx < n && 0 <= my && my < m && s[mx][my] == '#')
                        {
                            int idx = 0, idy = 0;
                            if (cx[k] == 0)
                            {
                                idx =         m * min(i, nx) + min(ny, j);
                                idy = n * m + m * min(i, mx) + min(my, j);
                            }
                            else
                            {
                                idx = n * m + m * min(i, nx) + min(ny, j);
                                idy =         m * min(i, mx) + min(my, j);
                            }
                            graph[idx].push_back(idy);
                            graph[idy].push_back(idx);
                        }
                        int idx = 0;
                        if (cx[k] == 0)
                        {
                            idx =         m * min(i, nx) + min(ny, j);
                        }
                        else
                        {
                            idx = n * m + m * min(i, nx) + min(ny, j);
                        }
                        activated[idx] = 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 2 * n * m; i++) paired[i] = -1;
    for (int i = 0; i < 2 * n * m; i++) if (activated[i]) q--;
    for (int i = 0; i < n * m; i++)
    {
        for (int j = 0; j < 2 * n * m; j++) vis[j] = 0;
        if (kuhn(i)) q++;
    }
    cout << q;
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