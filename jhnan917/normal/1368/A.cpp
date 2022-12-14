#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long a, b, n, ans;
        scanf("%lld %lld %lld", &a, &b, &n);
        for (ans = 0; a <= n && b <= n; ans++) {
            if (a < b) a += b;
            else b += a;
        }
        printf("%lld\n", ans);
    }
}