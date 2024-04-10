#include <bits/stdc++.h>

using namespace std;

const int N = 120000;

int n;
int en[N], a[N], dp[N];

int get(int k) {
    int ans = 0, now = 0, cnt = 0;
    memset(en, 0, sizeof(en[0]) * (n + 1));
    for (int i = 0; i < n; ++i) {
        ++en[a[i]];
        if (en[a[i]] == 1) ++cnt;
        if (cnt > k) {
            ++ans;
            for (int j = now; j < i; ++j) --en[a[j]];
            cnt = 1, now = i;
        }
    }
    return ans + 1;
}

void solve(int l, int r) {
    if (r - l <= 1) return;
    if (dp[l] == dp[r]) {
        for (int i = l + 1; i < r; ++i) dp[i] = dp[l];
        return;
    }
    int m = (l + r) >> 1;
    dp[m] = get(m), solve(l, m), solve(m, r);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    dp[1] = get(1), dp[n] = get(n), solve(1, n);
    for (int i = 1; i <= n; ++i) printf("%d ", dp[i]);
    printf("\n");
    return 0;
}