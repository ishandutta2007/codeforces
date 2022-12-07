#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 505;
int n, m;
double v[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    scanf("%lf", &v[i]);
    int a, b;
    double w;
    double ans = 0;
    while (m--) {
    scanf("%d%d%lf", &a, &b, &w);
    ans = max(ans, (v[a] + v[b]) / w);
    }
    printf("%.15lf\n", ans);
    return 0;
}