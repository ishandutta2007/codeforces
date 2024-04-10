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

    string s;
    cin >> s;

    ll ans = 0;
    string res = s;

    map<int, int> cnt;
    for (int i = 0; i < s.size(); i++)
        cnt[s[i]]++;

    vector<pii> q;
    for (auto e : cnt)
        q.push_back(e);

    auto get = [&](string &t)
    {
        ll cur = 0;
        map<int, int> pos;
        vector<int> ch = {'A', 'N', 'T', 'O'};
        for (int i = t.size() - 1; i >= 0; i--)
            pos[t[i]] = i;

        for (int i = 0; i < s.size(); i++)
        {
            int g = pos[s[i]];
            cur += abs(g - i);
            for (auto e : ch)
            {
                if (pos[e] <= g)
                    pos[e]++;
            }
        }
        return cur;
    };

    while (1)
    {
        string t;
        for (auto e : q)
        {
            for (int i = 0; i < e.second; i++)
                t += e.first;
        }
        ll cost = get(t);
        if (cost > ans)
        {
            ans = cost;
            res = t;
        }
        if (!next_permutation(all(q)))
            break;
    }

    cout << res << "\n";
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