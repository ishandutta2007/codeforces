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

vector<int> binary(int x)
{
    vector<int> s;
    while (x)
    {
        s.push_back(x % 2);
        x /= 2;
    }
    reverse(all(s));
    return s;
}

void solve()
{
    int n, p;
    cin >> n >> p;

    vector<int> dp(p + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= p; i++)
        dp[i] = dp[i - 1] + dp[i - 2], dp[i] %= MOD;

    for (int i = 1; i <= p; i++)
        dp[i] += dp[i - 1], dp[i] %= MOD;

    vector<int> a(n);
    forn(i, n) cin >> a[i];
    sort(all(a));
    int ans = 0;
    set<vector<int> > S;
    for (auto e : a)
    {
        vector<int> num = binary(e);
        if (num.size() > p) continue;
        int T = 1;
        while (T)
        {
            if (S.find(num) != S.end())
            {
                T = 0;
                break;
            }
            if (num.size() >= 2 && num[num.size() - 1] == 0 && num[num.size() - 2] == 0)
                num.pop_back(), num.pop_back();
            else if (num.size() && num.back() == 1)
                num.pop_back();
            else break;
        }
        if (T == 1)
        {
            num = binary(e);
            ans += dp[p - num.size()], ans %= MOD;
            S.insert(num);
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifdef LOCAL
    cout << "\n";
    #endif // LOCAL

    int t = 1;
    #ifdef tests
    cin >> t;
    #endif // tests
    while (t--)
    {
        solve();
    }
}