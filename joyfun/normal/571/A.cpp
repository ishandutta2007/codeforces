#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a, b, c, l;

long long C(int n, int m) {
    if (m < 0 || m > n) return 0;
    long long ans = 1;
    for (int i = 0; i < m; i++)
        ans = ans * (n - i) / (i + 1);
    return ans;
}

long long cal(int a, int b, int c, int l) {
    if (a - b - c < 0) return 0;
    return C(min(a - b - c, l) + 2, 2);
}

int main() {
    scanf("%d%d%d%d", &a, &b, &c, &l);
    long long ans = C(l + 3, 3);
    for (int i = 0; i <= l; i++) {
        ans -= cal(a + i, b, c, l - i);
        ans -= cal(b + i, a, c, l - i);
        ans -= cal(c + i, a, b, l - i);
    }
    printf("%lld\n", ans);
    return 0;
}