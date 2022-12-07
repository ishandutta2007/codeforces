#include <stdio.h>
#include <string.h>

int n;
__int64 num[200005], sum[200005];

int main() {
    scanf("%d", &n);
    int i;
    for (i = 1; i <= n; i++) {
        scanf("%I64d", &num[i]);
    }
    num[n + 1] = -1;
    for (i = n + 1; i >= 1; i--)
        if (num[i] == 0) {
            sum[i - 1] = sum[i] + 1;
        }
        else sum[i - 1] = sum[i];
    __int64 ans = 0;
    for (i = 1; i <= n; i++)
        if (num[i] == 1) {
            ans += sum[i];
        }
    printf("%I64d\n", ans);
    return 0;
}