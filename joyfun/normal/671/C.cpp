#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 200005;
const int INF = 0x3f3f3f3f;

int n, a[N];
vector<int> g[N];

#define lson(x) (x<<1)
#define rson(x) ((x<<1)|1)

struct Node {
    int Min[2], cnt;
    long long sum;
    void gao(int f) {
        if (f <= Min[0]) return;
        sum += 1LL * (f - Min[0]) * cnt;
        Min[0] = f;
    }
} node[N * 4];

void pushdown(int x) {
    node[lson(x)].gao(node[x].Min[0]);
    node[rson(x)].gao(node[x].Min[0]);
}

void pushup(int x) {
    node[x].sum = node[lson(x)].sum + node[rson(x)].sum;
    for (int i = 0; i < 2; i++) node[x].Min[i] = min(node[lson(x)].Min[i], node[rson(x)].Min[i]);
    node[x].cnt = 0;
    for (int i = 0; i < 2; i++) {
        if (node[x].Min[0] == node[(x<<1)|i].Min[0]) node[x].cnt += node[(x<<1)|i].cnt;
        else node[x].Min[1] = min(node[x].Min[1], node[(x<<1)|i].Min[0]);
    }
}

void build(int L, int R, int x = 1) {
    if (L == R) {
        node[x].Min[0] = L;
        node[x].Min[1] = INF;
        node[x].cnt = 1;
        node[x].sum = 0;
        return;
    }
    int mid = (L + R)>>1;
    build(L, mid, lson(x));
    build(mid + 1, R, rson(x));
    pushup(x);
}

void add(int l, int r, int val, int L = 1, int R = n, int x = 1) {
    if (l > r) return;
    if (L >= l && R <= r && val <= node[x].Min[1]) {
        node[x].gao(val);
        return;
    }
    int mid = (L + R)>>1;
    pushdown(x);
    if (l <= mid) add(l, r, val, L, mid, lson(x));
    if (r > mid) add(l, r, val, mid + 1, R, rson(x));
    pushup(x);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                g[j].push_back(i);
                if (a[i] / j != j) g[a[i] / j].push_back(i);
            }
        }
    }
    long long ans = 0;
    build(1, n);
    long long pre = 0;
    for (int i = 200000; i >= 1; i--) {
        int sz = (int)g[i].size();
        if (sz < 2) continue;
        add(1, g[i][0], g[i][sz - 2]);
        add(g[i][0] + 1, g[i][1], g[i][sz - 1]);
        add(g[i][1] + 1, n, n + 1);
        ans += (node[1].sum - pre) * i;
        pre = node[1].sum;
    }
    printf("%lld\n", ans);
    return 0;
}