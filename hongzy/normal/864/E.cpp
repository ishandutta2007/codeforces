#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 110;
struct Node {
	int t, d, p, id;
	bool operator < (const Node &b) const {
		return d < b.d;
	}
} a[N];
int n, dp[N][2010], pre[N][2010];
vector<int> ans;
void print(int x, int y) {
	if(x == 0) return ;
	print(x - 1, pre[x][y]);
	if(pre[x][y] != y) {
		ans.push_back(a[x].id);
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d%d%d", &a[i].t, &a[i].d, &a[i].p);
		a[i].id = i;
	}
	sort(a + 1, a + n + 1); dp[0][0] = 0;
	for(int i = 1; i <= n; i ++) {
		for(int j = 0; j <= 2000; j ++) {
			dp[i][j] = dp[i - 1][j];
			pre[i][j] = j;
		}
		for(int j = 0; j <= 2000; j ++) {
			if(j + a[i].t < a[i].d) {
				if(dp[i][j + a[i].t] < dp[i - 1][j] + a[i].p) {
					dp[i][j + a[i].t] = dp[i - 1][j] + a[i].p;
					pre[i][j + a[i].t] = j;
				}
			}
		}
	}
	int p = 0;
	for(int i = 1; i <= 2000; i ++) {
		if(dp[n][i] > dp[n][p]) {
			p = i;
		}
	}
	printf("%d\n", dp[n][p]);
	print(n, p);
	printf("%d\n", (int) ans.size());
	for(int i = 0; i < (int) ans.size(); i ++)
		printf("%d ", ans[i]);
	return 0;
}