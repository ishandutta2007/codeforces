#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))

const int N = 100005;
int n, m, a[N], b[N], c[N * 2], i;

int main() {
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        c[i] = a[i];
    }
    for (i = 0; i < m; i++) {
        scanf("%d", &b[i]);
        c[i + n] = b[i];
    }
    sort(c, c + n + m);
    int tmp = c[m];
    __int64 ans = 0;
    for (i = 0; i < n; i++)
        ans += max(0, tmp - a[i]);
    for (i = 0; i < m; i++)
        ans += max(0, b[i] - tmp);
    printf("%I64d\n", ans);
    return 0;
}