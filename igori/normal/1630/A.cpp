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
    #define tests

    int n, k;
    cin >> n >> k;

    if (k + 1 == n)
    {
        if (n == 4)
        {
            cout << -1 << "\n";
            return;
        }
        cout << n / 2 - 1 << " " << n - 1 << "\n";
        cout << n / 2 << " " << n / 2 + 1 << "\n";
        cout << n / 2 - 2 << " " << 0 << "\n";
        vector<int> used(n);
        used[n / 2 - 2] = used[n / 2 - 1] = used[n / 2] = used[n / 2 + 1] = used[0] = used[n - 1] = 1;

        for (int i = 0; i < n; i++)
        {
            if (!used[i])
            {
                cout << i << " " << n - 1 - i << "\n";
                used[i] = used[n - 1 - i] = 1;
            }
        }
        return;
    }
    if (k == 0)
    {
        for (int i = 0; i < n / 2; i++)
        {
            cout << i << " " << n - 1 - i << "\n";
        }
        return;
    }
    vector<int> used(n);
    used[0] = 1, used[k] = 1, used[n - 1] = 1, used[n - 1 - k] = 1;
    cout << k << " " << n - 1 << "\n";
    cout << 0 << " " << n - 1 - k << "\n";
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            cout << i << " " << n - 1 - i << "\n";
            used[i] = used[n - 1 - i] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << "\n";

    int t = 1;
    #ifdef tests
    cin >> t;
    #endif
    while (t--)
    {
        solve();
    }
}