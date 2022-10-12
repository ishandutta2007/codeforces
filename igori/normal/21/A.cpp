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

void solve()
{
    string s;
    cin >> s;

    vector<int> pos_2, pos_dot, pos_s;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '@') pos_2.pb(i);
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '.') pos_dot.pb(i);
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '/') pos_s.pb(i);

    if (pos_2.size() != 1)
    {
        cout << "NO\n";
        return;
    }
    if (pos_s.size() > 1)
    {
        cout << "NO\n";
        return;
    }
    string username = s.substr(0, pos_2[0]);
    int len_hostname = s.size() - pos_2[0] - 1;
    if (pos_s.size()) len_hostname = pos_s[0] - pos_2[0] - 1;
    string hostname = s.substr(pos_2[0] + 1, len_hostname);
    string resource = "";
    if (pos_s.size()) resource = s.substr(pos_s[0] + 1, s.size() - pos_s[0] - 1);

    auto is_valid_c = [&](char c)
    {
        return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9') || c == '_';
    };

    auto is_valid_word = [&](string s)
    {
        if (s.size() < 1 || s.size() > 16) return 0;
        for (auto e : s) if (!is_valid_c(e)) return 0;
        return 1;
    };

    if (!is_valid_word(username))
        cout << "NO\n", exit(0);

    if (hostname.size() < 1 || hostname.size() > 32)
        cout << "NO\n", exit(0);

    ln;

    string g = "";
    for (int i = 0; i < hostname.size(); i++)
    {
        if (hostname[i] == '.')
        {
            if (!is_valid_word(g)) cout << "NO\n", exit(0);
            g = "";
        }
        else
        {
            g += hostname[i];
        }
    }
    ln;
    dbg(g);

    if (!is_valid_word(g)) cout << "NO\n", exit(0);

    ln;

    if (pos_s.size() && !is_valid_word(resource)) cout << "NO\n", exit(0);
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