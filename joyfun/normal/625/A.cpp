#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long n, a, b, c;

int main() {
    scanf("%lld%lld%lld%lld", &n, &a, &b, &c);
    if (a < b - c) {
        printf("%lld\n", n / a);
    } else {
        long long ans = 0;
        if (n >= b) {
            ans += (n - b) / (b - c) + 1;
            n -= ans * (b - c);
        }
        ans += n / a;
        printf("%lld\n", ans);
    }
    return 0;
}