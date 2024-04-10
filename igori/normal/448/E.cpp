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
    ll x, k;
    cin >> x >> k;
    if (x == 1)
    {
        cout << 1 << " ";
        return;
    }
    const int N = 1e5;
    if (k > N)
    {
        forn(i, N) cout << 1 << " ";
        return;
    }
    vector<ll> divs;
    for (ll j = 1; j * j <= x; j++)
    {
        if (x % j == 0)
        {
            divs.push_back(j);
            if (j * j != x) divs.push_back(x / j);
        }
    }
    sort(all(divs));
    map<ll, vector<ll> > d;
    for (int i = 0; i < divs.size(); i++)
    {
        for (int j = 0; j < divs.size(); j++)
        {
            if (divs[i] % divs[j] == 0)
                d[divs[i]].push_back(divs[j]);
        }
    }
    vector<ll> res = {x};
    while (k)
    {
        int t = 0;
        vector<ll> res2;
        for (auto e : res)
        {
            for (auto ee : d[e])
            {
                res2.push_back(ee);
                if (res2.size() >= N) break;
            }
            if (d[e].size() > 2) t = 1;
            if (res2.size() >= N) break;
        }
        res = res2;
        k--;
        if (!t)
            break;
    }
    //cout << k << endl;
    vector<ll> res2;
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i] == 1) res2.push_back(1);
        else
        {
            forn(i, k) res2.push_back(1);
            res2.push_back(res[i]);
        }
        if (res2.size() >= N) break;
    }
    if (res2.size() >= N) res2.resize(N);
    //cout << res2.size() << endl;
    for (auto e : res2) cout << e << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << "\n";

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}