//#pragma GCC optimize("O3")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define y0 _y0
#define kill _kill

//permanent constants
const ld pi = acosl(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const ld eps = 1e-8;
const ll INF = (ll)(2e18) + 239;
const int BIG = (int)(1e9) + (int)(239); // (int)(2e9) + (int)(1e6)
const int MOD = 998'244'353; // 1'000'000'007
const ll MOD2 = (ll)MOD * (ll)MOD;

namespace math {
    inline int sum(int a, int b) {
        a += b - MOD;
        a += (a >> 31) & MOD;
        return a;
    }

    inline void add(int& a, int b) {
        a += b - MOD;
        a += (a >> 31) & MOD;
    }

    inline int sub(int a, int b) {
        a -= b;
        a += (a >> 31) & MOD;
        return a;
    }

    inline void make_sub(int& a, int b) {
        a -= b;
        a += (a >> 31) & MOD;
    }

    inline int mul(int a, int b) {
        return (ll)a * (ll)b % (ll)MOD;
    }

    inline int power(int a, int k) {
        int ans = 1;
        int pw = a;
        while (k) {
            if (k & 1) {
                ans = mul(ans, pw);
            }
            pw = mul(pw, pw);
            k >>= 1;
        }
        return ans;
    }

    inline int inv(int a) {
        return power(a, MOD - 2);
    }

    inline int div(int a, int b) {
        return mul(a, inv(b));
    }
}

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 19) + 239;
const int B = 500;
const int X = 510;

vector<int> v[X];
int n, m;
int w[X][X];
int dist[X][X];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        v[i].clear();
        for (int j = 0; j < n; j++) {
            w[i][j] = BIG;
            dist[i][j] = BIG;
        }
    }
    for (int i = 0; i < m; i++) {
        int s, f, ww;
        cin >> s >> f >> ww;
        s--, f--;
        if (w[s][f] == BIG) {
            v[s].emplace_back(f);
            v[f].emplace_back(s);
        }
        w[s][f] = min(w[s][f], ww);
        w[f][s] = min(w[f][s], ww);
    }
    queue<pair<int, int>> q;
    dist[0][n - 1] = 0;
    q.push(make_pair(0, n - 1));
    while (!q.empty()) {
        pair<int, int> t = q.front();
        q.pop();
        int x = t.first;
        int y = t.second;
        for (int z : v[x]) {
            int cx = min(z, y);
            int cy = max(z, y);
            if (dist[cx][cy] > dist[x][y] + 1) {
                dist[cx][cy] = dist[x][y] + 1;
                q.push(make_pair(cx, cy));
            }
        }
        for (int z : v[y]) {
            int cx = min(z, x);
            int cy = max(z, x);
            if (dist[cx][cy] > dist[x][y] + 1) {
                dist[cx][cy] = dist[x][y] + 1;
                q.push(make_pair(cx, cy));
            }
        }
        if (x == y) {
            for (int i = 0; i < n; i++) {
                int cx = min(i, x);
                int cy = max(i, x);
                if (dist[cx][cy] > dist[x][y] + 1) {
                    dist[cx][cy] = dist[x][y] + 1;
                    q.push(make_pair(cx, cy));
                }
            }
        }
    }
    ll ans = (ll)(1e18);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (w[i][j] != BIG && dist[i][j] != BIG) {
                //cerr << i + 1 << " " << j + 1 << " " << dist[i][j] << "\n";
                ans = min(ans, (ll)w[i][j] * (dist[i][j] + 1));
            }
        }
    }
    cout << ans << "\n";
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}