#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
using namespace std;

int read() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)){ if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)){ x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

#define maxn 310
#define maxm 101210
#define oo 1e14
#define LL long long
int Cnt, U[maxm], V[maxm], W[maxm];
int v, a[maxn];

struct Edge { int from, to; LL flow, cap; } es[maxm];
struct Dinic {
	int n, m, s, t, head[maxn], next[maxm];
	int vis[maxn], Q[maxn<<2], Head, Tail;
	int cur[maxn];	
	void init() {
		m = 0; memset(head, -1, sizeof(head));
		return ;
	}
	void AddEdge(int a, int b, LL c) {
		es[m] = (Edge){ a, b, 0, c }; next[m] = head[a]; head[a] = m++;
		return ;
	}
	bool BFS() {
		memset(vis, 0, sizeof(vis));
		vis[s] = 1;
		Head = Tail = 0; Q[++Tail] = s;
		while(Head < Tail) {
			int u = Q[++Head];
			for(int i = head[u]; i != -1; i = next[i]) {
				Edge& e = es[i];
				if(e.flow < e.cap && !vis[e.to]) {
					vis[e.to] = vis[u] + 1;
					Q[++Tail] = e.to;
				}
			}
		}
		return vis[t] > 0;
	}
	LL DFS(int u, LL a) {
		if(u == t || !a) return a;
		LL flow = 0, f;
		for(int& i = cur[u]; i != -1; i = next[i]) {
			Edge& e = es[i];
			if(vis[e.to] == vis[u] + 1 && (f = DFS(e.to, min(a, e.cap - e.flow)))) {
				flow += f; a -= f;
				e.flow += f; es[i^1].flow -= f;
				if(!a) return flow;
			}
		}
		return flow;
	}
	LL MaxFlow() {
		s = n - 1; t = n;
		LL flow = 0;
		while(BFS()) {
			for(int i = 1; i <= n; i++) cur[i] = head[i];
			flow += DFS(s, oo);
		}
		return flow;
	}
	int in[maxn];
	bool Print() {
		memset(in, 0, sizeof(in));
		for(int i = 1; i <= n - 2; i++)
			for(int j = head[i]; j != -1; j = next[j]) {
				Edge& e = es[j];
				if(e.flow > 0) in[e.to]++;
			}
		Head = Tail = 0;
		for(int i = 1; i <= n - 2; i++) if(!in[i]) Q[++Tail] = i;
		// for(int i = Head + 1; i <= Tail; i++) printf("%d ", Q[i]); putchar('\n');
		if(Tail == n - 2) return 0;
		while(Head < Tail) {
			int u = Q[++Head];
			for(int i = head[u]; i != -1; i = next[i]) {
				Edge& e = es[i];
				if(e.to <= n - 2) {
					LL w = min(e.flow, (LL)min(a[u], v - a[e.to]));
					if(w > 0) {
						U[++Cnt] = u; V[Cnt] = e.to; W[Cnt] = w;
						e.flow -= w; a[u] -= w; a[e.to] += w;
					}
					in[e.to]--; if(!in[e.to]) Q[++Tail] = e.to;
					// printf("[%d]%d\n", e.to, in[e.to]);
				}
			}
		}
		return 1;
	}
} sol;

int main() {
	sol.init();
	int n = read(), m; v = read(); m = read();
	LL suma = 0, sumb = 0;
	sol.n = n + 2; int s = n + 1, t = n + 2;
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= n; i++) {
		int b = read();
		if(a[i] > b) {
			sol.AddEdge(s, i, a[i] - b);
			sol.AddEdge(i, s, 0);
			suma += a[i] - b;
		} else {
			sol.AddEdge(i, t, b - a[i]);
			sol.AddEdge(t, i, 0);
			sumb += b - a[i];
		}
	}
	for(int i = 0; i < m; i++) {
		int A = read(), b = read();
		sol.AddEdge(A, b, oo);
		sol.AddEdge(b, A, oo);
	}
	LL flow = sol.MaxFlow();
	if(suma == sumb && flow == suma) {
		while(sol.Print());
		printf("%d\n", Cnt);
		for(int i = 1; i <= Cnt; i++) printf("%d %d %d\n", U[i], V[i], W[i]);
	}
	else puts("NO");
	
	
	return 0;
}