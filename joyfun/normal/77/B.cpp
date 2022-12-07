#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double eps = 1e-8;
int t;
double a, b;

int dcmp(double x) {
    if (fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%lf%lf", &a, &b);
        if (dcmp(a) == 0) {
            if (dcmp(b) == 0) printf("%.12f\n", 1.0);
            else printf("%.12f\n", 0.5);
            continue;
        }
        if (dcmp(b) == 0) {
            printf("%.12f\n", 1.0);
            continue;
        }
        double s = (a * b);
        double y = a / 4;
        s += y * a / 2;
        if (dcmp(y - b) > 0) {
            double xx = (y - b) / y * a;
            s -= xx * (y - b) / 2;
        }
        printf("%.12f\n", s / (a * b * 2));
    }
    return 0;
}