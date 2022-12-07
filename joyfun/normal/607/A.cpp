#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 100005;

const int INF = 0x3f3f3f3f;

int n;

struct SB {
    int a, b;

    void read() {
        scanf("%d%d", &a, &b);
    }

    bool operator < (const SB& c) const {
        return a < c.a;
    }
} sb[N];

int dp[N];

int find(int v) {
    int l = 1, r = n;
    if (sb[1].a >= v) return 0;
    while (l < r) {
        int mid = (l + r)>>1;
        if (sb[mid].a >= v) r = mid;
        else l = mid + 1;
    }
    return l - 1;
}

int solve() {
    dp[0] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int v = sb[i].a - sb[i].b;
        dp[i] = dp[find(v)] + 1;
        ans = max(ans, dp[i]);
    }
    return n - ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) sb[i].read();
    sort(sb + 1, sb + n + 1);
    printf("%d\n", solve());
    return 0;
}