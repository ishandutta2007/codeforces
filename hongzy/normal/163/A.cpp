#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 5010;
const int mo = 1e9 + 7;

char s[N], t[N];
int n, m, ans, dp[N], sum[N];

int main() {
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1); m = strlen(t + 1);
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			dp[j] = s[i] == t[j] ? sum[j - 1] + 1 : 0;
		}
		for(int j = 1; j <= m; j ++) {
			sum[j] = sum[j - 1] + dp[j];
			if(sum[j] >= mo) sum[j] -= mo;
		}
		ans += sum[m];
		if(ans >= mo) ans -= mo;
	}
	printf("%d\n", ans);
	return 0;
}