#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int n, m, num;
int ans[105], b[105];
int i;
int main() {
    scanf("%d%d", &n, &m);
    for (i = 0; i < m; i++)
        scanf("%d", &b[i]);
    int e = n;
    for (i = 0; i < m; i++) {
        while (b[i] <= e && e > 0) {
            ans[e] = b[i];
            e--;
        }
    }
    for (i = 1; i < n; i++)
        printf("%d ", ans[i]);
    printf("%d\n", ans[n]);
    return 0;
}