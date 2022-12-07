#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const int N = 25;
const double pi = acos(-1.0);

int n;
double l, r, dp[1<<20];
struct D {
    double x, y, du;
    void scan() {
        scanf("%lf%lf%lf", &x, &y, &du);
        du = du * pi / 180.0;
        x -= l;
    }
} d[N];

double cal(int i, double x0) {
    double dx = x0 - d[i].x;
    double dy = -d[i].y;
    double x1 = dx * cos(d[i].du) - dy * sin(d[i].du);
    double y1 = dx * sin(d[i].du) + dy * cos(d[i].du);
    if (fabs(y1) < 1e-12 || y1 > 0) return r;
    return min(r, d[i].x - d[i].y * x1 / y1);
}

void init() {
    scanf("%d%lf%lf", &n, &l, &r); r -= l;
    for (int i = 0; i < n; i++)
        d[i].scan();
}

double solve() {
    for (int i = 0; i < (1<<n); i++) {
        for (int j = 0; j < n; j++) {
            if (i&(1<<j)) continue;
            dp[i|(1<<j)] = max(dp[i|(1<<j)], cal(j, dp[i]));
        }
    }
    return dp[(1<<n) - 1];
}

int main() {
    init();
    printf("%.9lf\n", solve());
    return 0;
}