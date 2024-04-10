#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 5005;
const int MOD = 1000000007;

int n, m, sol_cnt, sol_res;
int s[MAXN], col[MAXN], br[MAXN], lef[MAXN], rig[MAXN];
vector <int> v[MAXN], c[MAXN];

int mul (int a, int b) {return (llint) a * b % MOD;}
int add (int a, int b) {a += b; if (a >= MOD) return a - MOD; return a;}

void precompute () {
    for (int i = 1; i <= m; i++) {
        if (br[i] <= v[col[i]].size()) {
            lef[i] = v[col[i]][br[i] - 1];
            rig[i] = v[col[i]][v[col[i]].size() - br[i]];
        } else {
            lef[i] = n + 1;
            rig[i] = 0;
        }
    }
}

void calc_zero () {
    int cnt = 0, res = 1;
    for (int i = 1; i <= n; i++) {
        if (c[i].empty()) continue;
        int R = 0;
        for (auto x : c[i]) {
            if (1 <= rig[x]) R++;
        }
        if (R > 0) cnt++, res = mul(res, R);
    }
    sol_cnt = cnt; sol_res = res;
}

void calc (int ind) {
    int cnt = 1, res = 1;
    for (int i = 1; i <= n; i++) {
        if (c[i].empty()) continue;
        int L = 0, R = 0, M = 0;
        for (auto x : c[i]) {
            if (lef[x] < lef[ind]) L++;
            if (lef[ind] < rig[x]) R++;
            if (lef[x] < lef[ind] && lef[ind] < rig[x]) M++;
        }
        int cnt2 = L * R - M;
        int cnt1 = L + R;
        if (i != col[ind]) {
            if (cnt2 > 0) {
                cnt += 2; res = mul(res, cnt2);
            } else if (cnt1 > 0) {
                cnt += 1; res = mul(res, cnt1);
            }
        } else {
            if (lef[ind] < rig[ind]) R--;
            if (R > 0) cnt += 1, res = mul(res, R);
        }
    }
    if (cnt > sol_cnt) sol_cnt = cnt, sol_res = res; else if (cnt == sol_cnt) sol_res = add(sol_res, res);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        v[s[i]].push_back(i);
    }
    for (int i = 1; i <= m; i++) {
        cin >> col[i] >> br[i];
        c[col[i]].push_back(i);
    }
    precompute();
    calc_zero();
    for (int i = 1; i <= m; i++) {
        if (lef[i] <= n) calc(i);
    }
    cout << sol_cnt << " " << sol_res;
    return 0;
}