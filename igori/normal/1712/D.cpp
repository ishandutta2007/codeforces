const int MOD = 1e9 + 7;
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

#define ok(x, n) (0 <= (x) && (x) < (n))
#define withBit(mask, i) ((mask & (1 << i)) > 0)

template<typename T> istream& operator>>(istream& in, vector<T>& a)
{
    for (int i = 0; i < a.size(); i++)
        in >> a[i];
    return in;
}

template<typename T> ostream& operator<<(ostream& out, const vector<T>& a)
{
    for (auto e : a)
    {
        out << e << " ";
        if (typeid(T) != typeid(int) && typeid(T) != typeid(ll))
            out << "\n";
    }
    return out;
}

void solve()
{
    #define tests

    int n, k;
    cin >> n >> k;
    vi a(n);
    cin >> a;

    ll L = 0, R = 1e9 + 1;
    while (L + 1 < R)
    {
        ll M = (L + R) / 2;

        vi b = a;
        int min_cnt = 1e9;

        int small = 0;
        for (int i = 0; i < n; i++)
        {
            if (2 * a[i] < M)
                small++;
        }

        for (int i = 0; i + 1 < n; i++)
        {
            // want to have
            // min(a[i], a[i + 1], 2 * mn) >= M
            // a[i] >= M
            // a[i + 1] >= M
            // mn >= M / 2
            int sq = small;
            if (a[i] < M)
                sq++;
            if (a[i + 1] < M)
                sq++;
            if (2 * a[i] < M)
                sq--;
            if (2 * a[i + 1] < M)
                sq--;

            min_cnt = min(min_cnt, sq);
        }

        if (min_cnt <= k)
            L = M;
        else
            R = M;
    }
    cout << L << "\n";
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