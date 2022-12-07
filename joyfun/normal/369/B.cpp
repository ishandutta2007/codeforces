#include <stdio.h>
#include <string.h>

int main() {
    int i, j;
    int n, k, l, r, sall, sk;
    int save[1005], t = 0;
    scanf("%d%d%d%d%d%d", &n, &k, &l, &r, &sall , &sk);
    if (l == r)
        for (i = 0; i < n; i ++)
            save[i] = l;
    for (i = l; i < r; i ++)
        if ((i + 1) * k >= sk) {
            for (j = 0; j < k; j ++)
                save[j] = i;
            for (j = 0; j < (sk - i * k); j ++)
                save[j] ++;
            break;
        }
    for (i = l; i < r; i ++)
        if ((i + 1) * (n - k) >= sall - sk) {
            for (j = k; j < n; j ++)
                save[j] = i;
            for (j = k; j < k + (sall - sk - i * (n - k)); j ++)
                save[j] ++;
            break;
        }
    for (i = 0; i < n - 1; i ++)
        printf("%d ", save[i]);
    printf("%d\n", save[n - 1]);
    return 0;
}