#include <stdio.h>
#include <string.h>

const int MAXN = 4 * 1000005;
__int64 bit1[2][MAXN], bit2[2][MAXN];

void insert(__int64 *bit, int x, __int64 value) {
    while (x < MAXN) {
        bit[x] += value;
        x += x&(-x);
    }
}

__int64 get(__int64 *bit, int x) {
    __int64 ans = 0;
    while (x > 0) {
        ans += bit[x];
        x -= x&(-x);
    }
    return ans;
}

void Insert(int id, int l, int r, __int64 value) {
    insert(bit1[id], l, value);
    insert(bit1[id], r + 1, -value);
    insert(bit2[id], l, -value * (l - 1));
    insert(bit2[id], r + 1, value * r);
}

__int64 Get(int id, int x) {
    return get(bit1[id], x) * x + get(bit2[id], x);
}

int n, m, w;

int main() {
    scanf("%d%d%d", &n, &m, &w);
    int v, x1, y1, x2, y2;
    __int64 value;
    while (w--) {
        scanf("%d%d%d%d%d", &v, &x1, &y1, &x2, &y2);
        if (v) {
            __int64 ans = Get(1, y2) - Get(1, y1 - 1) - (Get(0, n) - Get(0, x2) + Get(0, x1 - 1));
            printf("%I64d\n", ans);
        }
        else {
            scanf("%I64d", &value);
            Insert(0, x1, x2, value * (y2 - y1 + 1));
            Insert(1, y1, y2, value * (x2 - x1 + 1));
        }
    }
    return 0;
}