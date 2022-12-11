#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1010;
const int mo = 1e9 + 7;

int qpow(int a, int b, int mo) {
	int ans = 1;
	for( ; b >= 1; b >>= 1, a = 1ll * a * a % mo)
		if(b & 1) ans = 1ll * ans * a % mo;
	return ans;
}

int n, m, x[N], y[N], ans[N][N];
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			ans[i][j] = -1;
	for(int i = 1; i <= n; i ++) {
		scanf("%d", x + i);
		for(int j = 1; j <= x[i]; j ++) {
			ans[i][j] = 1;
		}
		ans[i][x[i] + 1] = 0;
	}
	int res = 1;
	for(int i = 1; i <= m; i ++) {
		scanf("%d", y + i);
		for(int j = 1; j <= y[i]; j ++) {
			if(ans[j][i] == 0) res = 0;
			ans[j][i] = 1;
		}
		if(y[i] < n && ans[y[i] + 1][i] == 1) {
			res = 0;
		} 
		ans[y[i] + 1][i] = 0;
	}
	int cnt = 0;
	for(int i = 1; i <= n; i += 1)
		for(int j = 1; j <= m; j ++)
			if(ans[i][j] == -1) cnt ++;
	printf("%d\n", res * qpow(2, cnt, mo) % mo);
	return 0;
}