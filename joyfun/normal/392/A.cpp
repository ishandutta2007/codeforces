#include <stdio.h>
#include <string.h>
#include <math.h>

int main () {
    __int64 n, ans = 0;
    scanf("%I64d", &n);
    double R = n;
    __int64 tmp = n;
    for (int i = 1; i <= n; i++) {
        double r = i;
        __int64 k = sqrt(R*R - r*r);
        if (tmp - k == 0)
            ans += 1;
        else
            ans += tmp - k;
        tmp = k;
    }
    if (n == 0) printf("1\n");
    else printf("%I64d\n", ans * 4);
    return 0;
}