#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 30010;
const int D = 300;

int ans[N][2 * D];
int p[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, d;
    cin >> n >> d;
    while(n--) {
        int x;
        cin >> x;
        p[x]++;
    }
    forn(i, 0, N) forn(j, 0, 2 * D) ans[i][j] = -INF;
    ans[d][D] = p[d];
    int res = p[d];
    forn(i, d + 1, N)
        forn(j, 0, 2 * D) {
            ans[i][j] = -INF;
            forn(sh, d - D + j - 1, d - D + j + 2) {
                if (sh <= 0) continue;
                if (sh + D - d < 0) continue;
                if (sh + D - d >= 2 * D) continue;
                if (d - D +  j <= 0) continue;
                if (i - (d - D + j) < 0) continue;
                ans[i][j] = max(ans[i][j], ans[i - (d - D + j)][sh + D - d] + p[i]);
            }
            res = max(res, ans[i][j]);
            //if (ans[i][j] )cerr << i << ' ' << j << ' ' << ans[i][j] << '\n';
        }
    cout << res << '\n';
}