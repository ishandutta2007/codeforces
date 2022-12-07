#include <cstdio>
#include <cstring>

int n, m, a, b;

int solve() {
    if (b >= m * a) return a * n;
    int yu = n % m;
    int ans = n / m * b;
    if (yu * a < b) return ans + yu * a;
    return ans + b;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &a, &b);
    printf("%d\n", solve());
    return 0;
}