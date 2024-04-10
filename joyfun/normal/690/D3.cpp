#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int MOD = 1000003;
const int N = 105;

int c, w, h;
deque<int> q;
int mi[N];
int dp[2];

int main() {
    scanf("%d%d%d", &c, &w, &h);
    mi[0] = 1; for (int i = 1; i <= w + 1; i++) mi[i] = 1LL * mi[i - 1] * h % MOD;
    q.push_back(1);
    dp[0] = 1;
    int sum = h;
    for (int i = 1; i <= c; i++) {
        dp[0] = (dp[1] + dp[0]) % MOD;
        dp[1] = sum;
        sum = (sum + dp[0]) % MOD;
        sum = 1LL * sum * h % MOD;
        q.push_back(dp[0]);
        if (q.size() > w) {
            int u = q.front();
            sum = (sum - 1LL * u * mi[w + 1] % MOD + MOD) % MOD;
            q.pop_front();
        }
    }
    printf("%d\n", (dp[0] + dp[1]) % MOD);
    return 0;
}