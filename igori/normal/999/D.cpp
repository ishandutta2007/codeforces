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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<vi> pos(m);
    for (int i = 0; i < n; i++) cin >> a[i], pos[a[i] % m].push_back(i);
    vector<int> st;
    for (int t = 0; t < 2; t++)
    for (int i = 0; i < m; i++)
    {
        while (pos[i].size() > n / m)
        {
            st.push_back(pos[i].back());
            pos[i].pop_back();
        }
        while (pos[i].size() < n / m && st.size())
        {
            pos[i].push_back(st.back());
            st.pop_back();
        }
    }
    ll ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (auto e : pos[i])
        {
            //cout << e << " ";
            if (a[e] % m <= i)
                ans += i - a[e] % m, a[e] += i - a[e] % m;
            else
                ans += m - a[e] % m + i, a[e] += m - a[e] % m + i;
        }
        //cout << endl;
    }
    cout << ans << "\n";
    for (auto e : a) cout << e << " ";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}

/* Note:
Check constants at the beginning of the code (MOD, INF, INFLL)
Check corner cases.
    N = 1
No def int long long for now.
Add something here.
*/