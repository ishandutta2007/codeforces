#include <stdio.h>
#include <math.h>

int main()
{
    int n, k, i;
    double sum = 0;
    int x[100], y[100];

    scanf("%d %d", &n, &k);

    for (i = 0; i < n; i++) scanf("%d %d", &x[i], &y[i]);

    for (i = 0; i < n - 1; i++) sum += sqrt((x[i] - x[i + 1]) * (x[i] - x[i + 1]) + (y[i] - y[i + 1]) * (y[i] - y[i + 1])) / 50;

    printf("%.10lf\n", sum * k);

    return 0;
}