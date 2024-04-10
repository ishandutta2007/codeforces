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

int can(int M, vi &a, int k)
{
    vector<int> cnt(a.size() + 1);
    forn(i, a.size()) cnt[a[i]]++;

    for (int i = 1; i <= a.size(); i++) cnt[i] += cnt[i - 1];

    for (int R = M; R <= a.size(); R++)
    {
        if (2 * (cnt[R] - cnt[R - M]) - (int)a.size() >= k)
            return 1;
    }
    return 0;
}

void solve()
{
    #define tests

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    forn(i, n) cin >> a[i];

    int L = 0, R = n + 1;
    while (L + 1 < R)
    {
        int M = (L + R) / 2;
        if (can(M, a, k)) R = M;
        else L = M;
    }

    int M = R;
    vector<int> cnt(a.size() + 1);
    forn(i, a.size()) cnt[a[i]]++;

    for (int i = 1; i <= a.size(); i++) cnt[i] += cnt[i - 1];

    for (int r = M; r <= a.size(); r++)
    {
        if (2 * (cnt[r] - cnt[r - M]) - (int)a.size() >= k)
        {
            cout << r - M + 1 << " " << r << "\n";
            int pnt = 0, si = 0;
            for (int i = 0; i < a.size(); i++)
            {
                if (r - M + 1 <= a[i] && a[i] <= r) si++;
                else si--;

                if (si > 0 && (k > 1 || i + 1 == a.size()))
                {
                    cout << pnt + 1 << " " << i + 1 << "\n";
                    pnt = i + 1;
                    si = 0;
                    k--;
                }
            }
            return;
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