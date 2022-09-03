#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
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
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const ld eps = 1e-10;
const ll INF = (ll)(2e18 + 239);
const int BIG = (int)(1e9) + 239;
const int MOD = 998244353; // 1e9 + 7
const ll MOD2 = (ll)MOD * (ll)MOD;

namespace math {
    int sum(int a, int b) {
        a += b - MOD;
        a += (a >> 31) & MOD;
        return a;
    }

    int sub(int a, int b) {
        a -= b;
        a += (a >> 31) & MOD;
        return a;
    }

    int mul(int a, int b) {
        return 1LL * a * b % MOD;
    }

    int power(int a, int k) {
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
}

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(1e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 18) + 239;
const int B = 270;
const int X = 70;

int n, m;
int id[X][X];
int val[B];

vector<int> main_id;
vector<vector<pair<int, int>>> coef;
vector<int> res;

int cf[B], tot;

bool add() {
    for (int i = 0; i < (int)main_id.size(); i++) {
        if (cf[main_id[i]] != 0) {
            int mlt = cf[main_id[i]];
            for (const auto& t : coef[i]) {
                cf[t.first] = (81 + cf[t.first] - t.second * mlt) % 3;
            }
            tot = (81 + tot - res[i] * mlt) % 3;
        }
    }
    int cur_main = -1;
    for (int i = 0; i < m; i++) {
        if (cf[i] != 0) {
            cur_main = i;
            break;
        }
    }
    if (cur_main == -1 && tot != 0) {
        return false;
    }
    if (cur_main == -1) {
        return true;
    }
    if (cf[cur_main] == 2) {
        for (int i = 0; i < m; i++) {
            cf[i] = (2 * cf[i]) % 3;
        }
        tot = (2 * tot) % 3;
    }
    main_id.emplace_back(cur_main);
    coef.push_back({});
    for (int i = 0; i < m; i++) {
        if (cf[i] != 0) {
            coef.back().emplace_back(i, cf[i]);
        }
    }
    res.emplace_back(tot);
    return true;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            id[i][j] = -1;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        if (c > 0) {
            c--;
        }
        val[i] = c;
        id[a][b] = i;
        id[b][a] = i;
    }
    main_id.clear();
    coef.clear();
    res.clear();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int h = j + 1; h < n; h++) {
                if (id[i][j] != -1 && id[i][h] != -1 && id[j][h] != -1) {
                    tot = 0;
                    int cnt = 0;
                    memset(cf, 0, sizeof(cf));
                    if (val[id[i][j]] != -1) {
                        tot += val[id[i][j]];
                        cnt++;
                    } else {
                        cf[id[i][j]] = 1;
                    }
                    if (val[id[i][h]] != -1) {
                        tot += val[id[i][h]];
                        cnt++;
                    } else {
                        cf[id[i][h]] = 1;
                    }
                    if (val[id[h][j]] != -1) {
                        tot += val[id[h][j]];
                        cnt++;
                    } else {
                        cf[id[h][j]] = 1;
                    }
                    tot %= 3;
                    if (cnt == 3 && tot != 0) {
                        cout << "-1\n";
                        return;
                    }
                    tot = (3 - tot) % 3;
                    if (!add()) {
                        cout << "-1\n";
                        return;
                    }
                }
            }
        }
    }
    for (int i : main_id) {
        val[i] = -2;
    }
    for (int i = 0; i < m; i++) {
        if (val[i] == -1) {
            val[i] = 0;
        }
    }
    for (int i = (int)main_id.size() - 1; i >= 0; i--) {
        int id = main_id[i];
        val[id] = res[i];
        for (const auto& t : coef[i]) {
            if (t.first != id) {
                val[id] = (81 + val[id] - t.second * val[t.first]) % 3;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        cout << val[i] + 1 << " ";
    }
    cout << "\n";
#ifdef ONPC
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int h = j + 1; h < n; h++) {
                if (id[i][j] != -1 && id[i][h] != -1 && id[j][h] != -1) {
                    tot = 0;
                    tot += val[id[i][j]];
                    tot += val[id[i][h]];
                    tot += val[id[h][j]];
                    tot %= 3;
                    if (tot != 0) {
                        cout << "WA\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "OK\n";
#endif
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    //cout << fixed << setprecision(20);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}