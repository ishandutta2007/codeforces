#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 1;
long long dp[N][2][2][2];
int top[N];
int a[N][2];
bool use[N];
vector <int> d[N];
vector <pair<int, int> > e[N];

int main() {
    int i, j, k, n;
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    long long ans0 = 1, ans1 = 0;
    for (i = 1; i <= n; ++i) {
        cin >> top[i];
        for (j = 0; j < top[i]; ++j) {
            cin >> a[i][j];
            d[abs(a[i][j])].push_back(i);
        }
    }
    for (i = 1; i <= k; ++i)
    if (d[i].size() > 1)
        if (d[i][0] == d[i][1]) {
            int u1, u2;
            if (a[d[i][0]][0] < 0)
                u1 = -1;
            else
                u1 = 1;
            if (a[d[i][0]][1] < 0)
                u2 = -1;
            else
                u2 = 1;
            if (u1 * u2 > 0) {
                ans0 = (ans0 + ans1) % mod;
                ans1 = ans0;
            } else {
                swap(ans0, ans1);
                ans0 = (ans0 * 2) % mod;
                ans1 = (ans1 * 2) % mod;
            }
            top[d[i][0]] = 0;
        } else {
            e[d[i][0]].push_back({d[i][1], i});
            e[d[i][1]].push_back({d[i][0], i});
        }
    else if (d[i].size() == 0) {
            ans0 = (ans0 * 2) % mod;
            ans1 = (ans1 * 2) % mod;
        }
    for (i = 1; i <= n; ++i)
    if (top[i] == 2 && e[i].size() == 0) {
        long long c0 = 0, c1 = 0;
        c0 = (3 * ans1 + ans0) % mod;
        c1 = (3 * ans0 + ans1) % mod;
        ans0 = c0;
        ans1 = c1;
        top[i] = 0;
    }
    for (i = 1; i <= n; ++i)
    if (top[i] == 1 && e[i].size() == 0) {
        ans0 = (ans0 + ans1) % mod;
        ans1 = ans0;
        top[i] = 0;
    }
    for (i = 1; i <= n; ++i)
    if (top[i] > 0 && e[i].size() == 1 && !use[i]) {
        vector <int> v, inv1, inv2;
        v.push_back(i);
        inv1.push_back(a[i][1] < 0);
        inv2.push_back(a[i][0] < 0);
        for (j = 0; j < v.size(); ++j) {
            use[v[j]] = 1;
            for (int l = 0; l < e[v[j]].size(); ++l)
            if (j == 0 || e[v[j]][l].fi != v[j - 1]) {
                v.push_back(e[v[j]][l].fi);
                for (int pp = 0; pp < 2; ++pp)
                if (abs(a[e[v[j]][l].fi][pp]) == e[v[j]][l].se) {
                    inv1.push_back(a[e[v[j]][l].fi][pp] < 0);
                    inv2.push_back(a[e[v[j]][l].fi][1 - pp] < 0);
                }
            }
        }
        if (e[v[0]][0].se == abs(a[i][1]))
            swap(inv1[0], inv2[0]);
        for (j = 0; j <= v.size(); ++j)
        for (int p = 0; p < 2; ++p)
        for (int i1 = 0; i1 < 2; ++i1)
        for (int j1 = 0; j1 < 2; ++j1)
            dp[j][p][i1][j1] = 0;
        if (top[i] == 1)
            dp[0][0][0][0] = 1;
        else {
            dp[0][0][0][1] = 1;
            dp[0][0][0][0] = 1;
        }
        for (j = 0; j < v.size() - 1; ++j)
        for (int p = 0; p < 2; ++p)
        for (int i1 = 0; i1 < 2; ++i1)
        for (int j1 = 0; j1 < 2; ++j1) {
            dp[j][p][i1][j1] %= mod;
            for (int l = 0; l < 2; ++l) {
                dp[j + 1][p][(i1 ^ ((j1 ^ inv1[j]) | (l ^ inv2[j])))][l] += dp[j][p][i1][j1];
            }
        }
        long long as[2];
        as[0] = as[1] = 0;
        if (top[v[v.size() - 1]] == 1) {
            for (int p = 0; p < 2; ++p)
            for (int i1 = 0; i1 < 2; ++i1)
            for (int j1 = 0; j1 < 2; ++j1) {
                as[(i1 ^ j1 ^ inv1[v.size() - 1])] += dp[v.size() - 1][p][i1][j1];
            }
        } else {
            for (int p = 0; p < 2; ++p)
            for (int i1 = 0; i1 < 2; ++i1)
            for (int j1 = 0; j1 < 2; ++j1)
            for (int l = 0; l < 2; ++l) {
                as[(i1 ^ ((j1 ^ inv1[v.size() - 1]) | (l ^ inv2[v.size() - 1])))] += dp[v.size() - 1][p][i1][j1];
            }
        }
        long long c0, c1;
        as[0] %= mod;
        as[1] %= mod;
        c0 = (ans0 * as[0] + ans1 * as[1]) % mod;
        c1 = (ans1 * as[0] + ans0 * as[1]) % mod;
        ans0 = c0;
        ans1 = c1;
    }
    for (i = 1; i <= n; ++i)
    if (top[i] == 2 && !use[i]) {
        vector <int> v, inv1, inv2;
        v.push_back(i);
        inv1.push_back(a[i][0] < 0);
        inv2.push_back(a[i][1] < 0);
        for (j = 0; j < v.size(); ++j) {
            use[v[j]] = 1;
            for (int l = 0; l < e[v[j]].size(); ++l)
            if (j == 0 || (e[v[j]][l].fi != v[j - 1] && e[v[j]][l].fi != v[0])) {
                v.push_back(e[v[j]][l].fi);
                for (int pp = 0; pp < 2; ++pp)
                if (abs(a[e[v[j]][l].fi][pp]) == e[v[j]][l].se) {
                    inv1.push_back(a[e[v[j]][l].fi][pp] < 0);
                    inv2.push_back(a[e[v[j]][l].fi][1 - pp] < 0);
                }
                break;
            }
        }
        if (e[v[0]][0].se == abs(a[i][1]))
            swap(inv1[0], inv2[0]);
        for (j = 1; j <= v.size(); ++j)
        for (int p = 0; p < 2; ++p)
        for (int i1 = 0; i1 < 2; ++i1)
        for (int j1 = 0; j1 < 2; ++j1)
            dp[j][p][i1][j1] = 0;
        dp[1][0][0][0] = 1;
        dp[1][1][0][1] = 1;
        for (j = 1; j < v.size(); ++j)
        for (int p = 0; p < 2; ++p)
        for (int i1 = 0; i1 < 2; ++i1)
        for (int j1 = 0; j1 < 2; ++j1) {
            dp[j][p][i1][j1] %= mod;
            for (int l = 0; l < 2; ++l) {
                int u = (i1 ^ ((j1 ^ inv1[j]) | (l ^ inv2[j])));
                dp[j + 1][p][(i1 ^ ((j1 ^ inv1[j]) | (l ^ inv2[j])))][l] += dp[j][p][i1][j1];
            }
        }
        long long as[2];
        as[0] = as[1] = 0;
        for (int p = 0; p < 2; ++p)
        for (int i1 = 0; i1 < 2; ++i1)
        for (int j1 = 0; j1 < 2; ++j1) {
            as[(i1 ^ ((j1 ^ inv2[0]) | (p ^ inv1[0])))] += dp[v.size()][p][i1][j1];
        }
        long long c0, c1;
        as[0] %= mod;
        as[1] %= mod;
        c0 = (ans0 * as[0] + ans1 * as[1]) % mod;
        c1 = (ans1 * as[0] + ans0 * as[1]) % mod;
        ans0 = c0;
        ans1 = c1;
    }
    cout << ans1 << endl;
}