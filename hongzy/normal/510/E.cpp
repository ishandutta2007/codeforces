#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

#define pb push_back

const int N = 210;
const int M = N * (N + 2);
const int A = 2e4 + 10;
const int INF = 1 << 29;

bool tag[A];
int p[A], pc;
void sieve(int n = 2e4) {
	tag[1] = 1;
	for(int i = 2; i <= n; i ++) {
		if(!tag[i]) {
			p[++ pc] = i;
		}
		for(int j = 1; j <= pc; j ++) {
			if(i * p[j] > n) break ;
			tag[i * p[j]] = 1;
			if(i % p[j] == 0) break ;
		}
	}
}
int n, a[N], hd[N], c;

namespace network {

struct Edge {
	int u, v, c, f, nxt;
} e[M];
int s, t, ec, hd[N];

void clr() {
	fill(hd + 1, hd + t + 1, -1);
}

void addedge(int u, int v, int c) {
	e[ec] = (Edge) {u, v, c, 0, hd[u]}; hd[u] = ec ++; 
	e[ec] = (Edge) {v, u, 0, 0, hd[v]}; hd[v] = ec ++; 
}

int d[N];
bool bfs() {
	fill(d + 1, d + t + 1, -1);
	queue<int> q; q.push(s); d[s] = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int i = hd[u]; ~ i; i = e[i].nxt) {
			int v = e[i].v;
			if(d[v] == -1 && e[i].f < e[i].c) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
	return ~ d[t];
}

int cur[N];

int dfs(int u, int a) {
	if(u == t || a == 0) return a;
	int ans = 0;
	for(int &i = cur[u]; ~ i; i = e[i].nxt) {
		int v = e[i].v, f;
		if(d[v] == d[u] + 1 && (f = dfs(v, min(a, e[i].c - e[i].f))) > 0) {
			ans += f; e[i].f += f; e[i ^ 1].f -= f;
			if((a -= f) == 0) break ;
		}
	}
	return ans;
}

int dinic() {
	int ans = 0;
	while(bfs()) {
		copy(hd + 1, hd + t + 1, cur + 1);
		ans += dfs(s, INF);
	}
	return ans;
}

bool vis[N];
vector<int> res;
vector< vector<int> > lst;

void dfs(int u) {
	vis[u] = 1; res.pb(u);
	for(int i = hd[u]; ~ i; i = e[i].nxt) {
		int v = e[i].v;
		if(v <= n && !vis[v] && e[i].f != 0) {
			dfs(v);
		}
	}
}

}
using namespace network;


int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", a + i);
	}
	sieve();
	int lp = 0, rp = 0;
	for(int i = 1; i <= n; i ++) {
		if(a[i] & 1) lp ++;
		else rp ++;
	}
	bool fail = 0;
	if(lp != rp) fail = 1;
	else {
		s = n + 1; t = s + 1; clr();
		for(int i = 1; i <= n; i ++) {
			if(a[i] & 1) addedge(s, i, 2);
			else addedge(i, t, 2);
		}
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= n; j ++) {
				if(!tag[a[i] + a[j]] && (a[i] & 1)) {
					addedge(i, j, 1);
				}
			}
		}
		if(dinic() < n) fail = 1;
		else {
			for(int i = 1; i <= n; i ++) {
				if(!vis[i]) {
					res.clear();
					dfs(i);
					lst.pb(res);
				}
			}
			printf("%d\n", lst.size());
			for(int i = 0; i < lst.size(); i ++) {
				printf("%d ", lst[i].size());
				for(int j = 0; j < lst[i].size(); j ++) {
					printf("%d ", lst[i][j]);
				}
				printf("\n");
			}
		}
	}
	
	if(fail) {
		puts("Impossible");
	}
	return 0;
}