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
const int MOD = 998'244'353;
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
const int T = (1 << 18) + 239;
const int B = 500;
const int X = 110;

int n, cnt[M][2], p[M], k, s[M];
vector<int> v[M];
ll dp[M][2];

void dfs(int i) {
    if (i != 0) {
        cnt[i][0] = (cnt[p[i]][0] / (int) v[p[i]].size());
        cnt[i][1] = ((cnt[p[i]][1] + (int) v[p[i]].size() - 1) / (int) v[p[i]].size());
        assert(cnt[i][1] <= cnt[i][0] + 1);
    }
    for (int t = 0; t < 2; t++) {
        dp[i][t] = (ll)cnt[i][t] * s[i];
    }
    if (v[i].empty()) {
        return;
    }
    for (int j : v[i]) {
        dfs(j);
    }
    for (int t = 0; t < 2; t++) {
        int need = cnt[i][t];
        int lw = need / (int)v[i].size();
        int up = (need + (int)v[i].size() - 1) / (int)v[i].size();
        int cnt_up = need % (int)v[i].size();
        vector<ll> can;
        for (int j : v[i]) {
            ll lw_score = 0;
            if (cnt[j][0] == lw) {
                lw_score = dp[j][0];
            } else {
                assert(cnt[j][1] == lw);
                lw_score = dp[j][1];
            }
            ll up_score = 0;
            if (cnt[j][0] == up) {
                up_score = dp[j][0];
            } else {
                assert(cnt[j][1] == up);
                up_score = dp[j][1];
            }
            dp[i][t] += lw_score;
            can.emplace_back(up_score - lw_score);
        }
        sort(can.rbegin(), can.rend());
        for (int j = 0; j < cnt_up; j++) {
            dp[i][t] += can[j];
        }
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        v[i].clear();
    }
    for (int i = 1; i < n; i++) {
        cin >> p[i];
        p[i]--;
        v[p[i]].emplace_back(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    cnt[0][0] = k;
    cnt[0][1] = k;
    dfs(0);
    cout << dp[0][0] << "\n";
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