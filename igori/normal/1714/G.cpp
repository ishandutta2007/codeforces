const int MOD = 998244353;
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

vector<long long> Q;

void dfs(int v, vector<vector<pii> > &gA, vector<vector<pii> > &gB, long long S, vi &ans)
{
    int L = 0, R = Q.size();
    while (L + 1 < R)
    {
        int M = (L + R) / 2;
        if (Q[M] <= S) L = M;
        else R = M;
    }
    ans[v] = L;
    for (int i = 0; i < gA[v].size(); i++)
    {
        Q.push_back(Q.back() + gB[v][i].second);
        dfs(gA[v][i].first, gA, gB, S + gA[v][i].second, ans);
        Q.pop_back();
    }
}

void solve()
{
    #define tests

    int n;
    cin >> n;

    vector<vector<pii> > gA(n);
    vector<vector<pii> > gB(n);

    for (int i = 2; i <= n; i++)
    {
        int p, a, b;
        cin >> p >> a >> b;
        p--;
        gA[p].push_back({i - 1, a});
        gB[p].push_back({i - 1, b});
    }

    vector<int> ans(n);
    Q = {0};
    dfs(0, gA, gB, 0, ans);
    for (int i = 1; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    #ifdef tests
    cin >> t;
    #endif // tests
    while (t--)
    {
        solve();
    }
}