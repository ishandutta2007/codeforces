#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 200005;
std::vector<int> G[maxn];
int dis[maxn];
int tot[maxn];

void bfs(int s) {
	std::queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int v : G[u]) {
			if(!dis[v] and v != s) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
			tot[v] += dis[v] == dis[u] + 1;
		}
	}
}

int path[maxn];

int main() {
	int n = read, m = read;
	while(m --) {
		int u = read, v = read;
		// G[u].push_back(v);
		G[v].push_back(u);
	}

	int p = read;
	for(int i = 1; i <= p; i ++)
		path[i] = read;

	bfs(path[p]);

	int ans1 = 0, ans2 = 0;
	for(int i = 1; i < p; i ++) {
		ans1 += dis[path[i + 1]] + 1 != dis[path[i]];
		ans2 += (dis[path[i + 1]] + 1 != dis[path[i]]) or (tot[path[i]] > 1);
	}

	printf("%d %d\n", ans1, ans2);
}