#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const int N = 1e5 + 10;

int n, a[N], b[N];
ll dp[N][3];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);
	for(int i = 1; i <= n; i ++) scanf("%d", b + i);
	dp[1][0] = a[1]; dp[1][1] = b[1]; dp[1][2] = 0;
	for(int i = 2; i <= n; i ++) {
		dp[i][0] = max(dp[i - 1][1] + a[i], dp[i - 1][2] + a[i]);
		dp[i][1] = max(dp[i - 1][0] + b[i], dp[i - 1][2] + b[i]);
		dp[i][2] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
	}
	printf("%I64d\n", max(dp[n][0], max(dp[n][2], dp[n][1])));
	return 0;
}