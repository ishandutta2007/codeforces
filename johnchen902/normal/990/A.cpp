#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    long long n, m, a, b;
    scanf("%lld %lld %lld %lld", &n, &m, &a, &b);
    printf("%lld\n", min(((n + m - 1) / m * m - n) * a, (n - n / m * m) * b));
}