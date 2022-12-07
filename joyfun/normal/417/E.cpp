#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>

int n, m;
bool check(int num) {
    int m = (int)sqrt(num);
    return m * m == num;
}

int main() {
    scanf("%d%d", &n, &m);
    int a, b, c, d, i, j;
    while (1) {
        a = rand() % 100 + 1;
        b = rand() % 100 + 1;
        c = rand() % 100 + 1;
        d = rand() % 100 + 1;
        if (check((m - 1) * a * a + b * b) && 
            check((m - 1) * c * c + d * d) && 
            check((n - 1) * a * a + c * c) && 
            check((n - 1) * b * b + d * d))
            break;
    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < m - 1; j++)
            printf("%d ", a);
        printf("%d\n", b);
    }
    for (j = 0; j < m - 1; j++)
        printf("%d ", c);
    printf("%d\n", d);
    return 0;
}