#include <bits/stdc++.h>

using namespace std;

const int INF = int(1e9);
const int K = 20;

struct node {
    int max_val, min_val, ans, len;

    node(const node& left, const node& right) {
        len = left.len + right.len;
        max_val = max(left.max_val, right.max_val + left.len);
        min_val = min(left.min_val, right.min_val + left.len);
        ans = min(min(left.ans, right.ans),
                  min(INF, right.min_val - left.max_val + left.len));
    }

    node(int x) {
        ans = INF;
        len = 1;
        if (x == 1)
            max_val = min_val = 0;
        else {
            max_val = -INF;
            min_val = INF;
        }
    }

    node(){};
};

int cnt[1 << K];
vector<node> tree[2 << K];

void build(int v, int l, int r) {
    tree[v].resize(r - l);
    if (l == r - 1) {
        tree[v][0] = node(cnt[l]);
    } else {
        int m = (l + r) / 2;
        build(v * 2 + 1, l, m);
        build(v * 2 + 2, m, r);
        for (int i = 0; i < m - l; i++) {
            tree[v][i] = node(tree[v * 2 + 1][i], tree[v * 2 + 2][i]);
            tree[v][i + (m - l)] = node(tree[v * 2 + 2][i], tree[v * 2 + 1][i]);
        }
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    int m = 1 << k;
    build(0, 0, m);
    for (int i = 0; i < m; i++) printf("%d ", tree[0][i].ans);
    puts("");
}