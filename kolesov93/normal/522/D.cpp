#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 500011;
typedef pair<int, int> pii;
struct tree {
    int l, r, mn;
} a[N*4];
int where[N];
vector<int> q[N];
int initValue[N];
pii b[N];
int nxt[N];
int l[N], r[N];
int ans[N];

void build(int x, int l, int r) {
    a[x].l = l; a[x].r = r;

    if (l != r) {
        build(x + x, l, (l + r) >> 1);
        build(x + x + 1, ((l + r) >> 1) + 1, r);
        a[x].mn = min(a[x + x].mn, a[x + x + 1].mn);
    } else {
        a[x].mn = initValue[l];
        where[l] = x;
    }
}

void exclude(int pos) {
    pos = where[pos];
    a[pos].mn = 1e9;
    for (pos >>= 1; pos; pos >>= 1) {
        a[pos].mn = min(a[pos + pos].mn, a[pos + pos + 1].mn);
    }
}
int findmin(int x, int l, int r) {
    if (a[x].l > r || a[x].r < l) {
        return 1e9;
    }
    if (l <= a[x].l && a[x].r <= r) {
        return a[x].mn;
    }
    return min(findmin(x + x, l, r), findmin(x + x + 1, l, r));
}



int main() {
    memset(initValue, 63, sizeof(initValue));
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i].first);
        b[i].second = i + 1;
        initValue[i] = 1e9;
    }
    sort(b, b + n);
    for (int i = 1; i < n; ++i) {
        if (b[i - 1].first == b[i].first) {
            nxt[ b[i - 1].second ] = b[i].second;
            initValue[ b[i].second ] = b[i].second - b[i - 1].second;
        }
    }
    build(1, 1, n);

    for (int i = 0; i < m; ++i) {
        scanf("%d%d", l + i, r + i);
        q[l[i]].push_back(i);
    }

    for (int i = 1; i <= n; ++i) {
        for (size_t j = 0; j < q[i].size(); ++j) {
            int num = q[i][j];
            int result = findmin(1, l[num], r[num]);
            if (result > 1e8) {
                ans[num] = -1;
            } else {
                ans[num] = result;
            }
        }

        if (nxt[i]) {
            exclude(nxt[i]);
        }
    }

    for (int i = 0; i < m; ++i) {
        printf("%d\n", ans[i]);
    }

    return 0;
}