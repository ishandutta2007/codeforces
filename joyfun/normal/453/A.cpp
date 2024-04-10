#include <cstdio>
#include <cstring>
#include <cmath>

int m, n;

int main() {
    scanf("%d%d", &m, &n);
    double ans = 0;
    for (int i = 1; i < m; i++)
	ans += pow((m - i) * 1.0 / m, n);
    printf("%.12lf\n", m * 1.0 - ans);
    return 0;
}