#include <stdio.h>
#include <string.h>

int p, x, ans[1000005];

int main() {
    scanf("%d%d", &p, &x);
    int yu = 0;
    for (int i = 0; i <= 9; i++) {
        int s = i; int j; yu = 0;
        for (j = 0; j < p; j++) {
            ans[j] = s;
            int ji = s * x + yu;
            s = ji % 10;
            yu = ji / 10;
        }
        if (s == i && j == p && ans[p - 1] != 0 && yu == 0) {
            for (int j = p - 1; j >= 0; j--)
                printf("%d", ans[j]);
            printf("\n");
            return 0;
        }
    }
    printf("Impossible\n");
    return 0;
}