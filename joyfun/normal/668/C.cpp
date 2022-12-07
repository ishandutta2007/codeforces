#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 100005;
const double eps = 1e-8;

int n;
double a[N], b[N], x[N], y[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lf", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%lf", &b[i]);
    double sx = 0.0, sy = 0.0;
    for (int i = 1; i <= n; i++) {
        double A = -1.0;
        double B = a[i] + b[i] - sx + sy;
        double C = sx * (a[i] + b[i]) - a[i];
        double det = B * B - 4 * A * C;
        if (det < 0) det = 0.0;
        x[i] = (B + sqrt(det)) * 0.5;
        y[i] = a[i] + b[i] - x[i];
        sx += x[i];
        sy += y[i];
    }
    for (int i = 1; i <= n; i++) printf("%.12f ", x[i]); printf("\n");
    for (int i = 1; i <= n; i++) printf("%.12f ", y[i]); printf("\n");
    return 0;
}