#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

const long long MOD = 998244353;
const long long INF = 1e9 + 10;
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

ll log10(ll x)
{
    if (x < 10) re 1;
    re 1 + log10(x / 10);
}

ll ds(ll x)
{
    if (x < 10) return x;
    re x % 10 + ds(x / 10);
}

double sqr(double x)
{
    return x * x;
}

bool inmask(int bit, int mask)
{
    return (mask & (1 << bit)) > 0;
}

void Del(vector<int> &v, int pos)
{
    swap(v[pos], v[v.size() - 1]);
    v.pop_back();
}

long long g(vector<long long> &p, int pos)
{
    if (ok(pos, p.size())) return p[pos];
    if (pos < 0 || p.size() == 0) return 0;
    return p.back();
}

int g(vector<int> &p, int pos)
{
    if (ok(pos, p.size())) return p[pos];
    if (pos < 0 || p.size() == 0) return 0;
    return p.back();
}

ll binpow(ll x, ll y)
{
    if (!y) re 1 % MOD;
    ll l = binpow(x, y / 2);
    if (y % 2) re l * l % MOD * x % MOD;
    re l * l % MOD;
}

ll rev(ll x)
{
    return binpow(x, MOD - 2);
}

int __precomputed_combinatorics = 0;
vector<ll> __fact, __ufact, __rev;

inline void __precompute_combinatorics(int __n)
{
    if (__n < 2) __n = 2;
    if (__precomputed_combinatorics >= __n)
        return;
    __fact.resize(__n);
    __ufact.resize(__n);
    __rev.resize(__n);
    __rev[1] = 1;
    for (int i = max(2, __precomputed_combinatorics); i < __n; i++)
        __rev[i] = MOD - __rev[MOD % i] * (MOD / i) % MOD;
    __fact[0] = 1, __ufact[0] = 1;
    for (int i = max(1, __precomputed_combinatorics); i < __n; i++)
        __fact[i] = __fact[i - 1] * i % MOD, __ufact[i] = __ufact[i - 1] * __rev[i] % MOD;
    __precomputed_combinatorics = __n;
}

ll fact(int x)
{
    if (__precomputed_combinatorics <= x)
        __precompute_combinatorics(x + 1);
    return __fact[x];
}

ll cnk(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    if (__precomputed_combinatorics <= n)
        __precompute_combinatorics(n + 1);
    return __fact[n] * __ufact[n - k] % MOD * __ufact[k] % MOD;
}

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
    string s;
    cin >> s;

    if (0)
    {
        for (int i = 0; i < 100; i++)
        {
            s += "RDUL"[rand() % 4];
        }
        ll naive = 0;
        for (int l = 0; l < s.size(); l++)
        {
            for (int r = l; r < s.size(); r++)
            {
                int len = r - l + 1;
                int ok = 0;
                for (int d = 1; d <= len; d++)
                {
                    if (len % d == 0)
                    {
                        vector<vector<int> > table(d, vector<int>(len / d));
                        int fl = 1;
                        map<char, int> cx, cy;
                        cx['U'] = -1;
                        cx['D'] = 1;
                        cy['L'] = -1;
                        cy['R'] = 1;
                        for (int i = 0; i < d; i++)
                        {
                            for (int j = 0; j < len / d; j++)
                            {
                                char ch = s[l + i * len / d + j];
                                if (ch == 'U' && i == 0) fl = 0;
                                if (ch == 'D' && i == d - 1) fl = 0;
                                if (ch == 'L' && j == 0) fl = 0;
                                if (ch == 'R' && j == len / d - 1) fl = 0;
                                if (fl == 0) continue;
                                table[i + cx[ch]][j + cy[ch]]++;
                                if (table[i + cx[ch]][j + cy[ch]] == 2)
                                    fl = 0;
                            }
                        }
                        if (fl == 1)
                            ok = 1;
                    }
                }
                if (ok)
                {
                    //for (int j = l; j <= r; j++)
                    //    cout << s[j];
                    //cout << "\n";
                }
                naive += ok;
            }
        }
        cout << naive << "\n";
    }

    ll trivial = 0;
    for (int i = 0; i + 1 < s.size(); i += 2)
    {
        if (s[i] == 'R' && s[i + 1] == 'L')
        {
            int j = i;
            int cnt = 0;
            while (j + 1 < s.size() && s[j] == 'R' && s[j + 1] == 'L')
            {
                cnt++;
                j += 2;
            }
            trivial += 1ll * cnt * (cnt + 1) / 2;
            i = j - 2;
        }
    }
    for (int i = 1; i + 1 < s.size(); i += 2)
    {
        if (s[i] == 'R' && s[i + 1] == 'L')
        {
            int j = i;
            int cnt = 0;
            while (j + 1 < s.size() && s[j] == 'R' && s[j + 1] == 'L')
            {
                cnt++;
                j += 2;
            }
            trivial += 1ll * cnt * (cnt + 1) / 2;
            i = j - 2;
        }
    }

    vector<int> nextposU(s.size());
    int uu = s.size();
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == 'U') uu = i;
        nextposU[i] = uu;
    }

    ll ans = 0;
    for (int le = 0; le < s.size(); le++)
    {
        int posbreak = -1;
        for (int j = le; j + 1 < s.size(); j += 2)
        {
            if (s[j] != 'R' || s[j + 1] != 'L')
            {
                posbreak = j;
                break;
            }
        }
        if (posbreak == -1) continue;
        if (s[posbreak] == 'U' || s[posbreak] == 'L') continue;

        int pointup = posbreak;
        if (s[posbreak] == 'D')
        {
            while (pointup + 1 < s.size() && s[pointup + 1] == 'L') pointup++;
        }

        int len = nextposU[pointup] - pointup;
        int shouldcontain = nextposU[pointup];

        if (shouldcontain == s.size()) continue;

        //cout << "start at " << le << " len = " << len << "\n";

        for (int rows = 1; le + rows * len <= s.size(); rows++)
        {
            int ok = 1;
            int outerdown = 0;
            for (int i = 0; i < len; i++)
            {
                int pos = le + (rows - 1) * len + i;
                //cout << ok << " " << s[pos] << "\n";
                if (i == 0 && s[pos] == 'L') ok = 0;
                if (i == len - 1 && s[pos] == 'R') ok = 0;
                if (!ok) break;

                if (s[pos] == 'L')
                {
                    if (i >= 2 && s[pos - 2] == 'R') ok = 0;
                    if (rows >= 2 && s[pos - len - 1] == 'D') ok = 0;
                }
                if (s[pos] == 'R')
                {
                    if (rows >= 2 && s[pos - len + 1] == 'D') ok = 0;
                }
                if (s[pos] == 'U')
                {
                    if (rows == 1) ok = 0;
                    if (rows >= 2 && i + 1 < len && s[pos - len + 1] == 'L') ok = 0;
                    if (rows >= 2 && i > 0 && s[pos - len - 1] == 'R') ok = 0;
                    if (rows >= 3 && s[pos - len - len] == 'D') ok = 0;
                }

                if (s[pos] == 'D')
                {
                    outerdown = 1;
                }
                if (ok == 0)
                    break;
            }
            //cout << rows << " " << ok << "\n";
            if (!ok) break;
            if (!outerdown && le + rows * len - 1 >= shouldcontain)
            {
                //for (int j = le; j < le + rows * len; j++)
                //    cout << s[j];
                //cout << "\n";
                //cout << le << " " << le + rows * len - 1 << "\n";
                ans++;
            }
        }
    }

    //cerr << "ans = " << ans << "\n";
    cout << ans + trivial << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    srand(time(NULL));

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