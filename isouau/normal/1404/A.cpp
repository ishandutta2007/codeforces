#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

char c[N];
int T, n, k;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%s", &n, &k, c);
        int ans = 1, cnt[2] = {0, 0};
        for (int i = 0; i < k; i++) {
            int now = -1;
            for (int j = i; j < n; j += k) {
                if (c[j] == '?') continue;
                if (now == -1) now = c[j] - '0';
                else if (now != c[j] - '0') {
                    ans = 0;
                    break;
                }
            }
            if (now != -1) ++cnt[now];
        }
        if (ans && min(cnt[0], cnt[1]) + k - cnt[0] - cnt[1] >= max(cnt[0], cnt[1])) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}