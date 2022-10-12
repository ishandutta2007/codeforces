const int MOD = 998244353;
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

struct node{
    long long tot, mx_pref, mx_suff, mx_segm;
    node()
    {
        tot = mx_pref = mx_suff = mx_segm = 0;
    }
    node(long long x)
    {
        tot = x;
        mx_pref = max(x, 0ll);
        mx_suff = max(x, 0ll);
        mx_segm = max(x, 0ll);
    }
    friend ostream& operator << (ostream &out, node &nd)
    {
        out << nd.tot << " " << nd.mx_pref << " " << nd.mx_suff << " " << nd.mx_segm;
        return out;
    }
};

node merge(const node &a, const node &b)
{
    node res(0);
    res.tot = a.tot + b.tot;
    res.mx_pref = max(a.mx_pref, a.tot + b.mx_pref);
    res.mx_suff = max(b.mx_suff, b.tot + a.mx_suff);
    res.mx_segm = max({a.mx_segm, b.mx_segm, a.mx_suff + b.mx_pref});
    return res;
}

void solve()
{
    int n = 18;
    cin >> n;
    vector<long long> a(1 << n);
    //for (int i = 0; i < a.size(); i++) a[i] = rand();
    for (int i = 0; i < a.size(); i++) cin >> a[i];

    int sz = n / 2;
    vector<vector<node> > nodes(1 << sz);
    for (int i = 0; i < (1 << n); i += (1 << sz))
    {
        for (int state = 0; state < (1 << sz); state++)
        {
            node ans(0);
            for (int j = 0; j < (1 << sz); j++)
            {
                ans = merge(ans, node(a[i + (state ^ j)]));
            }
            nodes[state].push_back(ans);
        }
    }

    int q;
    cin >> q;

    int state = 0, ustate = 0;

    while (q--)
    {
        int k;
        cin >> k;
        //k = rand() % n;
        if (k < sz)
        {
            state ^= (1 << k);
        }
        else
        {
            ustate ^= (1 << (k - sz));
        }

        node ans(0);
        for (int i = 0; i < (1 << (n - sz)); i++)
        {
            //cout << "merge with [" << nodes[state][i ^ ustate] << "] ";
            ans = merge(ans, nodes[state][i ^ ustate]);
        }
        cout << ans.mx_segm << "\n";
    }
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