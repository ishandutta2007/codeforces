#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 200005;
const ll MOD = 1000000007;

ll r, g;
int n;
ll dp[N];

int main() {
    scanf("%lld%lld", &r, &g);
    if (r > g) swap(r, g);
    ll sum = 0;
    for (int i = 1; ;i++) {
        sum += i;
        if (sum >= r + g) {
            if (sum > r + g) {
                sum -= i;
                i--;
            }
            n = i;
            break;
        }
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = r; j >= i; j--) {
            dp[j] = dp[j] + dp[j - i];
            if (dp[j] > MOD) dp[j] -= MOD;
        }
    }
    ll sb = 0;
    for (int i = 0; i <= r + g - sum; i++) {
        if (r < i) break;
        sb = (dp[r - i] + sb) % MOD;
    }
    printf("%lld\n", sb);
    return 0;
}