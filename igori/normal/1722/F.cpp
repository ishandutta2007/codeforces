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

    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    cin >> s;

    vector<string> S(n + 2, string(m + 2, '.'));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            S[i + 1][j + 1] = s[i][j];
        }
    }
    n += 2, m += 2;

    vvi a(n, vi(m));
    int id = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (S[i][j] == '*')
            {
                int near = 0;
                for (int k = 0; k < 4; k++)
                {
                    if (S[i + cx[k]][j + cy[k]] == '*')
                        near++;
                }
                if (near > 2)
                {
                    cout << "No\n";
                    return;
                }
                if (near == 2)
                {
                    vector<pii> q = {{i, j}};
                    for (int k = 0; k < 4; k++)
                    {
                        if (S[i + cx[k]][j + cy[k]] == '*')
                        {
                            q.push_back({i + cx[k], j + cy[k]});
                        }
                    }
                    id++;
                    for (auto e : q) a[e.fi][e.se] = id;
                    set<int> dix, diy;
                    for (auto e : q) dix.insert(e.fi);
                    for (auto e : q) diy.insert(e.se);
                    if (dix.size() != 2 || diy.size() != 2)
                    {
                        cout << "nO\n";
                        return;
                    }
                    for (auto e : q)
                    {
                        vi c8x = {-1, -1, -1, 0, 0, 1, 1, 1};
                        vi c8y = {-1, 0, 1, -1, 1, -1, 0, 1};
                        for (int k = 0; k < 8; k++)
                        {
                            int nx = e.fi + c8x[k];
                            int ny = e.se + c8y[k];
                            if (S[nx][ny] == '*' && a[nx][ny] != id)
                            {
                                cout << "NO\n";
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (S[i][j] == '*' && a[i][j] == 0)
            {
                cout << "no\n";
                return;
            }
        }
    }
    cout << "YES\n";
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