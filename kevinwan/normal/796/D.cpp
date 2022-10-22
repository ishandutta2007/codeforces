#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
struct edge { int b, i; };
vector<edge> g[300001];
bool vis[300001];
set<int> ans;
int par[300001];
int main() {
	queue<int> q;
	int n, k, d,i,a,b;
	scanf("%d%d%d", &n, &k, &d);
	for (i = 0; i < k; i++)scanf("%d", &a),vis[a]=1;
	for(i=1;i<=n;i++)if(vis[i])q.push(i);
	for (i = 1; i < n; i++)scanf("%d%d", &a, &b), g[a].push_back({ b,i }), g[b].push_back({ a,i });
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto e : g[x]) {
			if (par[x] == e.b)continue;
			if (!vis[e.b])q.push(e.b), vis[e.b] = 1,par[e.b]=x;
			else ans.insert(e.i);
		}
	}
	printf("%d\n", ans.size());
	for (int x : ans)printf("%d ", x);
}