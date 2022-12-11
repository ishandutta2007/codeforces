#include <functional>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
struct Edge { int v, w; };
int n, k, dp[N][2];
vector<Edge> G[N];
vector< pair<int, int> > vec;
bool ch[N];
void dfs(int u, int fa = 0) {
	for(const Edge &p : G[u]) if(p.v != fa) dfs(p.v, u);
	vec.clear();
	for(const Edge &p : G[u]) if(p.v != fa) {
		vec.push_back(make_pair(dp[p.v][1] + p.w, p.v));
	}
	sort(vec.begin(), vec.end(), greater< pair<int, int> >());
	int sz = min((int) vec.size(), k - 1);
	for(int i = 0; i < sz; i ++) {
		dp[u][1] += vec[i].first;
	}
	int sum = 0;
	sz = min((int) vec.size(), k);
	for(int i = 0; i < sz; i ++) {
		sum += vec[i].first; ch[vec[i].second] = 1;
	}
	for(const Edge &p : G[u]) if(p.v != fa) {
		if(ch[p.v]) {
			dp[u][0] = max(dp[u][0], sum - dp[p.v][1] + dp[p.v][0]);
		} else {
			dp[u][0] = max(dp[u][0], sum - vec[sz - 1].first + dp[p.v][0] + p.w);
		}
	}
}
int main() {
	scanf("%d%d", &n, &k);
	for(int u, v, w, i = 1; i < n; i ++) {
		scanf("%d%d%d", &u, &v, &w); u ++; v ++;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	dfs(1);
	printf("%d\n", max(dp[1][0], dp[1][1]));
	return 0;
}