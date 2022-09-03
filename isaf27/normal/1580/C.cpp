#pragma GCC optimize("Ofast")
/*
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/

#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define y0 _y0
#define kill _kill

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const ld eps = 1e-10;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

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
const int T = (1 << 18) + 239;
const int B = 2000;
const int X = 1000;

struct fenwick {
    vector<int> tree;

    fenwick() = default;

    explicit fenwick(int n) {
        tree.resize(n + 1);
    }

    void add(int l, int r, int x) {
        upd(l, x);
        upd(r + 1, -x);
    }

    int gett(int i) {
        int ans = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) {
            ans += tree[i];
        }
        return ans;
    }

    void upd(int i, int x) {
        for (; i < (int)tree.size(); i |= i + 1) {
            tree[i] += x;
        }
    }
};

int n, m, x[M], y[M];

#define prev prev_

int prev[M], small[X + 2][X + 2];

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    fenwick total(m);
    for (int z = 0; z < m; z++) {
        int t, i;
        cin >> t >> i;
        if (t == 1) {
            t = 1;
        } else {
            t = -1;
        }
        i--;
        if (t == 1) {
            prev[i] = z;
        }
        if (x[i] + y[i] <= X) {
            int lg = (prev[i] + x[i]) % (x[i] + y[i]);
            int rg = (prev[i] + x[i] + y[i] - 1) % (x[i] + y[i]);
            if (lg <= rg) {
                for (int j = lg; j <= rg; j++) {
                    small[x[i] + y[i]][j] += t;
                }
            } else {
                for (int j = lg; j < x[i] + y[i]; j++) {
                    small[x[i] + y[i]][j] += t;
                }
                for (int j = 0; j <= rg; j++) {
                    small[x[i] + y[i]][j] += t;
                }
            }
        } else {
            for (ll j = prev[i] + x[i]; j < m; j += x[i] + y[i]) {
                int lg = j;
                int rg = min((ll)m - 1, j + y[i] - 1);
                total.add(lg, rg, t);
            }
        }
        int ans = total.gett(z);
        for (int j = 1; j <= X; j++) {
            ans += small[j][z % j];
        }
        cout << ans << "\n";
    }
    return 0;
}