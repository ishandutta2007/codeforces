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

#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
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

ll inq(ll x, ll y)
{
    if (y == 0) return 1;
    ll l = inq(x, y / 2);
    l = l * l % MOD;
    if (y % 2) return l * x % MOD;
    return l;
}

int sz = 0;
pair<int, ll> st[10100];

inline void comp(vector<ll> &d, vector<int> &le, vector<int> &ri)
{
    for (int j = 0; j < d.size(); j++)
    {
        while (sz && st[sz - 1].second >= d[j])
            sz--;
        if (sz)
            le[j] = st[sz - 1].first;
        st[sz] = {j, d[j]}, sz++;
    }
    sz = 0;
    for (int j = d.size() - 1; j >= 0; j--)
    {
        while (sz && st[sz - 1].second >= d[j])
            sz--;
        if (sz)
            ri[j] = st[sz - 1].first;
        st[sz] = {j, d[j]}, sz++;
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> h(n + 2);
    forn(i, n) cin >> h[i + 1];

    ll ans = 0;
    vector<ll> d = h;
    vector<int> Le(n + 2), Ri(n + 2);
    comp(h, Le, Ri);
    vector<int> le(n + 2), ri(n + 2);

    vector<ll> lo(n + 2);
    for (int i = 1; i <= n; i++)
    {
        int L = Le[i], R = Ri[i];
        ll res = h[i] * (R - L - 1);
        for (int j = L + 1; j <= R - 1; j++) d[j] -= h[i];

        {
            ll cur = h[i];
            ll b = h[i];
            ll a = 0;
            lo[L] = h[L];
            for (int j = L - 1; j >= 0; j--)
                lo[j] = min(h[j], lo[j + 1]);
            int pl = 0;
            for (int pos = R; pos <= n; pos++)
            {
                b = min(b, h[pos]);
                a = cur - b;
                while (pl <= L && lo[pl] < a) pl++;
                ans = max(ans, b * (pos - L) + a * (R - pl));
            }
        }
        {
            ll cur = h[i];
            ll a = h[i];
            ll b = 0;
            lo[R] = h[R];
            for (int j = R + 1; j <= n + 1; j++)
                lo[j] = min(h[j], lo[j - 1]);
            int pl = n + 1;
            for (int pos = L; pos >= 1; pos--)
            {
                a = min(a, h[pos]);
                b = cur - a;
                while (pl >= R && lo[pl] < b) pl--;
                ans = max(ans, a * (R - pos) + b * (pl - L));
            }
        }

        comp(d, le, ri);
        for (int j = 1; j <= n; j++)
        {
            ll res2 = (ri[j] - le[j] - 1) * d[j] + res;
            ans = max(ans, res2);
        }

        for (int j = L + 1; j <= R - 1; j++) d[j] += h[i];
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    #ifdef tests
    cin >> t;
    #endif // tests
    for (int tt = 1; tt <= t; tt++)
    {
        solve();
    }
}