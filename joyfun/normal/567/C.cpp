#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;

map<int, ll> dp[4];

int main() {
    int n, k, a;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        if (a % k == 0) {
            dp[3][a] += dp[2][a / k];
            dp[2][a] += dp[1][a / k];
        }
        dp[1][a]++;
    }
    ll ans = 0;
    for (map<int, ll>::iterator it = dp[3].begin(); it != dp[3].end(); it++)
        ans += it->second;
    printf("%lld\n", ans);
    return 0;
}