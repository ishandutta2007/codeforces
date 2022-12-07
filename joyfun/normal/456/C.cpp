#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;
int n;
long long vis[N], dp[N][2];

int main() {
    int a;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
    scanf("%d", &a);
    vis[a]++;
    }
    for (long long i = 1; i <= 100000; i++) {
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
    dp[i][1] = max(dp[i][1], dp[i - 1][0] + vis[i] * i);
    }
    printf("%lld\n", max(dp[100000][0], dp[100000][1]));
    return 0;
}