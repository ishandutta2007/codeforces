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

ll binpow(ll x, ll y)
{
    if (y == 0) return 1;
    ll l = binpow(x, y / 2);
    l = l * l % MOD;
    if (y % 2) l = l * x % MOD;
    return l;
}

void solve()
{
    int x, y;
    cin >> x >> y;
    if (y % x != 0)
    {
        cout << 0 << "\n";
        return;
    }
    y /= x;

    vector<int> divs;
    for (int i = 1; i * i <= y; i++)
    {
        if (y % i == 0)
        {
            divs.pb(i);
            divs.pb(y / i);
        }
    }
    uniq(divs);
    dbg(divs);

    int ans = 0;
    for (auto e : divs)
    {
        int mu = 1, E = e;
        for (int i = 2; i * i <= E; i++)
        {
            if (E % i == 0)
            {
                E /= i;
                mu *= -1;
                if (E % i == 0)
                {
                    mu = 0;
                    break;
                }
            }
        }
        if (E > 1)
            mu *= -1;
        ans = (ans + mu * binpow(2, y / e - 1)) % MOD;
        if (ans < 0) ans += MOD;
    }
    cout << ans << "\n";
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