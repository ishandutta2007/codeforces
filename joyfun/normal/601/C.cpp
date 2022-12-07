#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 105;
const int M = 100005;

int n, m, x[N];
double dp[M], sum[M];

int main() {
    scanf("%d%d", &n, &m);
    int s = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
        s += x[i];
    }
    if (m == 1) {
        printf("%.12f\n", 1.0);
        return 0;
    }
    sum[0] = 1;
    for (int i = 1; i <= m * n; i++) sum[i] += sum[i - 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m * i; j++) {
            double tmp = sum[j - 1];
            if (j - m - 1 >= 0) tmp -= sum[j - m - 1];
            if (j - x[i] >= 0) tmp -= sum[j - x[i]];
            if (j - x[i] - 1 >= 0) tmp += sum[j - x[i] - 1];
            tmp *= 1.0 / (m - 1);
            dp[j] = tmp;
        }
        sum[0] = 0;
        if (i != n) for (int j = 1; j <= m * (i + 1); j++) sum[j] = sum[j - 1] + dp[j];
    }
    double p = 0;
    for (int i = 0; i < s; i++) p += dp[i];
    printf("%.12f\n", p * (m - 1) + 1);
    return 0;
}