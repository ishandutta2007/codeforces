#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, a, b, p, q;

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

long long lcm(int a, int b) {
    return 1LL * a / gcd(a, b) * b;
}

int main() {
    scanf("%d%d%d%d%d", &n, &a, &b, &p, &q);
    printf("%lld\n", 1LL * n / a * p + 1LL * n / b * q - 1LL * min(p, q) * (n / lcm(a, b)));
    return 0;
}