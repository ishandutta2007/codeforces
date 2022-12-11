#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 12;
const int mo = 1e9 + 7;

int n, m, k, a[N][N], f[N][N], lg[1 << N]; //n + m <= 11
int cnt[N], all;
int dfs(int x, int y) {
	if(x == n + 1) {
		return y == m ? 1 : dfs(1, y + 1);
	}
	int i = a[x][y], st = f[x - 1][y] | f[x][y - 1];
	if(~ i) {
		if(!(st >> i & 1)) {
			f[x][y] = st | (1 << i);
			return dfs(x + 1, y);
		}
		return 0;
	}
	if(__builtin_popcount(all ^ st) < n + m - x - y) return 0;
	int ans = 0, fir = -1;
	for(i = all ^ st; i; i &= i - 1) {
		int j = lg[i & (-i)];
		f[x][y] = st | (1 << j);
		if(!cnt[j] ++) {
			if(fir == -1) fir = dfs(x + 1, y);
			(ans += fir) %= mo;
		} else (ans += dfs(x + 1, y)) %= mo;
		cnt[j] --;
	}
	return ans;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	if(n + m - 1 > k) {
		puts("0"); return 0;
	}
	all = (1 << k) - 1;
	for(int i = 0; i < k; i ++) lg[1 << i] = i;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			scanf("%d", &a[i][j]);;
			if(~ -- a[i][j]) cnt[a[i][j]] ++;
		}
	}
	printf("%d\n", dfs(1, 1));
	return 0;
}