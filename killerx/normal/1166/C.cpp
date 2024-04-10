#include <bits/stdc++.h>
using namespace std;
int a[200005];
int n;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
        if (a[i] < 0) a[i] = -a[i];
    }
    sort(a, a + n);
    long long ans = 0;
    for (int i = 0; i < n; ++ i) {
        int ps = upper_bound(a, a + n, a[i] + a[i]) - a;
        ans += ps - i - 1;
    }
    printf("%lld\n", ans);
    return 0;
}