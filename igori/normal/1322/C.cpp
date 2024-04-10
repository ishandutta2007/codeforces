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

const int N = 5e5 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<pair<vector<int>, int> > ns(n);
    forn(i, n) cin >> a[i];
    forn(i, n) ns[i].second = i;
    forn(i, m)
    {
        int v, u;
        cin >> v >> u;
        u--;
        v--;
        ns[u].first.push_back(v);
    }
    for (int i = 0; i < n; i++) sort(all(ns[i].first));
    sort(all(ns));
    ll g = 0;
    for (int i = 0; i < n; )
    {
        ll si = 0, j = i;
        while (j < n && ns[j].first == ns[i].first)
        {
            si += ns[j].first.size() ? a[ns[j].second] : 0;
            j++;
        }
        i = j;
        if (si == 0) continue;
        g = __gcd(g, si);
    }
    cout << g << "\n";
}

signed main()
{
    #ifdef ONLINE_JUDGE
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // ONLINE_JUDGE
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}