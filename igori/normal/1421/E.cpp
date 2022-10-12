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

int cx[4] = {-1, 0, 1, 0};
int cy[4] = {0, -1, 0, 1};
string Yes[2] = {"No\n", "Yes\n"};
string YES[2] = {"NO\n", "YES\n"};
string Possible[2] = {"Impossible\n", "Possible\n"};
string POSSIBLE[2] = {"IMPOSSIBLE\n", "POSSIBLE\n"};

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    if (n == 1)
    {
        cout << a[0];
        return 0;
    }
    vector<pair<int, int> > r(n);
    forn(i, n) r[i] = {a[i], i};
    sort(all(r));
    ll ans = -INFLL;
    ll cur = accumulate(a.begin(), a.end(), 0ll);
    int m = 0;
    for (int i = 0; i <= n; i++)
    {
        if ((n + m) % 3 == 1)
        {
            if (m != n / 2 && m != n / 2 + 1)
            {
                ans = max(ans, cur);
            }
            else
            {
                int t = 0;
                vector<int> b(n);
                for (int j = 0; j < i; j++)
                    b[r[j].second] = 1;
                for (int j = 0; j + 1 < n; j++)
                    t = max(t, (int)(b[j] == b[j + 1]));
                if (t)
                    ans = max(ans, cur);
                else
                    ans = max(ans, cur - 2 * r[i].first + 2 * r[i - 1].first);
            }
        }
        if (i < n)
        {
            cur -= 2 * r[i].first;
            m++;
        }
    }
    cout << ans;
}