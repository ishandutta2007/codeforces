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

template<class T> struct sparse_max{
    // Returns min on segment [l, r] of predefined array a
    //
    // Correctness tested on the following problem:
    // https://codeforces.com/contest/1304/problem/E
    // Speed tested on random tests with n = 4e6, q = 4e6, T = int, average = 0.508ms/test (local)
    // Speed tested on random tests with n = 4e6, q = 4e7, T = int, average = 1.778ms/test (local)
    //
    vector<vector<T> > sp;
    vector<int> H;
    T get(int l, int r)
    {
        int h = H[r - l + 1];
        return max(sp[h][l], sp[h][r - (1 << h) + 1]);
    }
    sparse_max(vector<T> a)
    {
        int n = a.size();
        H = vector<int>(n + 1);
        for (int i = 3; i < n + 1; i++)
        {
            H[i] = H[i - 1] + (((i - 1) & (i - 2)) == 0);
        }
        int s = 0;
        while ((1 << s) <= n) s++;
        sp = vector<vector<T>>(s, vector<T>(n));
        for (int i = 0; i < n; i++)
        {
            sp[0][i] = a[i];
        }
        for (int j = 1; j < s; j++)
        {
            for (int i = 0; i + (1 << j) - 1 < n; i++)
            {
                sp[j][i] = get(i, i + (1 << j) - 1);
            }
        }
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, n) cin >> a[i], a[i]--;

    vector<int> L(n, -1), R(n, -1);
    forn(i, n)
    {
        R[a[i]] = i;
        if (L[a[i]] == -1) L[a[i]] = i;
    }

    vector<int> ri(n, -1);
    forn(i, n)
    {
        if (L[i] < R[i])
            ri[L[i]] = R[i];
    }

    sparse_max<int> sp(ri);

    int ans = 0;

    for (int i = 0; i < n;)
    {
        if (ri[i] != -1)
        {
            int j = ri[i];
            int cnt = 0;
            while (sp.get(i + 1, j - 1) > j)
            {
                cnt++;
                j = sp.get(i + 1, j - 1);
            }
            ans += j - i - 1 - cnt;
            i = j + 1;
        }
        else
        {
            i++;
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << "\n";

    int t = 1;
    #ifdef tests
    cin >> t;
    #endif
    while (t--)
    {
        solve();
    }
}