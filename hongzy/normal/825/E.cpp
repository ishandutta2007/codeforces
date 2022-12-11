#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
struct Edge {
	int v, nxt;
} e[N];
int n, m, hd[N], ec, d[N], w[N], s[N];
void add(int u, int v) {
	e[ec] = (Edge) {v, hd[u]}; hd[u] = ec ++; d[v] ++;
}
priority_queue<int> pq;
int main() {
	scanf("%d%d", &n, &m);
	fill(hd + 1, hd + n + 1, -1);
	for(int u, v, i = 1; i <= m; i ++) {
		scanf("%d%d", &u, &v); add(v, u);
	}
	for(int i = 1; i <= n; i ++)
		if(!d[i]) pq.push(i);
	int cur = n;
	while(pq.size()) {
		int u = pq.top(); pq.pop(); w[u] = cur --;
		for(int i = hd[u]; ~ i; i = e[i].nxt) {
			if(! --d[e[i].v]) {
				pq.push(e[i].v);
			}
		}
	}
	for(int i = 1; i <= n; i ++)
		printf("%d ", w[i]);
	return 0;
}