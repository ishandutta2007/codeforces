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

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int p0 = 0, p1 = 0;
    for (int i = 0; i < k; i++)
    {
        int c0 = 0, c1 = 0, cq = 0;
        for (int j = i; j < n; j += k)
        {
            if (s[j] == '0') c0++;
            else if (s[j] == '1') c1++;
            else cq++;
        }
        if (c0 > 0 && c1 > 0)
        {
            cout << "NO\n";
            return;
        }
        if (c0 > 0)
        {
            p0++;
            continue;
        }
        if (c1 > 0)
        {
            p1++;
            continue;
        }
    }
    if (p0 <= k / 2 && p1 <= k / 2)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

signed main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
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