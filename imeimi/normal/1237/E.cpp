#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

const int mod = 998244353;
int node, leaf;

int dfs(int x, int v, int l, int r) {
    if (node < x) {
        //debug("node:%d, val = %d\n", x, (l ^ r) + 1);
        if (l == r && l == v) {
            return -1;
        }
        if (l != r && l != v) {
            return -1;
        }
        return l ^ r;
    }
    int ret = 0, t;
    ret += t = dfs(x << 1, v ^ 1, l, v);
    if (t < 0) return -1;
    ret += t = dfs(x << 1 | 1, v, v, r);
    if (t < 0) return -1;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int n;
    cin >> n;
    int o = n + 1 & 1;
    leaf = 1;
    while (leaf * 4 - 1 <= n) leaf <<= 1;
    node = leaf - 1;
    n -= leaf + node;
    debug("leaf:%d, node:%d\n", leaf, node);
    int ans = 0;
    for (int i = 0; i < 2; ++i) {
        if (dfs(1, i, 0, o) == n) {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}