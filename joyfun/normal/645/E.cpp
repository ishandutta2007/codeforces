#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 1000005;
const int MOD = 1000000007;

int n, k, m, dp[N * 2], v[26];
char str[N];

priority_queue<int, vector<int>, greater<int> > Q;

int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", str + 1);
    m = strlen(str + 1);
    for (int i = 1; i <= m; i++) {
        int c = str[i] - 'a';
        if (v[c] == 0) dp[i] = (2 * dp[i - 1] % MOD + 1) % MOD;
        else dp[i] = (2 * dp[i - 1] % MOD - dp[v[c] - 1] + MOD) % MOD;
        v[c] = i;
    }
    for (int i = 0; i < k; i++) Q.push(v[i]);
    for (int i = m + 1; i <= n + m; i++) {
        int x = Q.top(); Q.pop();
        if (x == 0) dp[i] = (2 * dp[i - 1] % MOD + 1) % MOD;
        else dp[i] = (2 * dp[i - 1] % MOD - dp[x - 1] + MOD) % MOD;
        Q.push(i);
    }
    printf("%d\n", (dp[n + m] + 1) % MOD);
    return 0;
}