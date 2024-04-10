#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

const int N = 1e5 + 5;

int n, m;
int in[N];
int num[N], cnt;
vector <int> g[N];
priority_queue <int> pq;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++ i) {
		int u, v; scanf("%d %d", &u, &v); -- u, -- v;
		g[v].pb(u); in[u] ++;
	}
	for (int i = 0; i < n; ++ i)
		if (!in[i]) pq.push(i);
	cnt = n;
	while (!pq.empty()) {
		int u = pq.top(); pq.pop();
		num[u] = cnt --;
		for (int i = 0; i < g[u].size(); ++ i) {
			int v = g[u][i];
			if (-- in[v] == 0) pq.push(v);
		}
	}
	for (int i = 0; i < n; ++ i)
		printf("%d%c", num[i], " \n"[i + 1 == n]);
	return 0;
}