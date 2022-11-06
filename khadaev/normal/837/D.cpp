#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n - 1); i >= (int)(a); --i)
#define fore(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
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

template<typename T>
inline void setmax(T& a, T b) {
    if (a < b) a = b;
}

template<typename T>
inline void setmin(T& a, T b) {
    if (a > b) a = b;
}

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 222;
int dp1[N][N * 30], dp2[N][N * 30];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, K;
    cin >> n >> K;
    vector<ll> a(n);
    forn(i, 0, n) cin >> a[i];
    forn(j, 0, N) forn(k, 0, 30 * N) dp1[j][k] = -1;
    forn(j, 0, N) forn(k, 0, 30 * N) dp2[j][k] = -1;
    dp1[0][0] = 0;
    forn(i, 0, n) {
        int x = 0, y = 0;
        while (a[i] % 2 == 0) {
            ++x;
            a[i] /= 2;
        }
        while (a[i] % 5 == 0) {
            ++y;
            a[i] /= 5;
        }
        fore(j, 0, i + 1) forn(k, 0, N * 30) {
            dp2[j][k] = dp1[j][k];
            if (j && k >= y && dp1[j - 1][k - y] != -1) {
                setmax(dp2[j][k], dp1[j - 1][k - y] + x);
            }
        }
        swap(dp1, dp2);
        forn(j, 0, N) forn(k, 0, 30 * N) dp2[j][k] = -1;
    }
    int ans = 0;
    forn(i, 0, N * 30) {
        setmax(ans, min(dp1[K][i], i));
    }
    cout << ans << '\n';
}