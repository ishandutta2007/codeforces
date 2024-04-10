const long long MOD = 1e9 + 7;
const long long INF = 2e9;
const long long INFLL = 4e18;

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
    int n, q;
    cin >> n >> q;
    vector<int> x(n), w(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> w[i];

    struct Query{
        int l, r, id;
    };
    vector<Query> asks;
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        asks.push_back({l, r, i});
    }

    auto compute = [&](vector<int> x, vector<int> w, vector<Query> asks)
    {
        vector<long long> ans(q, INFLL);
        vector<pair<int, int> > st;
        vector<pair<int, long long> > L(n, {-INF - 1, INFLL});
        for (int i = 0; i < n; i++)
        {
            while (st.size() && st.back().second > w[i])
                st.pop_back();
            if (st.size())
            {
                L[i] = {st.back().first, 1ll * (x[i] - x[st.back().first]) * (w[i] + st.back().second)};
            }
            st.push_back({i, w[i]});
        }
        struct LQuery{
            int l, type, r;
            long long value;
        };
        vector<LQuery> req;
        for (int i = 0; i < n; i++) req.push_back({L[i].first, 1, i, L[i].second});
        for (int i = 0; i < q; i++) req.push_back({asks[i].l, 2, asks[i].r, asks[i].id});
        sort(all(req), [&](LQuery a, LQuery b){
             if (a.l != b.l) return a.l > b.l;
             return a.type < b.type;
             });

        vector<long long> fenw(n, INFLL);
        auto get = [&](int pos)
        {
            long long res = INFLL;
            while (pos >= 0)
            {
                res = min(res, fenw[pos]);
                pos &= pos + 1;
                pos--;
            }
            return res;
        };
        auto set = [&](int pos, long long val)
        {
            while (pos < n)
            {
                fenw[pos] = min(fenw[pos], val);
                pos |= pos + 1;
            }
        };

        for (auto e : req)
        {
            if (e.type == 1)
            {
                set(e.r, e.value);
            }
            else
            {
                ans[e.value] = get(e.r);
            }
        }
        return ans;
    };
    vector<long long> resL = compute(x, w, asks);
    for (int i = 0; i < n - 1 - i; i++)
        swap(x[i], x[n - 1 - i]), swap(w[i], w[n - 1 - i]);
    for (int i = 0; i < n; i++)
        x[i] *= -1;
    for (int i = 0; i < q; i++)
        asks[i].l = n - 1 - asks[i].l, asks[i].r = n - 1 - asks[i].r, swap(asks[i].l, asks[i].r);
    vector<long long> resR = compute(x, w, asks);
    for (int i = 0; i < q; i++) cout << min(resL[i], resR[i]) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifdef LOCAL
    cout << "\n";
    #endif // LOCAL

    int t = 1;
    #ifdef tests
    cin >> t;
    #endif // tests
    while (t--)
    {
        solve();
    }
}