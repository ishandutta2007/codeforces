#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int N = 200005;
const int MOD = 1000000007;

int pow_mod(int x, int k) {
    int ans = 1;
    while (k) {
        if (k&1) ans = 1LL * ans * x % MOD;
        x = 1LL * x * x % MOD;
        k >>= 1;
    }
    return ans;
}

int n, m, k, s, f[N], rf[N];

int C(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return 1LL * f[n] * rf[m] % MOD * rf[n - m] % MOD;
}

struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
    void read() {
        scanf("%d%d", &x, &y);
    }
    bool operator < (const Point& c) const {
        if (x != c.x) return x < c.x;
        return y < c.y;
    }
} p[N];

int c[50], cn;

int dp[N][50];

int main() {
    f[0] = 1; for (int i = 1; i < N; i++) f[i] = 1LL * f[i - 1] * i % MOD;
    rf[N - 1] = pow_mod(f[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) rf[i] = 1LL * rf[i + 1] * (i + 1) % MOD;
    scanf("%d%d%d%d", &n, &m, &k, &s);
    cn = 1;
    c[1] = s;
    for (int i = 2; ; i++) {
        s = (s + 1) / 2;
        c[i] = s;
        cn++;
        if (s == 1) break;
    }
    for (int i = 1; i <= k; i++) p[i].read();
    p[0] = Point(1, 1); p[++k] = Point(n, m);
    sort(p, p + k + 1);
    dp[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int x = 1; x <= cn; x++) {
            for (int j = 0; j < i; j++) {
                if (p[j].x > p[i].x || p[j].y > p[i].y) continue;
                int dx = p[i].x - p[j].x;
                int dy = p[i].y - p[j].y;
                int tmp = C(dx + dy, dx);
				dp[i][x] = (dp[i][x] + 1LL * tmp * dp[j][x - 1] % MOD) % MOD;
                dp[i][x] = (dp[i][x] - 1LL * tmp * dp[j][x] % MOD + MOD) % MOD;
            }
        }
    }
    int ans = C(n + m - 2, n - 1);
    for (int i = 1; i <= cn; i++) {
        ans = (ans + 1LL * dp[k][i] * (c[i] - 1) % MOD) % MOD;
    }
    //printf("%d\n", ans);
    ans = 1LL * ans * pow_mod(C(n + m - 2, n - 1), MOD - 2) % MOD;
    printf("%d\n", ans);
    return 0;
}