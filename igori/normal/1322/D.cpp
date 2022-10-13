#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

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

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " " << #x << " " << x << endl
#define ln cerr << __LINE__ << endl
#else
#define dbg(x) void(0)
#define ln void(0)
#endif // LOCAL

const int N = 5000;

int n, m;
int a[N], s[N], c[N];
ll dp[N][N];
ll dpA[N];

signed main()
{
    #ifdef ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // ONLINE_JUDGE
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 1; i <= n + m; i++) cin >> c[i];
    reverse(a, a + n);
    reverse(s, s + n);
    for (int i = 0; i < n; i++) s[i] *= -1;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) dp[i][j] = -1e9, dpA[i] = -1e9;
    dpA[0] = 0, dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int pr = a[i]; pr >= 0; pr--)
        {
            if (pr + 12 <= a[i])
            {
                dp[a[i]][1] = max(dp[a[i]][1], dpA[pr] + c[a[i]] + s[i]);
                dpA[a[i]] = max(dpA[a[i]], dp[a[i]][1]);
            }
            else
            {
                for (int sel_mask = (1 << 12) - 1; sel_mask >= 0; sel_mask--)
                {
                    int bit = a[i] - pr;
                    int new_mask = sel_mask >> bit;
                    int res = c[a[i]] + s[i];
                    for (int j = 0; j < 12; j++)
                    {
                        if ((new_mask & (1 << j)) == 0)
                        {
                            new_mask += (1 << j);
                            break;
                        }
                        new_mask -= (1 << j);
                        res += c[a[i] + j + 1];
                    }
                    //cout << sel_mask << " " << new_mask << "\n";
                    dp[a[i]][new_mask] = max(dp[a[i]][new_mask], dp[pr][sel_mask] + res);
                    dpA[a[i]] = max(dpA[a[i]], dp[a[i]][new_mask]);
                }
            }
        }
    }
    ll mx = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) mx = max(mx, dp[i][j]);
    cout << mx;
}