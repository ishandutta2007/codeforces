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

int cx[4] = {-1, 0, 1, 0};
int cy[4] = {0, -1, 0, 1};
string Yes[2] = {"No\n", "Yes\n"};
string YES[2] = {"NO\n", "YES\n"};
string Possible[2] = {"Impossible\n", "Possible\n"};
string POSSIBLE[2] = {"IMPOSSIBLE\n", "POSSIBLE\n"};

void solve()
{
    #define tests

    int n;
    string s;
    cin >> n >> s;
    vector<int> dx(s.size() + 1), dy(s.size() + 1);
    for (int i = s.size() - 1; i >= 0; i--)
    {
        dx[i] = dx[i + 1], dy[i] = dy[i + 1];
        if (s[i] == 'D') dx[i]++;
        else dy[i]++;
    }

    int fD = 0, fR = 0;
    int curx = 1, cury = 1;
    long long ans = 1;
    int coverx = 1, covery = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'D') fD = 1, curx++;
        else fR = 1, cury++;
        int x2 = n, y2 = n;
        if (fD == 0) x2 = curx;
        else x2 = x2 - dx[i + 1];
        if (fR == 0) y2 = cury;
        else y2 = y2 - dy[i + 1];
        //cout << curx << " " << cury << " " << x2 << " " << y2 << "\n";
        //cout << "+ " << (x2 - curx + 1) * (y2 - cury + 1) << "\n";
        //cout << "- " << (coverx - curx + 1) * (covery - cury + 1) << "\n";
        ans += 1ll * (x2 - curx + 1) * (y2 - cury + 1) - 1ll * (coverx - curx + 1) * (covery - cury + 1);
        //cout << ans << "\n";
        coverx = x2;
        covery = y2;
        //Rect.push_back({curx, cury, x2, y2});
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