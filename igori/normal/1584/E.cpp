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

long long ans = 0;

void run(int l, int r, int m, vll &a)
{
    int mid = (l + r) / 2;
    if (mid % 2 == 1)
    {
        if (a[l] == a[l + 1] && l + 1 < m)
        {
            ans++;
        }
        return;
    }
    map<ll, int> mm;
    mm[a[mid - 1]]++;
    ll cur = 0, mnEven = 0, mnOdd = 0;
    for (int pos = mid - 2; pos >= l; pos -= 2)
    {
        ll C = a[pos + 1] - a[pos];
        cur += C;
        mnEven = min(C, C + mnEven);
        mnOdd = min(a[pos], mnOdd - C);
        if (pos == mid - 2) mnOdd = a[pos];
        if (mnEven >= 0 && mnOdd >= 0)
            mm[cur]++;
    }

    cur = 0, mnEven = 0, mnOdd = 0;
    for (int pos = mid - 3; pos >= l; pos -= 2)
    {
        ll C = a[pos + 1] - a[pos];
        cur += C;
        mnEven = min(C, C + mnEven);
        mnOdd = min(a[pos], mnOdd - C);
        if (pos == mid - 3) mnOdd = a[pos];
        if (mnEven >= 0 && mnOdd >= 0)
        {
            if (cur <= a[mid - 1])
                mm[a[mid - 1] - cur]++;
        }
    }

    if (mid < m)
        ans += mm[a[mid]];

    cur = 0, mnEven = 0, mnOdd = 0;
    for (int pos = mid + 1; pos < r && pos < m; pos += 2)
    {
        ll C = a[pos - 1] - a[pos];
        cur += C;
        mnEven = min(C, C + mnEven);
        mnOdd = min(a[pos], mnOdd - C);
        if (pos == mid + 1) mnOdd = a[pos];
        if (mnEven >= 0 && mnOdd >= 0)
            ans += mm[cur];
    }

    cur = 0, mnEven = 0, mnOdd = 0;
    for (int pos = mid + 2; pos < r && pos < m; pos += 2)
    {
        ll C = a[pos - 1] - a[pos];
        cur += C;
        mnEven = min(C, C + mnEven);
        mnOdd = min(a[pos], mnOdd - C);
        if (pos == mid + 2) mnOdd = a[pos];
        if (mnEven >= 0 && mnOdd >= 0)
        {
            if (cur <= a[mid])
                ans += mm[a[mid] - cur];
        }
    }

    run(l, mid, m, a);
    run(mid, r, m, a);
}

void solve(int n, vector<ll> a)
{
    ans = 0;
    int m = n;
    n++, a.push_back(0);
    while (n & (n - 1))
        n++, a.push_back(0);
    run(0, n, m, a);
    for (int i = 0; i < m; i++) ans += (a[i] == 0);

    cout << ans << "\n";
    return;

    long long res = 0;
    for (int i = 0; i < m; i++)
    {
        long long cur = 0;
        for (int j = i; j < m; j++)
        {
            if (a[j] < cur)
                break;
            cur = a[j] - cur;
            if (cur == 0) res++;
        }
    }
    cout << res << "\n";
    return;

    if (res != ans)
    {
        cout << m << "\n";
        for (auto e : a) cout << e << " ";
        cout << endl;
        exit(0);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        forn(i, n) cin >> a[i];
        solve(n, a);
    }
}