#include <cstdio>
#include <cstring>

long long n, k, h, a;

int main() {
    long long ans = 0;
    long long yu = 0;
    scanf("%lld%lld%lld", &n, &h, &k);
    long long sum = 0;
    for (long long i = 1; i <= n; i++) {
        scanf("%lld", &a);
        if (sum + a > h) {
            ans += sum / k;
            sum %= k;
        }
        if (sum + a > h) {
            ans++;
            sum = 0;
        }
        sum += a;
    }
    ans += (sum + k - 1) / k;
    printf("%lld\n", ans);
    return 0;
}