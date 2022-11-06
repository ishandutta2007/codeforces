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

const int N = 1001;
int a[N][N];

int main() {
    int n, m, ans = 0;
    scanf("%d %d", &n, &m);
    forn(i, 0, n) forn(j, 0, m) scanf("%d", &a[i][j]);
    forn(i, 0, n) forn(j, i + 1, n) {
        int m1 = 0, m2 = 0;
        forn(k, 0, m) {
            int x = min(a[i][k], a[j][k]);
            if (x > m1) {
                m2 = m1;
                m1 = x;
            } else if (x > m2) m2 = x;
        }
        ans = max(ans, m2);
    }
    printf("%d\n", ans);
}