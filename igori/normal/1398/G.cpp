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

const int LG = 20;
const int SZ = (1 << LG);
const double PI = acos(-1);

int bitreverse[SZ];

int BitReverse(int x)
{
    int y = 0;
    for (int i = 0; i < LG; i++)
    {
        y = 2 * y + ((x & (1 << i)) > 0);
    }
    return y;
}

vector<cd> dft(vector<cd> a, int fl)
{
    vector<cd> b(SZ);
    for (int i = 0; i < SZ; i++)
    {
        b[i] = a[bitreverse[i]];
    }
    for (int len = 2; len <= SZ; len <<= 1)
    {
        double ang = 2 * PI / len * fl;
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < SZ; i += len)
        {
            cd w(1, 0);
            for (int j = 0; j < len / 2; j++)
            {
                cd v = b[i + j], u = b[i + j + len / 2] * w;
                b[i + j] = v + u;
                b[i + j + len / 2] = v - u;
                w *= wlen;
            }
        }
    }
    return b;
}

vector<ll> fft(vector<ll> a0, vector<ll> b0)
{
    vector<cd> a(SZ), b(SZ);
    for (int i = 0; i < a0.size(); i++) a[i].real(a0[i]);
    for (int i = 0; i < a0.size(); i++) b[i].real(b0[i]);
    a = dft(a, 1);
    b = dft(b, 1);
    forn(i, SZ) a[i] *= b[i];
    a = dft(a, -1);
    vector<ll> r(SZ);
    forn(i, SZ)
    {
        r[i] = round(a[i].real() / SZ);
    }
    return r;
}

vector<ll> achieve(vector<ll> P)
{
    vector<ll> poly0(SZ), poly1(SZ);
    for (int i = 0; i < P.size(); i++)
    {
        poly0[P[i]] = 1;
        poly1[P.back() - P[i]] = 1;
    }
    vector<ll> a = fft(poly0, poly1);
    vector<ll> r(SZ);
    forn(i, SZ) if (a[i] && i < P.back()) r[P.back() - i] = 1;
    return r;
}

signed main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    forn(i, SZ) bitreverse[i] = BitReverse(i);

    if (0)
    {
        int n;
        cin >> n;
        vector<ll> P(n);
        for (int i = 0; i < n; i++) cin >> P[i];
        vector<ll> can = achieve(P);
        for (int i = 0; i < 10; i++)
        {
            cout << can[i] << " ";
        }
    }
    int n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n + 1);
    for (int i = 0; i < n + 1; i++)
    {
        cin >> a[i];
        a[i] *= 2;
    }
    vector<ll> can = achieve(a);
    int q;
    cin >> q;
    vector<ll> ans(SZ, -1);
    for (int i = 0; i + 2 * y < SZ; i++)
    {
        if (can[i])
        {
            ans[i + 2 * y] = i + 2 * y;
        }
    }
    for (int i = 1; i < SZ; i++)
    {
        if (ans[i] != -1)
        for (int j = i; j < SZ; j += i)
        {
            ans[j] = max(ans[j], ans[i]);
        }
    }
    while (q--)
    {
        int l;
        cin >> l;
        cout << ans[l] << " ";
    }
}

/* Note:
Check constants at the beginning of the code.
    N is set to 4e5 but be careful in problems with large constant factor.
    Setting N in every problem is more effective.
Check corner cases.
    N = 1
No def int long long for now.
Add something here.
*/