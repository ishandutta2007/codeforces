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

const int N = 1010;
ld p[N][N];

int main() {
    int n;
    scanf("%d", &n);
    forn(i, 0, n) forn(j, 0, n) {
        int x;
        scanf("%d", &x);
        p[i][j] = x / 100.;
    }
    using T = pair<ld, int>;
    priority_queue<T, vector<T>, greater<T>> q;
    vector<ld> ans(n, -1.), a(n, 1.), b(n, 1.);
    ans[n - 1] = 0.;
    forn(i, 0, n - 1) {
        a[i] += b[i] * p[i][n - 1] * ans[n - 1];
        b[i] *= 1 - p[i][n - 1];
    }
    while (1) {
        ld bestval = 1e9;
        int v = -1;
        forn(i, 0, n) {
            if (ans[i] > -eps) continue;
            ld val = a[i] / (1 - b[i]);
            if (val < bestval) {
                bestval = val;
                v = i;
            }
        }
        if (v == -1) break;
        if (ans[v] > -eps) continue;
        if (v == n - 1) ans[v] = 0.;
        else {
            ans[v] = a[v] / (1 - b[v]);
        }
        forn(i, 0, n) {
            if (ans[i] > -eps) continue;
            if (p[i][v] < eps) continue;
            a[i] += b[i] * p[i][v] * ans[v];
            b[i] *= 1 - p[i][v];
        }
    };
    cout << fixed << setprecision(10) << ans[0] << '\n';
}