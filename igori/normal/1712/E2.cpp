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

void solve(ll L, ll R)
{
    ll len = R - L + 1;
    ll tot = len * (len - 1) * (len - 2) / 6;

    vector<ll> divs(2 * R + 1);

    ll Gk = 0, G2k = 0;

    for (ll k = L; k <= R; k++)
    {
        ll w = divs[k];
        Gk += w * (w - 1) / 2;
        //cout << w << "\n";

        if (k % 3 == 0)
        {
            ll j = 2 * k / 3;
            // i | 2k
            // i >= k / 3
            ll alpha = 0;
            if (2 * k % 4 == 0 && 2 * k / 4 >= L) alpha++;
            if (2 * k % 5 == 0 && 2 * k / 5 >= L) alpha++;
            //cout << k << " -> " << alpha << "\n";
            G2k += max(alpha, 0ll);
        }

        for (ll j = 2 * k; j <= 2 * R; j += k)
        {
            divs[j]++;
        }
    }

    cout << Gk << " " << G2k << "\n";
    //cout << tot - Gk - G2k << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    const int M = 4e5 + 222;

    int n;
    cin >> n;
    vector<ll> tot(n);
    vector<ll> G2(n);
    vector<ll> G2k(n);
    vector<vector<pair<ll, ll> > > queries(M);
    for (int i = 0; i < n; i++)
    {
        ll L, R;
        cin >> L >> R;
        //solve(L, R);
        queries[L].push_back({R, i});
        ll len = R - L + 1;
        tot[i] = len * (len - 1) * (len - 2) / 6;
    }

    vector<ll> fenw_divs(M);
    auto add = [&](int pos, ll val)
    {
        while (pos < M)
        {
            fenw_divs[pos] += val;
            pos |= (pos + 1);
        }
    };

    auto get = [&](int pos)
    {
        ll res = 0;
        while (pos >= 0)
        {
            res += fenw_divs[pos];
            pos &= (pos + 1);
            pos--;
        }
        return res;
    };

    auto getLR = [&](int l, int r)
    {
        return get(r) - get(l - 1);
    };

    vector<ll> divs(M);
    for (int i = 1; i < M; i++)
    {
        for (int j = 2 * i; j < M; j += i)
        {
            add(j, - (divs[j]) * (divs[j] - 1) / 2);
            divs[j]++;
            add(j, (divs[j]) * (divs[j] - 1) / 2);
        }
    }

    vector<ll> fenw2(M);
    auto add2 = [&](int pos, ll val)
    {
        while (pos < M)
        {
            fenw2[pos] += val;
            pos |= (pos + 1);
        }
    };

    auto get2 = [&](int pos)
    {
        ll res = 0;
        while (pos >= 0)
        {
            res += fenw2[pos];
            pos &= (pos + 1);
            pos--;
        }
        return res;
    };

    auto getLR2 = [&](int l, int r)
    {
        return get2(r) - get2(l - 1);
    };

    for (int i = 3; i < M; i += 3)
    {
        if (2 * i % 4 == 0) add2(i, 1);
        if (2 * i % 5 == 0) add2(i, 1);
    }

    for (int L = 1; L < M; L++)
    {
        for (auto e : queries[L])
        {
            ll R = e.first;
            G2[e.second] = getLR(L, R);
            G2k[e.second] = getLR2(L, R);
        }
        for (int j = 2 * L; j < M; j += L)
        {
            add(j, - (divs[j]) * (divs[j] - 1) / 2);
            divs[j]--;
            add(j, (divs[j]) * (divs[j] - 1) / 2);
        }

        if (5 * L % 2 == 0)
        {
            if (5 * L / 2 % 3 == 0)
            add2(5 * L / 2, -1);
        }
        if (4 * L % 2 == 0)
        {
            if (4 * L / 2 % 3 == 0)
            add2(4 * L / 2, -1);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << tot[i] - G2[i] - G2k[i] << "\n";
    }
}