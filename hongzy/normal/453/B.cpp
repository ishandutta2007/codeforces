#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 110;
struct Node {
	int x, id;
	bool operator < (const Node &b) const { return x > b.x; }
} a[N];
int n, b[N];
const int p[16] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int st[60], dp[18][1 << 16], sta[18][1 << 16];
int main() {
	for(int i = 1; i < 60; i ++)
		for(int j = 0; j < 16; j ++)
			if(i % p[j] == 0) st[i] |= 1 << j;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a[i].x); a[i].id = i;
	}
	sort(a + 1, a + n + 1);
	int r = min(16, n);
	dp[0][0] = 0;
	for(int i = 1; i < (1 << 16); i ++) dp[0][i] = -1;
	for(int i = 1; i <= r; i ++) {
		for(int j = 0; j < (1 << 16); j ++) dp[i][j] = -1;
		for(int j = 0; j < (1 << 16); j ++) if(~ dp[i - 1][j]) {
			for(int k = 1; k < 60; k ++) if(!(j & st[k])) {
				int f = dp[i - 1][j] + abs(a[i].x - k);
				int &nxt = dp[i][j | st[k]];
				if(nxt == -1 || nxt > f) {
					nxt = f; sta[i][j | st[k]] = k;
				}
			}
		}
	}
	int ans = 30000, j = 0, t = 0;
	for(int i = 0; i < (1 << 16); i ++)
		if(~ dp[r][i] && dp[r][i] < ans) {
			ans = dp[r][i]; t = sta[r][i]; j = i;
		}
	for(int i = r; i >= 1; t = sta[-- i][j ^= st[t]]) {
		b[a[i].id] = t;
	}
	for(int i = r + 1; i <= n; i ++) b[a[i].id] = 1;
	for(int i = 1; i <= n; i ++)
		printf("%d%c", b[i], " \n"[i == n]);
	return 0;
}