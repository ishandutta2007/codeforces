#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5;

int n, m;
int x[mxn], y[mxn];

int delta[mxn], delta1[450][mxn];
int ans[mxn];

void insert(int i, int l, int r) {
    if (x[i] + y[i] >= 450) {
        for (int j = l; j < r; j += x[i] + y[i]) {
            if (j + x[i] < r) {
                delta[j + x[i]] += 1;
                if (j + x[i] + y[i] <= r) delta[j + x[i] + y[i]] -= 1;
                else delta[r] -= 1;
            }
        }
    } else {
        for (int rem = x[i]; rem < x[i] + y[i]; ++ rem) {
            if (l + rem < r) {
                int s = l + (r - 1 - l - rem) / (x[i] + y[i]) * (x[i] + y[i]) + rem;
                delta1[x[i] + y[i]][l + rem] += 1;
                if (s + x[i] + y[i] < m) delta1[x[i] + y[i]][s + x[i] + y[i]] -= 1;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    rep(i, n) scanf("%d %d", &x[i], &y[i]);
    static int tim[mxn];
    memset(tim, -1, sizeof(tim));
    rep(tc, m) {
        int op, k;
        scanf("%d %d", &op, &k);
        -- k;
        if (op == 1) tim[k] = tc;
        else insert(k, tim[k], tc), tim[k] = -1;
    }
    rep(i, n) if (tim[i] != -1) insert(i, tim[i], m);
    rep(i, m) delta[i + 1] += delta[i];
    rep(j, 450) rep(i, m) if (i + j < m) delta1[j][i + j] += delta1[j][i];
    rep(i, m) ans[i] += delta[i];
    rep(j, 450) rep(i, m) ans[i] += delta1[j][i];
    rep(i, m) printf("%d\n", ans[i]);
	return 0;
}