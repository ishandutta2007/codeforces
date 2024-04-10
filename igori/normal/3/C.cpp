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
    int n = 3;
    vector<string> s(n);
    cin >> s;

    auto won = [&](vector<string> &g)
    {
        for (int i = 0; i < 3; i++)
        {
            if (g[i][0] == g[i][1] && g[i][1] == g[i][2] && g[i][0] != '.') return 1;
        }
        for (int i = 0; i < 3; i++)
        {
            if (g[0][i] == g[1][i] && g[1][i] == g[2][i] && g[0][i] != '.') return 1;
        }
        if (g[0][0] == g[1][1] && g[1][1] == g[2][2] && g[0][0] != '.') return 1;
        if (g[0][2] == g[1][1] && g[1][1] == g[2][0] && g[0][2] != '.') return 1;
        return 0;
    };

    vector<int> p(n * n);
    iota(all(p), 0);
    while (1)
    {
        vector<string> g(n, string(n, '.'));
        for (int i = 0; i < n * n; i++)
        {
            int x = p[i] / 3;
            int y = p[i] % 3;
            char c = i % 2 ? '0' : 'X';
            if (s == g)
            {
                if (c == 'X')
                {
                    cout << "first\n"; re;
                }
                else
                {
                    cout << "second\n"; re;
                }
            }
            g[x][y] = c;
            if (won(g))
            {
                if (s == g)
                {
                    if (c == 'X')
                    {
                        cout << "the first player won\n"; re;
                    }
                    else
                    {
                        cout << "the second player won\n"; re;
                    }
                }
                else
                    break;
            }
            if (i == 8)
            {
                if (s == g)
                {
                    cout << "draw";
                    return;
                }
            }
        }
        if (!next_permutation(all(p)))
            break;
    }

    cout << "illegal\n";
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