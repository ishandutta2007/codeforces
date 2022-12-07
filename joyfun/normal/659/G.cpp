#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1000005;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;

void add(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int n, h[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
        h[i]--;
    }
    h[n + 1] = INF;
    int ans = h[1], sum = min(h[1], h[2]);
    for (int i = 2; i <= n; i++) {
        add(ans, h[i]);
        add(ans, 1LL * sum * min(h[i - 1], h[i]) % MOD);
        sum = 1LL * sum * min(min(h[i - 1], h[i]), h[i + 1]) % MOD;
        add(sum, min(h[i], h[i + 1]));
    }
    printf("%d\n", ans);
    return 0;
}