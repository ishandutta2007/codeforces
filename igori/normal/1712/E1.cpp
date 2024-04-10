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

    ll L, R;
    cin >> L >> R;

    ll len = R - L + 1;
    ll tot = len * (len - 1) * (len - 2) / 6;

    ll gk = 0, g2k = 0;

    if (0)
    for (ll k = L; k <= R; k++)
    {
        for (ll j = L; j < k; j++)
        {
            for (ll i = L; i < j; i++)
            {
                ll lcm = i * j / __gcd(i, j);
                lcm = lcm * k / __gcd(lcm, k);
                if (lcm < i + j + k)
                {
                    assert(lcm == k || lcm == 2 * k);
                    if (lcm == k) gk++;
                    else
                    {
                        cout << i << " " << j << " " << k << "\n";
                        g2k++;
                    }
                }
            }
        }
    }

    vector<ll> divs(2 * R + 1);
    vector<ll> divs_triple(2 * R + 1);

    //cout << gk << " " << g2k << "\n";

    ll Gk = 0, G2k = 0;

    for (ll k = L; k <= R; k++)
    {
        ll w = divs[k];
        Gk += w * (w - 1) / 2;

        if (k % 3 == 0)
        {
            ll j = 2 * k / 3;
            // i | 2k
            // i >= k / 3
            //ll alpha = divs_triple[2 * k / 3];
            if (k / 3 >= L)
            {
                for (ll j = 2 * k / 3; j <= 2 * R; j += k / 3)
                    divs_triple[j]--;
            }
            ll alpha = divs_triple[2 * k];
            //cout << k << " -> " << alpha << "\n";
            G2k += max(alpha - 1, 0ll);
        }

        for (ll j = 2 * k; j <= 2 * R; j += k)
        {
            divs[j]++;
            divs_triple[j]++;
        }
    }

    //cout << Gk << " " << G2k << "\n";

    cout << tot - Gk - G2k << "\n";
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