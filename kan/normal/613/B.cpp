#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) begin(x), end(x)
#define fi first
#define se second

const int maxn = 100005;
const ll inf = 1e18;

pair<int, int> a[maxn];
int n;
int cf, cm;
int A;
ll M;
int ans[maxn];

int main()
{
    scanf("%d%d%d%d" LLD, &n, &A, &cf, &cm, &M);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i].fi);
        a[i].se = i;
    }
    sort(a, a + n);
    ll needfull = (ll)A * n;
    for (int i = 0; i < n; i++)
    {
        needfull -= a[i].fi;
//         cout << a[i].fi << endl;
    }
//     cout << needfull << endl;
    if (needfull <= M)
    {
        printf(LLD "\n", (ll)n * cf + (ll)cm * A);
        for (int i = 0; i < n; i++) printf("%d ", A);
        printf("\n");
        return 0;
    }
    ll curlvl = 0;
    int cur = 0;
    ll cursum = 0;
    pair<ll, pair<ll, ll>> result = {-1, {-1, -1}};
    for (int i = 0; i <= n; i++)
    {
//         cout << i << ' ' << needfull << ' ' << cur << ' ' << curlvl << ' ' << cursum << endl;
        if (needfull <= M)
        {
            result = max(result, {(ll)cf * (n - i) + (ll)cm * curlvl, {i, curlvl}});
        }
        if (i == n) break;
        needfull -= (A - a[i].fi);
        ll have = M - needfull;
        while (true)
        {
            ll minstop = inf;
            if (cur > 0) minstop = min(minstop, curlvl + (have - cursum) / cur);
            if (cur <= i) minstop = min(minstop, (ll)a[cur].fi);
//             cout << minstop << endl;
            if (minstop == inf || (minstop <= curlvl && !(cur <= i && a[cur].fi == minstop))) break;
            minstop = min(minstop, (ll)A);
            cursum += cur * (minstop - curlvl);
            curlvl = minstop;
            while (cur <= i && a[cur].fi <= curlvl) cur++;
        }
    }
//     cout << result.se.fi << ' ' << result.se.se << endl;
    printf(LLD "\n", result.first);
    for (int i = 0; i < n; i++) ans[a[i].se] = a[i].fi;
    for (int i = 0; i < n; i++) if (a[i].fi <= result.se.se) ans[a[i].se] = result.se.se;
    for (int i = result.se.fi; i < n; i++) ans[a[i].se] = A;
    for (int i = 0; i < n; i++) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}