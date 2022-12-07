#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2005;
const int M = 5005;

int n, a[N];
long long cnt[M], sum[M];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++)
            cnt[a[j] - a[i]]++;
    }
    for (int i = 5000; i >= 1; i--)
        sum[i] = sum[i + 1] + cnt[i];
    double ans = 0;
    double sb = 1.0 * n * (n - 1) / 2;
    for (int i = 1; i <= 5000; i++) {
        if (cnt[i] == 0) continue;
        for (int j = 1; j <= 5000; j++) {
            if (cnt[j] == 0) continue;
            if (i + j + 1 > 5000) break;
            double p1 = cnt[i] * 1.0 / sb;
            double p2 = cnt[j] * 1.0 / sb;
            double p3 = sum[i + j + 1] * 1.0 / sb;
            ans += p1 * p2 * p3;
        }
    }
    printf("%.12f\n", ans);
    return 0;
}