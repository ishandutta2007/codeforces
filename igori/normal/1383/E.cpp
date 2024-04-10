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

int cx[4] = {0, 0, 1, -1};
int cy[4] = {-1, 1, 0, 0};
string Yes[2] = {"No\n", "Yes\n"};
string YES[2] = {"NO\n", "YES\n"};
string Possible[2] = {"Impossible\n", "Possible\n"};
string POSSIBLE[2] = {"IMPOSSIBLE\n", "POSSIBLE\n"};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef LOCAL
        cout << "\n";
    #endif // LOCAL

    string s;
    cin >> s;
    int n = s.size();
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            a.push_back(i);
        }
    }
    if (a.size() == 0)
    {
        cout << n;
        return 0;
    }
    long long k = 1ll * (a[0] + 1) * (n - a.back()) % MOD;
    vector<ll> dp(n + 1);
    ll res = 1;
    for (int i = 1; i < a.size(); i++)
    {
        int len = a[i] - a[i - 1] - 1;
        ll cur = res;
        for (int j = 0; j <= len; j++)
        {
            res = ((res + cur - dp[j]) % MOD + MOD) % MOD;
            dp[j] = cur;
        }
    }
    cout << res * k % MOD;
}