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

void solve()
{
    int n;
    cin >> n;
    vector<ll> p(n), u(n);
    forn(i, n) cin >> u[i], u[i]--;
    forn(i, n) cin >> p[i];
    vector<vector<ll> > pp(n);
    forn(i, n) pp[u[i]].push_back(p[i]);
    forn(i, n) sort(rall(pp[i]));
    sort(all(pp), [&](vector<ll> a, vector<ll> b){
         return a.size() > b.size();
         });
    forn(i, n) forn(j, pp[i].size()) if (j) pp[i][j] += pp[i][j - 1];
    for (int k = 1; k <= n; k++)
    {
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (pp[i].size() < k) break;
            ans += pp[i][pp[i].size() / k * k - 1];
        }
        cout << ans << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}