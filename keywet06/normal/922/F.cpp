#include <bits/stdc++.h>

const int N = 300005;

bool del[N];
int n, k, cnt, limit, ans;
int val[N], prime[N];

void pre() {
    for (int i = 2; i <= n; i++) {
        if (!val[i]) prime[++cnt] = i;
        val[i]++;
        for (int j = i + i; j <= n; j += i) val[j]++;
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> k;
    pre();
    long long tot = 0;
    for (int i = 1; i <= n; i++) {
        tot += val[i];
        if (tot >= k) {
            ans = limit = i;
            break;
        }
    }
    if (tot > k) {
        for (int i = 1; i <= cnt; i++) {
            if (tot == k) break;
            if (tot - k >= limit / prime[i]) {
                del[prime[i]] = 1;
                tot -= limit / prime[i];
                ans--;
            }
        }
    }
    if (tot != k) {
        printf("No\n");
    } else {
        printf("Yes\n");
        printf("%d\n", ans);
        for (int i = 1; i <= limit; i++) {
            if (!del[i]) printf("%d ", i);
        }
        puts("");
    }
    return 0;
}