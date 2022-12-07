#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 200005;
const int MOD = 1000000007;

int n;

struct Node {
    int x, y;
    void read() {
        scanf("%d%d", &x, &y);
        x--; y--;
    }
} node[N];

bool cmp(Node a, Node b) {
    if (a.x == b.x) return a.y < b.y;
    else return a.x < b.x;
}

int pow_mod(int x, int k) {
    int ans = 1;
    while (k) {
        if (k&1) ans = (ll)x * ans % MOD;
        x = (ll)x * x % MOD;
        k >>= 1;
    }
    return ans;
}

int dp[N], f[N], rf[N];

int C(int n, int m) {
    if (m > n) return 0;
    return (ll)f[n] * rf[m] % MOD * rf[n - m] % MOD;
}

int main() {
    f[0] = 1;
    for (int i = 1; i < N; i++) f[i] = (ll)f[i - 1] * i % MOD;
    rf[N - 1] = pow_mod(f[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) rf[i] = (ll)rf[i + 1] * (i + 1) % MOD;
    node[0].read();
    scanf("%d", &n);
    n++;
    for (int i = 1; i < n; i++) node[i].read();
    sort(node, node + n, cmp);
    for (int i = 0; i < n; i++) {
        dp[i] = C(node[i].x + node[i].y, node[i].x);
        for (int j = 0; j < i; j++) {
            if (node[j].x == node[i].x && node[j].y > node[i].y) break;
            if (node[j].y > node[i].y) continue;
            dp[i] = (dp[i] - (ll)dp[j] * C(node[i].x - node[j].x + node[i].y - node[j].y, node[i].x - node[j].x) % MOD) % MOD;
            if (dp[i] < 0) dp[i] += MOD;
        }
    }
    printf("%d\n", dp[n - 1]);
    return 0;
}