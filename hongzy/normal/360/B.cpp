#include <cstdio>

#define abs(x) ((x) > 0 ? (x) : -(x))
#define up(x, y) if(x < y) x = y

int n, k, a[2018], dp[2018];

bool Check(int mid) {
    int ans = dp[0] = 0;
    for(int i = 1; i <= n; i ++) {
        dp[i] = 1;
        for(int j = 1; j < i; j ++) {
            if(abs(a[i] - a[j]) * 1ll <= mid * 1ll * (i - j)) 
                up(dp[i], dp[j] + 1);
        }
        up(ans, dp[i]);
    }
    return n - ans <= k;
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    
    int l = 0, r = 2e9, ans = -1, mid;
    for(; l <= r; ) {
        mid = 1ll*l + r >> 1;
        Check(mid) ? (r = (ans = mid) - 1) : (l = mid + 1);
    }
    printf("%d\n", ans);
    return 0;
}