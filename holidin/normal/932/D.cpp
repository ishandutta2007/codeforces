#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 2;
const int LogN = 20;
const long long inf = 1e18;

long long mx[LogN][N], sum[LogN][N], w[N], t[LogN];
int pr[LogN][N], prm[LogN][N], top = 0;

void connect(int u, int W) {
    int i;
    ++top;
    w[top] = W;
    pr[0][top] = u;
    mx[0][top] = w[u];
    for (i = 1; i < LogN; ++i) {
        pr[i][top] = pr[i - 1][pr[i - 1][top]];
        mx[i][top] = max(mx[i - 1][top], mx[i - 1][pr[i - 1][top]]);
    }
    int v = top;
    for (i = LogN - 1; i >= 0; --i)
    if (mx[i][v] < W)
        v = pr[i][v];
    v = pr[0][v];
    prm[0][top] = v;
    sum[0][top] = w[v];
    //cout << v << endl;
    for (i = 1; i < LogN; ++i) {
        prm[i][top] = prm[i - 1][prm[i - 1][top]];
        sum[i][top] = min(inf, sum[i - 1][top] + sum[i - 1][prm[i - 1][top]]);
    }
}

long long ans(int u, long long X) {
    if (w[u] > X)
        return 0;
    int cnt = 1;
    X -= w[u];
    for (int i = LogN - 1; i >= 0; --i)
    if (sum[i][u] <= X) {
        X -= sum[i][u];
        u = prm[i][u];
        cnt += t[i];
    }
    return cnt;
}

int main() {
    int i, j, q, k;
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> q;
    top = 0;
    t[0] = 1;
    w[0] = inf;
    for (i = 1; i < LogN; ++i)
        t[i] = t[i - 1] * 2;
    connect(0, 0);
    long long last = 0;
    for (i = 0; i < q; ++i) {
        long long p, q;
        cin >> j >> p >> q;
        p ^= last;
        q ^= last;
        if (j == 1)
            connect(p, q);
        else {
            last = ans(p, q);
            cout << last << "\n";
        }
    }
}