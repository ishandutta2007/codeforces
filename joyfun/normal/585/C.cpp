#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long x, y;
long long ans[105];
int an = 0;

long long gcd(long long x, long long y) {
    if (!y) return x;
    ans[an++] = x / y;
    long long d = gcd(y, x % y);
    return d;
}

int main() {
    scanf("%lld%lld", &x, &y);
    long long d = gcd(x, y);
    if (d != 1) printf("Impossible\n");
    else {
        if (ans[an - 1] > 0) ans[an - 1]--;
        if (ans[an - 1] == 0) an--;
        int f = (x > y);
        for (int i = !f; i < an; i++) {
            f = !f;
            printf("%lld%c", ans[i], 'A' + f);
        }
    }
    return 0;
}