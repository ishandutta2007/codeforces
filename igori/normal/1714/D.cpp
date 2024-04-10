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

void solve()
{
    #define tests

    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> S(n);
    forn(i, n) cin >> S[i];

    vector<int> dp(s.size() + 1, INF);
    dp[0] = 0;
    vector<int> prev(s.size() + 1), lst(s.size() + 1);

    for (int i = 1; i <= s.size(); i++)
    {
        for (int it = 0; it < n; it++)
        {
            if (S[it].size() <= i && s.substr(i - S[it].size(), S[it].size()) == S[it])
            {
                for (int j = i - S[it].size(); j < i; j++)
                {
                    if (dp[j] + 1 < dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        prev[i] = j, lst[i] = it;
                    }
                }
            }
        }
    }

    if (dp[s.size()] >= INF)
    {
        cout << -1 << "\n";
        return;
    }
    cout << dp[s.size()] << "\n";
    int pos = s.size();
    while (pos > 0)
    {
        cout << lst[pos] + 1 << " " << pos - S[lst[pos]].size() + 1 << "\n";
        pos = prev[pos];
    }
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