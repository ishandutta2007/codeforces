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

const int N = 2e5;
const int K = 5;
vector<int> e[N];
ll res[N][K];
int p[N];
ll sz[N];
int n, k;
ll ans = 0;

void dfs(int i) {
    res[i][0] = 1;
    for (int j : e[i])
        if (j != p[i]) {
            p[j] = i;
            dfs(j);
            forn(r, 0, k - 1)
                res[i][r + 1] += res[j][r];
            res[i][0] += res[j][k - 1];
        }
    forn(r, 0, k)
        sz[i] += res[i][r];
    ans += 2 * sz[i] * (n - sz[i]);
    forn(r1, 0, k) {
        forn(r2, 0, k) {
            int len = (r1 + r2) % k;
            if (len == 0) continue;
            if (len) ans += (k - len) * res[i][r1] * res[i][r2];
            int q1 = r1 - 1;
            if (q1 == -1) q1 += k;
            int q2 = r2 - 1;
            if (q2 == -1) q2 += k;


            for (int j : e[i])
                if (j != p[i]) {
                    ans -= (k - len) * res[j][q1] * res[j][q2];
                }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    forn(i, 1, n) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        e[u].eb(v);
        e[v].eb(u);
    }
    p[0] = -1;
    dfs(0);
    assert(ans % (2 * k) == 0);
    cout << ans / (2 * k) << '\n';
}