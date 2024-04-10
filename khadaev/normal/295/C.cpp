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

const int N = 51;
vector<int> e[2 * N * N];
ll ways[2 * N * N];
int dist[2 * N * N];
ll binom[N][N];

void show(int n) {
    cout << n / (N * N) << ' ';
    n %= (N * N);
    cout << n / N << ' ';
    n %= N;
    cout << n << '\n';
}

ll mult(int u, int v, int c1, int c2) {
    if (u < N * N) {
        v -= N * N;
        return binom[u / N][v / N] * binom[u % N][v % N] % MOD;
    } else {
        u -= N * N;
        return binom[c1 - u / N][c1 - v / N] * binom[c2 - u % N][c2 - v % N] % MOD;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    binom[0][0] = 1;
    forn(i, 1, N) {
        binom[i][0] = 1;
        forn(j, 1, i) binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % MOD;
        binom[i][i] = 1;
    }
    int n, k;
    cin >> n >> k;
    k /= 50;
    int c1 = 0, c2 = 0;
    forn(i, 0, n) {
        int w;
        cin >> w;
        if (w == 50) ++c1;
        else ++c2;
    }
    fore(i1, 0, c1) fore(i2, 0, c2) fore(j1, 0, c1) fore(j2, 0, c2) {
        if (j1 <= i1 && j2 <= i2) {
            int d1 = i1 - j1, d2 = i2 - j2;
            if ((d1 != 0 || d2 != 0) && d1 + 2 * d2 <= k)
                e[i1 * N + i2].eb(N * N + j1 * N + j2);
        }
        if (j1 >= i1 && j2 >= i2) {
            int d1 = j1 - i1, d2 = j2 - i2;
            if ((d1 != 0 || d2 != 0) && d1 + 2 * d2 <= k)
                e[N * N + i1 * N + i2].eb(j1 * N + j2);
        }
    }
    ways[c1 * N + c2] = 1;
    vector<int> q = {c1 * N + c2};
    int d = 0;
    while (!q.empty()) {
        ++d;
        vector<int> nq;
        for (int v : q) {
            if (dist[v]) continue;
            //cout << d << ": ";
            //show(v);
            //cout << ways[v] << '\n';
            dist[v] = d;
            for (int u : e[v])
                if (dist[u] == 0) {
                    nq.eb(u);
                    ways[u] += ways[v] * mult(u, v, c1, c2);
                    ways[u] %= MOD;
                }
        }
        q = nq;
    }
    int to = N * N;
    int ans = dist[to];
    if (ans == 0) {
        cout << "-1\n0\n";
        return 0;
    }
    --ans;
    cout << ans << '\n' << ways[to] << '\n';
}