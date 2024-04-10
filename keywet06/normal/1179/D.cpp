#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
using pil = pair<int, int64>;

const int N = 500005;

int tot, x, y, n;
int ne[N << 1], fi[N], zz[N << 1], sz[N];

int64 ans;
int64 dp[N];

struct Ask {
    int k;
    int64 b;
    double l, r;
    Ask(int _k = 0, int64 _b = 0, double _l = 0.0, double _r = 0.0) {
        k = _k;
        b = _b;
        l = _l;
        r = _r;
    }
} Stack[N];

inline void jb(int x, int y) {
    ne[++tot] = fi[x];
    fi[x] = tot;
    zz[tot] = y;
}

void dfs(int x, int y) {
    sz[x] = 1;
    vector<pil> v;
    for (int i = fi[x]; i; i = ne[i]) {
        if (zz[i] != y) dfs(zz[i], x), sz[x] += sz[zz[i]];
    }
    dp[x] = (int64)sz[x] * sz[x];
    for (int i = fi[x]; i; i = ne[i]) {
        if (zz[i] != y) {
            dp[x] = min(dp[x], dp[zz[i]] + (int64)(sz[x] - sz[zz[i]]) *
                                               (sz[x] - sz[zz[i]]));
            ans =
                min(ans, dp[zz[i]] + (int64)(n - sz[zz[i]]) * (n - sz[zz[i]]));
            v.push_back(make_pair(sz[zz[i]], dp[zz[i]]));
        }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    tot = 0;
    for (pil i : v) {
        if (tot) {
            int l = 1, r = tot;
            while (l < r) {
                int mid = (l + r) / 2;
                if (Stack[mid].r < i.first) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            ans = min(ans, (int64)Stack[l].k * i.first + Stack[l].b + i.second +
                               (int64)i.first * i.first);
        }
        int nowk = -(n - i.first) * 2;
        int64 nowb = i.second + (int64)(n - i.first) * (n - i.first);
        while (tot) {
            if (Stack[tot].k == nowk) {
                if (Stack[tot].b > nowb)
                    tot--;
                else
                    break;
                continue;
            }
            double X = (double)(Stack[tot].b - nowb) / (nowk - Stack[tot].k);
            if (X < Stack[tot].l)
                tot--;
            else {
                Stack[tot].r = X;
                Stack[++tot].l = X;
                Stack[tot].k = nowk;
                Stack[tot].b = nowb;
                Stack[tot].r = 1e18;
                break;
            }
        }
        if (!tot) Stack[++tot] = Ask(nowk, nowb, -1e18, 1e18);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        jb(x, y);
        jb(y, x);
    }
    ans = 1e18;
    dfs(1, 0);
    printf("%lld\n", (int64)n * (n - 1) / 2 + ((int64)n * n - ans) / 2);
    return 0;
}