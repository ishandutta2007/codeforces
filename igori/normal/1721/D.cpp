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

int suc(vi a, vi b, int r)
{
    int ans = 0;
    int c0a = 0, c1b = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (!(a[i] & (1 << r))) c0a++;
        if (b[i] & (1 << r)) c1b++;
    }
    return c0a == c1b;
}

void solve()
{
    #define tests

    int n;
    cin >> n;
    vi a(n), b(n);
    cin >> a >> b;

    vvi A = {a};
    vvi B = {b};

    int ans = 0;
    for (int r = 29; r >= 0; r--)
    {
        int tr = 1;
        for (int i = 0; i < A.size(); i++)
        {
            if (!suc(A[i], B[i], r))
                tr = 0;
        }
        if (tr)
        {
            ans += (1 << r);
            vvi A2, B2;
            for (int i = 0; i < A.size(); i++)
            {
                vi x0, x1, y0, y1;
                for (int j = 0; j < A[i].size(); j++)
                {
                    if (withBit(A[i][j], r)) x1.push_back(A[i][j]);
                    else x0.push_back(A[i][j]);
                    if (withBit(B[i][j], r)) y1.push_back(B[i][j]);
                    else y0.push_back(B[i][j]);
                }
                if (x0.size())
                {
                    A2.push_back(x0);
                    B2.push_back(y1);
                }
                if (x1.size())
                {
                    A2.push_back(x1);
                    B2.push_back(y0);
                }
            }
            swap(A, A2);
            swap(B, B2);
        }
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