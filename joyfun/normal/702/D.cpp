#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int INF = 0x3f3f3f3f;

long long d, k, a, b, t;

int main() {
    scanf("%lld%lld%lld%lld%lld", &d, &k, &a, &b, &t);
    long long ans = d / k * t + d * a;
    ans = min(ans, d * b);
    if (d >= k) {
        ans = min(ans, (d - k) * b + a * k);
        long long s = d - k;
        ans = min(ans, s % k * b + s / k * t + (s - s % k) * a + k * a);
    }
    printf("%lld\n", ans);
    return 0;
}