#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

constexpr int mod = 1000000007;

int modpow(int a, int b) {
    if (b == 0)
        return 1;
    int x = modpow(a, b / 2);
    x = (long long) x * x % mod;
    if (b % 2)
        x = (long long) x * a % mod;
    return x;
}
int inv(int x) {
    return modpow(x, mod - 2);
}

int pa, pb;
int invpb, invpapb;
bool ok[1001][1001];
int dp[1001][1001];

int solve(int k, int a) {
    if (a >= k)
        return ((a - k) + pa * 1LL * invpb) % mod;
    // a < k
    if (!ok[k][a]) {
        ok[k][a] = true;
        dp[k][a] = (pa * 1LL * solve(k, a + 1) + pb * 1LL * solve(k - a, a)) % mod * invpapb % mod;
    }
    return dp[k][a];
}

int main() {
    int k;
    scanf("%d %d %d", &k, &pa, &pb);
    invpb = inv(pb);
    invpapb = inv(pa + pb);
    printf("%d\n", (k + solve(k, 1)) % mod);
}