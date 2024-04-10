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

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string s;

    if (0)
    {
        s = "";
        vector<int> G = {a, b, c, d};
        while (accumulate(all(G), 0))
        {
            int r = rand() % 4;
            if (G[r] > 0)
            {
                G[r]--;
                if (r == 0) s += "A";
                if (r == 1) s += "B";
                if (r == 2) s += "AB";
                if (r == 3) s += "BA";
            }
        }
        cout << s << "\n";
    }

    cin >> s;
    int cnta = 0, cntb = 0;
    forn(i, s.size())
    {
        if (s[i] == 'A') cnta++;
        else cntb++;
    }
    if (cnta != a + c + d)
    {
        cout << "NO\n";
        return;
    }
    if (cntb != b + c + d)
    {
        cout << "NO\n";
        return;
    }

    vector<int> ab, ba, aba, bab;
    for (int i = 0; i < s.size(); i++)
    {
        int j = i;
        while (j + 1 < s.size() && s[j + 1] != s[j])
            j++;
        if (s[i] == 'A' && s[j] == 'B') ab.push_back(j - i + 1);
        if (s[i] == 'A' && s[j] == 'A') aba.push_back(j - i + 1);
        if (s[i] == 'B' && s[j] == 'B') bab.push_back(j - i + 1);
        if (s[i] == 'B' && s[j] == 'A') ba.push_back(j - i + 1);
        i = j;
    }

    sort(rall(ab));
    sort(rall(ba));

    while (c && ab.size())
    {
        //dbg(c);
        //dbg(ab);
        int cnt = min(ab.back() / 2, c);
        ab[ab.size() - 1] -= 2 * cnt;
        c -= cnt;
        if (ab.back() == 0)
            ab.pop_back();
    }

    while (d && ba.size())
    {
        //dbg(d);
        //dbg(ba);
        int cnt = min(ba.back() / 2, d);
        ba[ba.size() - 1] -= 2 * cnt;
        d -= cnt;
        if (ba.back() == 0)
            ba.pop_back();
    }

    int words = 0;
    for (auto e : ab) words += (e - 2) / 2;
    for (auto e : ba) words += (e - 2) / 2;
    for (auto e : aba) words += (e - 1) / 2;
    for (auto e : bab) words += (e - 1) / 2;
    cout << YES[words >= c + d];
    if (0 && words < c + d)
    {
        cout << ab << "\n";
        cout << ba << "\n";
        cout << aba << "\n";
        cout << bab << "\n";
        cout << c << " " << d << "\n";
        cout << "???";
        exit(0);
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