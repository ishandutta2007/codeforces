#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, r;
        scanf("%d %d", &n, &r), --r;
        int sum = 0;
        for (int i = 0; i < n - 1; ++i) {
            int x;
            scanf("%d", &x);
            --x, sum += x;
        }
        sum %= n;
        int ans = (r - sum + n) % n;
        printf("%d\n", ans + 1);
    }
    return 0;
}