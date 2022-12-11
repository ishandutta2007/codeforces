#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct node { int x, y; };
int n, dp[7010][2], cnt[7010][2], vis[7010][2];
vector<int> s[2];
queue<node> qn;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < 2; i ++) {
		int t; scanf("%d", &t);
		while(t --) {
			int x; scanf("%d", &x);
			s[i].push_back(x);
		}
		sort(s[i].begin(), s[i].end());
	}
	for(int i = 0; i < n; i ++) dp[i][0] = dp[i][1] = 2;
	qn.push((node) {0, 1}); qn.push((node) {0, 0});
	vis[0][1] = vis[0][0] = 1; dp[0][1] = dp[0][0] = 0;
	while(qn.size()) {
		node u = qn.front(); qn.pop();
		for(int v : s[u.y ^ 1]) {
			node nxt = {(u.x - v + n) % n, u.y ^ 1};
			if(dp[u.x][u.y] == 0) {
				dp[nxt.x][nxt.y] = 1;
				if(!vis[nxt.x][nxt.y]) {
					vis[nxt.x][nxt.y] = 1;
					qn.push(nxt);
				}
			} else {
				if(++ cnt[nxt.x][nxt.y] == s[u.y ^ 1].size()) {
					vis[nxt.x][nxt.y] = 1;
					dp[nxt.x][nxt.y] = 0;
					qn.push(nxt);
				}
			}
		}
	} 
	for(int i = 1; i < n; i ++)
		printf("%s%c", dp[i][0] == 0 ? "Lose" : (dp[i][0] == 1 ? "Win" : "Loop"), " \n"[i == n - 1]);
	for(int i = 1; i < n; i ++)
		printf("%s%c", dp[i][1] == 0 ? "Lose" : (dp[i][1] == 1 ? "Win" : "Loop"), " \n"[i == n - 1]);
	return 0;
}