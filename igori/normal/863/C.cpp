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
    ll k;
    int a, b;
    cin >> k >> a >> b; a--, b--;
    vector<vector<int> > alice(3, vector<int>(3));
    vector<vector<int> > bob(3, vector<int>(3));
    forn(i, 3) forn(j, 3) cin >> alice[i][j], alice[i][j]--;
    forn(i, 3) forn(j, 3) cin >> bob[i][j], bob[i][j]--;

    ll a1 = 0, a2 = 0;
    if (k > 100)
    {
        vector<vector<int> > lst(3, vector<int>(3));
        ll p = 0;
        for (int g = 1; ; g++)
        {
            if (lst[a][b] != 0)
            {
                p = g - lst[a][b];
                k -= g - 1;
                break;
            }
            else
            {
                if ((a + 1) % 3 == b) a2++;
                if ((b + 1) % 3 == a) a1++;
                lst[a][b] = g;
                int c = alice[a][b];
                b = bob[a][b];
                a = c;
            }
        }
        cerr << p << " " << a1 << " " << a2 << endl;
        ll sc1 = 0, sc2 = 0;
        for (int i = 0; i < p; i++)
        {
            if ((a + 1) % 3 == b) sc2++;
            if ((b + 1) % 3 == a) sc1++;
            int c = alice[a][b];
            b = bob[a][b];
            a = c;
        }
        a1 += k / p * sc1, a2 += k / p * sc2;
        k %= p;
    }
    while (k > 0)
    {
        k--;
        if ((a + 1) % 3 == b) a2++;
        if ((b + 1) % 3 == a) a1++;
        int c = alice[a][b];
        b = bob[a][b];
        a = c;
    }
    cout << a1 << " " << a2 << endl;
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