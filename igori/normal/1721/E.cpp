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

vector<int> p_func(string &s)
{
    // Calculates prefix function of string s
    //
    //
    vector<int> p(s.size());
    for (int i = 1; i < (int)s.size(); i++)
    {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j])
            j++;
        p[i] = j;
    }
    return p;
}

mt19937 rndx;

void solve()
{
    //#define NAIVE

    string s;
    cin >> s;

    int q;
    cin >> q;

    const __int128 MOD = 1'004'535'809 * 998'244'353;
    __int128 base = rndx() % (MOD - 10'000'000);
    base += 5'000'000;

    vector<__int128> hashes(s.size());
    for (int i = 0; i < s.size(); i++)
    {
        hashes[i] = s[i];
        if (i) hashes[i] = (hashes[i] + hashes[i - 1] * base) % MOD;
    }

    vector<__int128> deg(s.size() + 20);
    deg[0] = 1;
    for (int i = 1; i < s.size() + 20; i++)
    {
        deg[i] = deg[i - 1] * base % MOD;
    }

    auto get_substr_hash = [&](int l, int r)
    {
        ll X = (r >= 0 ? hashes[r] : 0) - (l ? hashes[l - 1] : 0) * deg[r - l + 1];
        X = (X % MOD + MOD) % MOD;
        return X;
    };

    map<ll, int> sup;
    for (int i = 0; i < s.size(); i++)
    {
        int ok = get_substr_hash(0, i - 1) == get_substr_hash(s.size() - i, s.size() - 1);
        ll tmp = 0;
        for (int j = 0; j < 10; j++)
        {
            if (i + j >= s.size()) break;
            tmp = 26 * tmp + s[i + j] - '0';
            if (ok) sup[tmp] = max(sup[tmp], i + j + 1);
        }
    }

    while (q--)
    {
        string t;
        cin >> t;

        #ifdef NAIVE
        s += t;
        vector<int> p = p_func(s);
        for (int i = s.size() - t.size(); i < s.size(); i++)
            cout << p[i] << " ";
        cout << "\n";
        forn(i, t.size()) s.pop_back();
        #endif // NAIVE

        for (int i = 0; i < t.size(); i++)
        {
            hashes.push_back((hashes.back() * base + t[i]) % MOD);
        }
        int A = s.size();
        ll tmp = 0;
        for (int i = 0; i < t.size(); i++)
        {
            A++;
            tmp = 26 * tmp + t[i] - '0';
            int ans = sup[tmp];
            for (int len = 1; len <= i; len++)
            {
                if (get_substr_hash(0, len - 1) == get_substr_hash(A - len, A - 1))
                {
                    ans = max(ans, len);
                }
            }
            for (int len = A - t.size(); len < A; len++)
            {
                if (get_substr_hash(0, len - 1) == get_substr_hash(A - len, A - 1))
                {
                    ans = max(ans, len);
                }
            }
            cout << ans << " ";
        }
        cout << "\n";
        for (int i = 0; i < t.size(); i++)
        {
            hashes.pop_back();
        }
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