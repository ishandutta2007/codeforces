#include <stdio.h>
#include <string.h>

const int N = 175;
int n;
double w[N][N], a[N][N], b[N][N];

int main() {
    int i, j;
    scanf("%d", &n);
    for (i = 0; i< n; i++)
        for (j = 0; j < n; j++)
            scanf("%lf", &w[i][j]);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            a[i][j] = (w[i][j] + w[j][i]) / 2;
            b[i][j] = (w[i][j] - w[j][i]) / 2;
        }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            printf("%.8lf ", a[i][j]);
        }
        printf("%.8lf\n", a[i][j]);
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            printf("%.8lf ", b[i][j]);
        }
        printf("%.8lf\n", b[i][j]);
    }
    return 0;
}