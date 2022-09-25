#include <stdio.h>
#include <math.h>

using namespace std;

const int N = 500500;

int n, tt;
double f[N], ff[N], pw[N];

int main() {
//  freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &tt);
    f[0] = 1;
    double ans = 0;
    for (int i = 0; i < n; i++) {
        int p, t;
        scanf("%d%d", &p, &t);
        double pp = (100 - p) * 1.0 / 100;
        pw[0] = 1;
        for (int i = 1; i <= t; i++) {
            pw[i] = pw[i - 1] * pp;
            if (pw[i] < 1e-15) pw[i] = 0;
        }
        double sum = 0;
        for (int j = 0; j <= tt; j++) {
            ff[j] = sum * (1 - pp);
            if (j - t >= 0) ff[j] += f[j - t] * pw[t - 1];
            sum = sum * pp + f[j];
            if (j - t + 1 >= 0) sum -= f[j - t + 1] * pw[t - 1];
            if (sum < 1e-15) sum = 0;
        }
        for (int j = 0; j <= tt; j++) {
            if (j + t > tt) {
                ans += f[j] * pw[tt - j] * i;
            }
        }
        for (int j = 0; j <= tt; j++) f[j] = ff[j];
    }
    for (int i = 0; i <= tt; i++) ans += f[i] * n;
    printf("%.10lf\n", ans);
}