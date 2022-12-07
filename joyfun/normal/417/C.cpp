#include <stdio.h>
#include <string.h>

int n, k;

int main() {
    scanf("%d%d", &n, &k);
    if ((n - k) <= k) printf("-1\n");
    else {
        printf("%d\n", n * k);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                int a = i, b = i + j;
                if (b > n) b -= n;
                printf("%d %d\n", a, b);
            }
        }
    }
    return 0;
}