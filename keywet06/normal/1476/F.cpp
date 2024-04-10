#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000000;

struct tree {
    int n;
    bool mx;
    vector<int> t;
    void fix(int v) {
        t[v] = (mx ? max(t[v * 2 + 1], t[v * 2 + 2])
                   : min(t[v * 2 + 1], t[v * 2 + 2]));
    }
    void build(int v, int l, int r) {
        if (l == r - 1)
            t[v] = (mx ? -INF : INF);
        else {
            int m = (l + r) / 2;
            build(v * 2 + 1, l, m);
            build(v * 2 + 2, m, r);
            fix(v);
        }
    }
    void upd(int v, int l, int r, int pos, int val) {
        if (l == r - 1)
            t[v] = (mx ? max(t[v], val) : min(t[v], val));
        else {
            int m = (l + r) / 2;
            if (pos < m)
                upd(v * 2 + 1, l, m, pos, val);
            else
                upd(v * 2 + 2, m, r, pos, val);
            fix(v);
        }
    }
    int get(int v, int l, int r, int L, int R) {
        if (L >= R) return (mx ? -INF : INF);
        if (l == L && r == R) return t[v];
        int m = (l + r) / 2;
        int lf = get(v * 2 + 1, l, m, L, min(R, m));
        int rg = get(v * 2 + 2, m, r, max(m, L), R);
        return (mx ? max(lf, rg) : min(lf, rg));
    }
    void upd(int pos, int val) { upd(0, 0, n, pos, val); }
    int get(int L, int R) { return get(0, 0, n, L, R); }
    void build() { return build(0, 0, n); }
    tree(){};
    tree(int n, bool mx) : n(n), mx(mx) { t.resize(4 * n); }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int _ = 0; _ < t; _++) {
        int n;
        scanf("%d", &n);
        vector<int> p(n);
        for (int i = 0; i < n; i++) scanf("%d", &p[i]);
        vector<int> dp(n + 1, -INF);
        vector<int> par(n + 1, -2);
        dp[0] = 0;
        par[0] = -1;
        vector<int> lf(n), rg(n);
        for (int i = 0; i < n; i++) {
            lf[i] = max(1, i - p[i] + 1);
            rg[i] = min(n, i + p[i] + 1);
        }
        tree sn(n + 1, false);
        tree sx(n, true);
        sn.build();
        sx.build();
        for (int i = 0; i < n; i++) sx.upd(i, rg[i]);
        sn.upd(0, 0);
        for (int i = 1; i <= n; i++) {
            int j = i - 1;
            int k = lf[j] - 1;
            int m = sn.get(k, n + 1);
            if (m != INF) {
                int nval = max(sx.get(m, i - 1), i - 1);
                if (nval > dp[i]) {
                    dp[i] = nval;
                    par[i] = m;
                }
            }
            if (dp[j] >= i && max(dp[j], rg[j]) > dp[i]) {
                dp[i] = max(dp[j], rg[j]);
                par[i] = -1;
            }
            if (dp[j] > dp[i]) {
                dp[i] = dp[j];
                par[i] = -1;
            }
            sn.upd(dp[i], i);
        }
        if (dp[n] != n)
            puts("NO");
        else {
            puts("YES");
            string ans;
            int cur = n;
            while (cur != 0) {
                if (par[cur] == -1) {
                    cur--;
                    ans += "R";
                } else {
                    int pcur = par[cur];
                    int diff = cur - pcur;
                    ans += "L";
                    for (int j = 0; j < diff - 1; j++) ans += "R";
                    cur = pcur;
                }
            }
            reverse(ans.begin(), ans.end());
            puts(ans.c_str());
        }
    }
}