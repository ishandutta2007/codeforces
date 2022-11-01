#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

long long a[N];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    if (n == 1) {
        printf("1 1\n%lld\n", -a[1]);
        printf("1 1\n%lld\n", 0ll);
        printf("1 1\n%lld\n", 0ll);
        return 0;
    }
    printf("%d %d\n", 1, n);
    for (int i = 1; i <= n; i++) {
        int mod = (a[i] % (n - 1) + n - 1) % (n - 1);
        int add = (mod == 0 ? 0 : n - 1 - mod);
        a[i] += 1ll * add * n;
        printf("%lld ", 1ll * add * n);
    }
    printf("\n");
    printf("%d %d\n", 1, n - 1);
    for (int i = 1; i < n; i++) printf("%lld ", -a[i]);
    printf("\n");
    printf("%d %d\n%lld\n", n, n, -a[n]);
    return 0;
}