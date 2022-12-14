#include <bits/stdc++.h>

using namespace std;

int cnt[65][2];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
            int a;
            scanf("%d", &a);
            cnt[min(i + j - 2, n + m - i - j)][a]++;
        }
        int ans = 0;
        for (int i = 0; i < 65; i++) {
            if (i == n + m - (i + 2)) continue;
            ans += min(cnt[i][0], cnt[i][1]);
        }
        printf("%d\n", ans);
    }
}