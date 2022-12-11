#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int N = 2e5 * 31 + 10;
int n, id = 1, ch[N][2];
void insert(int x) {
	int u = 1; 
	for(int i = 29; i >= 0; i --) {
		int &v = ch[u][x >> i & 1];
		u = v ? v : v = ++ id;
	}
}
ll dfs(int u, int v, int k) {
	if(k == 0) return 0ll;
	ll ans = 2e18;
	if(ch[u][0] && ch[v][0]) ans = min(ans, dfs(ch[u][0], ch[v][0], k - 1));
	if(ch[u][1] && ch[v][1]) ans = min(ans, dfs(ch[u][1], ch[v][1], k - 1));
	if(ans < 2e18) return ans;
	if(ch[u][0] && ch[v][1]) ans = min(ans, dfs(ch[u][0], ch[v][1], k - 1));
	if(ch[u][1] && ch[v][0]) ans = min(ans, dfs(ch[u][1], ch[v][0], k - 1));
	return ans + (1ll << (k - 1));
}
ll solve(int u, int k) {
	if(k == 0 || u == 0) return 0;
	if(!ch[u][0]) return solve(ch[u][1], k - 1);
	if(!ch[u][1]) return solve(ch[u][0], k - 1);
	return solve(ch[u][0], k - 1) + solve(ch[u][1], k - 1) + dfs(ch[u][0], ch[u][1], k - 1) + (1ll << (k - 1));
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) {
		int x; scanf("%d", &x); insert(x);
	}
	printf("%lld\n", solve(1, 30));
	return 0;
}