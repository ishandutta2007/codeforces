#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
long long solve(long long d, int k, int a, int b, int t) {
    if(d <= k)
        return d * a;
    if(t + k * 1LL * a >= k * 1LL * b)
        return k * 1LL * a + (d - k) * b;
    return k * 1LL * a + (d - k) / k * (t + k * 1LL * a) +
            min(t + (d % k) * a, d % k * b);
}
int main() {
    long long d;
    int k, a, b, t;
    scanf("%lld %d %d %d %d", &d, &k, &a, &b, &t);
    printf("%lld\n", solve(d, k, a, b, t));
}