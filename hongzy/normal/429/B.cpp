#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1010; 

int n, m, ans, a[N][N], d[4][N][N]; 

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			d[0][i][j] = max(d[0][i - 1][j], d[0][i][j - 1]) + a[i][j];
		}
	}
	for(int i = n; i >= 1; i --) {
		for(int j = m; j >= 1; j --){
			d[1][i][j] = max(d[1][i + 1][j], d[1][i][j + 1]) + a[i][j];
		}
	}
	for(int i = n; i >= 1; i --) {
		for(int j = 1; j <= m; j ++) {
			d[2][i][j] = max(d[2][i + 1][j], d[2][i][j - 1]) + a[i][j];
		}
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = m; j >= 1; j --) {
			d[3][i][j] = max(d[3][i][j + 1], d[3][i - 1][j]) + a[i][j];
		}
	}
	for(int i = 2; i < n; i ++) {
		for(int j = 2; j < m; j ++) {
			for(int k = 0; k < 4; k ++) d[k][i][j] -= a[i][j];
			//i : d0 & d2, d1 & d3 ; j : d0 & d3, d1 & d2
			ans = max(ans, d[0][i][j] + d[2][i + 1][j] + d[3][i][j + 1] + d[1][i + 1][j + 1]);
			ans = max(ans, d[0][i][j] + d[2][i + 1][j - 1] + d[3][i][j + 1] + d[1][i + 1][j]);
			ans = max(ans, d[0][i][j - 1] + d[2][i + 1][j] + d[3][i][j] + d[1][i + 1][j + 1]);
			ans = max(ans, d[0][i][j - 1] + d[2][i + 1][j - 1] + d[3][i][j] + d[1][i + 1][j]);
			ans = max(ans, d[0][i][j] + d[2][i + 1][j] + d[3][i - 1][j + 1] + d[1][i][j + 1]);
			ans = max(ans, d[0][i][j] + d[2][i + 1][j - 1] + d[3][i - 1][j + 1] + d[1][i][j]);
			ans = max(ans, d[0][i][j - 1] + d[2][i + 1][j] + d[3][i - 1][j] + d[1][i][j + 1]);
			ans = max(ans, d[0][i][j - 1] + d[2][i + 1][j - 1] + d[3][i - 1][j] + d[1][i][j]);
			ans = max(ans, d[0][i - 1][j] + d[2][i][j] + d[3][i][j + 1] + d[1][i + 1][j + 1]);
			ans = max(ans, d[0][i - 1][j] + d[2][i][j - 1] + d[3][i][j + 1] + d[1][i + 1][j]);
			ans = max(ans, d[0][i - 1][j - 1] + d[2][i][j] + d[3][i][j] + d[1][i + 1][j + 1]);
			ans = max(ans, d[0][i - 1][j - 1] + d[2][i][j - 1] + d[3][i][j] + d[1][i + 1][j]);
			ans = max(ans, d[0][i - 1][j] + d[2][i][j] + d[3][i - 1][j + 1] + d[1][i][j + 1]);
			ans = max(ans, d[0][i - 1][j] + d[2][i][j - 1] + d[3][i - 1][j + 1] + d[1][i][j]);
			ans = max(ans, d[0][i - 1][j - 1] + d[2][i][j] + d[3][i - 1][j] + d[1][i][j + 1]);
			ans = max(ans, d[0][i - 1][j - 1] + d[2][i][j - 1] + d[3][i - 1][j] + d[1][i][j]);
//			printf("i, j = %d, %d ans = %d\n", i, j, ans);
			for(int k = 0; k < 4; k ++) d[k][i][j] += a[i][j];
		}
	}
	printf("%d\n", ans);
	return 0;
}