#include <cstdio>
#include <algorithm>

int main() {
    int K;
    scanf("%d", &K);
    for (int n = 1; n <= 2000; n++) {
        for (int k = 0; k < n; k++) {
            int x = (K + n) / (n - k);
            if ((K + n) % (n - k) != 0)
                continue;
            if (x > k * 1000000)
                continue;
            printf("%d\n", n);
            for (int i = 0; i < n - k - 1; i++)
                printf("%d ", 0);
            printf("-1 ");
            for (int i = 0; i < k; i++) {
                if (x > 1000000) {
                    printf("%d ", 1000000);
                    x -= 1000000;
                } else {
                    printf("%d ", x);
                    x = 0;
                }
            }
            return 0;
        }
    }
    return 0;
}