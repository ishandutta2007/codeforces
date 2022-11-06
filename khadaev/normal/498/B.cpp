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

const int N = 5010;
double q[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    int n, T;
    cin >> n >> T;
    vector<double> p(n);
    vector<int> t(n);
    forn(i, 0, n) {
        int x;
        cin >> x;
        p[i] = 0.01 * x;
        cin >> t[i];
    }
    double ans = 0;
    q[0][0] = 1;
    forn(i, 0, n) {
        double POW = pow(1 - p[i], t[i] - 1);
        fore(j, 0, T)
            q[i + 1][j + 1] += p[i] * q[i][j];
        fore(j, 0, T - t[i] + 1)
            q[i + 1][j + t[i]] -= p[i] * POW * q[i][j];
        fore(j, 0, T)
            q[i + 1][j + 1] += (1 - p[i]) * q[i + 1][j];
        fore(j, 0, T - t[i])
            q[i + 1][j + t[i]] += POW * q[i][j];
        fore(j, 0, T) ans += q[i + 1][j];
    }
    cout << ans << '\n';
}