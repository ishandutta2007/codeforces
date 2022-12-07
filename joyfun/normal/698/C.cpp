#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = (1<<21);
const double eps = 1e-8;
double dp[N], p[25];
int n, k;
int bitc[N];

int dcmp(double x) {
    if (fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}

int main() {
    scanf("%d%d", &n, &k);
    int sb = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lf", &p[i]);
        if (dcmp(p[i]) != 0) sb++;
    }
    if (sb <= k) {
        for (int i = 0; i < n; i++) {
            if (dcmp(p[i]) != 0) printf("%.12f ", 1.0);
            else printf("%.12f ", 0.0);
        }
        printf("\n");
        return 0;
    }
    dp[0] = 1.0;
    for (int i = 1; i < (1<<n); i++) {
        double sum = 0;
        for (int j = 0; j < n; j++) {
            if (i&(1<<j)) {
                bitc[i] = bitc[i^(1<<j)] + 1;
                sum += p[j];
               // printf("%d %f %f\n", i^(1<<j), dp[i^(1<<j)], p[j]);
                dp[i] += dp[i^(1<<j)] * p[j];
            }
        }
        if (bitc[i] < k) dp[i] /= (1.0 - sum);
        //printf("%d %f\n", i, dp[i]);
    }
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < (1<<n); j++) {
            if ((j&(1<<i)) && bitc[j] == k) sum += dp[j];
        }
        printf("%.12f ", sum);
    }
    printf("\n");
    return 0;
}