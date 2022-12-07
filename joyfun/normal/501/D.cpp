#include <cstdio>
#include <cstring>

#define lowbit(x) (x&(-x))

const int N = 200005;

int n, a[N];

int bit[N];

void add(int x, int v) {
    while (x <= n) {
    bit[x] += v;
    x += lowbit(x);
    }
}

int query(int x) {
    int ans = 0;
    while (x) {
    ans += bit[x];
    x -= lowbit(x);
    }
    return ans;
}

int find(int x) {
    int l = 1, r = n;
    while (l < r) {
    int mid = (l + r) / 2;
    int tmp = query(mid);
    if (tmp < x) l = mid + 1;
    else r = mid;
    }
    return l;
}

int main() {
    scanf("%d", &n);
    memset(bit, 0, sizeof(bit));
    for (int i = 1; i <= n; i++) add(i, 1);
    int x;
    for (int i = 1; i <= n; i++) {
    scanf("%d", &x); x++;
    int tmp = query(x) - 1;
    add(x, -1);
    a[i] += tmp;
    }
    for (int i = 1; i <= n; i++) add(i, 1);
    for (int i = 1; i <= n; i++) {
    scanf("%d", &x); x++;
    int tmp = query(x) - 1;
    add(x, -1);
    a[i] += tmp;
    }
    for (int i = n; i >= 1; i--) {
    a[i - 1] += a[i] / (n - i + 1);
    a[i] %= (n - i + 1);
    }
    for (int i = 1; i <= n; i++) add(i, 1);
    for (int i = 1; i <= n; i++) {
    int tmp = find(a[i] + 1);
    printf("%d ", tmp - 1);
    add(tmp, -1);
    }
    printf("\n");
    return 0;
}