#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;
int a[N], b[N], n, d, x, to[N], q[N];

int getnext() {
    x = (x * 37LL + 10007) % 1000000007;
    return x;
}

void initAB() {
    for (int i = 0; i < n; i++)
    a[i] = i + 1;
    for (int i = 0; i < n; i++)
    swap(a[i], a[getnext() % (i + 1)]);
    for (int i = 0; i < n; i++) {
    if (i < d)
        b[i] = 1;
    else
        b[i] = 0;
    }
    for (int i = 0; i < n; i++)
    swap(b[i], b[getnext() % (i + 1)]);
}

int main() {
    scanf("%d%d%d", &n, &d, &x);
    initAB();
    for (int i = 0; i < n; i++) {
    to[a[i]] = i;
    if (b[i]) q[++q[0]] = i;
    }
    int s = 30;
    for (int i = 0; i < n; i++) {
    int j;
    for (j = n; j >= n - s; j--) {
        if (j > 0 && i >= to[j] && b[i - to[j]]) {
        printf("%d\n", j);
        break;
        }
    }
    if (j < n - s) {
        int ans = 0;
        for (int j = 1; j <= q[0] && q[j] <= i; j++)
        ans = max(ans, a[i - q[j]]);
        printf("%d\n", ans);
    }
    }
    return 0;
}