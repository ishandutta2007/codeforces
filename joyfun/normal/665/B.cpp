#include <cstdio>

const int N =105;

int n, m, k;
int a[N];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; i++) scanf("%d", &a[i]);
    int ans = 0;
    int x;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &x);
            for (int s = 1; s <= k; s++) {
                if (a[s] == x) {
                    ans += s;
                    for (int b = s - 1; b >= 1; b--)
                        a[b + 1] = a[b];
                    a[1] = x;
                    break;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}