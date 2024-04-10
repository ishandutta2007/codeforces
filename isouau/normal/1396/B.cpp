#include <bits/stdc++.h>
using namespace std;

int a[105];
int T, n;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int maxn = 0, sum = 0;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]), sum += a[i], maxn = max(maxn, a[i]);
        if (maxn > sum - maxn) {
            printf("T\n");
            continue;
        }
        if (sum & 1) printf("T\n");
        else printf("HL\n");
    }
    return 0;
}