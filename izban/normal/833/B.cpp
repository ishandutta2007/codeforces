#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1 << 16;
const int INF = (int)1.01e9;

int n, k;
int a[N];
int dp[N];

int t[N * 2], p[N * 2];

void build(int v, int tl, int tr) {
    p[v] = 0;
    if (tl == tr) {
        t[v] = dp[tl];
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
}

void push(int v, int tl, int tr) {
    if (p[v] == 0) return;
    if (tl != tr) {
        p[v * 2] += p[v];
        p[v * 2 + 1] += p[v];
    }
    t[v] += p[v];
    p[v] = 0;
}

void add(int v, int tl, int tr, int l, int r, int x) {
    push(v, tl, tr);
    if (l > r) return;
    if (l == tl && r == tr) {
        p[v] += x;
        push(v, tl, tr);
        return;
    }
    int tm = (tl + tr) >> 1;
    add(v * 2, tl, tm, l, min(r, tm), x);
    add(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
}

int get(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if (l > r) return -INF;
    if (l == tl && r == tr) return t[v];
    int tm = (tl + tr) >> 1;
    return max(get(v * 2, tl, tm, l, min(r, tm)), get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    while (scanf("%d%d", &n, &k) == 2) {
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        for (int i = 0; i <= n; i++) dp[i] = -INF;
        dp[0] = 0;
        for (int i = 0; i < k; i++) {
            build(1, 0, n);

            vector<int> last(n + 1, -1);
            for (int j = 0; j <= n; j++) {
                dp[j] = get(1, 0, n, 0, j - 1);
                if (j < n) {
                    add(1, 0, n, last[a[j]] + 1, j, 1);
                    last[a[j]] = j;
                }
            }
        }
        printf("%d\n", dp[n]);
    }

    return 0;
}