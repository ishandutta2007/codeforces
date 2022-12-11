#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

char gc() {
//	return getchar();
	static char buf[100000], *l = buf, *r = buf;
	return l == r && (r = (l = buf) + fread(buf, 1, 100000, stdin), l == r) ? EOF : *l ++;
}

template<class T> void read(T &x) {
	x = 0; char c = gc(); bool na = 0;
	for(; !isdigit(c); c = gc()) na |= c == '-';
	for(; isdigit(c); c = gc()) x = x * 10 + (c & 15);
	if(na) x = -x;
}

typedef long long ll;

const int N = 8e5 + 10; 
const ll INF = 2e18;

struct Edge {
	int v, w, nxt; 
};
struct Node {
	int u; ll d;
	bool operator < (const Node &b) const {
		return d > b.d;
	}
};
int n, q, s, num[N];
namespace G {
	priority_queue<Node> pq;
	vector<Edge> e;
	int hd[N];
	void clr() {
		fill(hd + 1, hd + N, -1); e.clear();
	}
	void add(int u, int v, int w) {
		e.push_back((Edge) {v, w, hd[u]}); hd[u] = e.size() - 1;
	}
	ll d[N];
	void dijkstra(int s) {
		while(pq.size()) pq.pop();
		fill(d + 1, d + N, INF);
		pq.push((Node) {s, d[s] = 0});
		while(pq.size()) {
			Node k = pq.top(); pq.pop();
			for(int i = hd[k.u]; ~ i; i = e[i].nxt) {
				int v = e[i].v, w = e[i].w;
				if(d[v] > d[k.u] + w) {
					d[v] = d[k.u] + w;
					pq.push((Node) {v, d[v]});
				}
			}
		}
		for(int i = 1; i <= n; i ++) {
			if(d[num[i]] == INF) d[num[i]] = -1;
			printf("%I64d ", d[num[i]]);
		}
	}
}

void build(int rt, int l, int r) {
	if(l == r) {
		num[l] = rt;
		G :: add(rt, N - rt, 0);
		G :: add(N - rt, rt, 0);
		return ;
	}
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	G :: add(rt, rt << 1, 0);
	G :: add(rt, rt << 1 | 1, 0);
	G :: add(N - (rt << 1), N - rt, 0);
	G :: add(N - (rt << 1 | 1), N - rt, 0);
}

void solve(int rt, int l, int r, int sl, int sr, int v, int w, bool dir) {
	if(l == sl && r == sr) {
		if(dir) G :: add(N - rt, N - num[v], w);
		else G :: add(num[v], rt, w);
		return ;
	}
	int mid = (l + r) >> 1;
	if(sr <= mid) solve(rt << 1, l, mid, sl, sr, v, w, dir);
	else if(sl > mid) solve(rt << 1 | 1, mid + 1, r, sl, sr, v, w, dir);
	else {
		solve(rt << 1, l, mid, sl, mid, v, w, dir);
		solve(rt << 1 | 1, mid + 1, r, mid + 1, sr, v, w, dir);
	}
}

int main() {
	read(n); read(q); read(s);
	G :: clr(); build(1, 1, n);
	int t, v, l, r, w;
	while(q --) {
		read(t);
		bool dir = 0;
		if(t == 1) {
			read(v); read(l); r = l; read(w); dir = 0;
		}
		if(t == 2 || t == 3) {
			read(v); read(l); read(r); read(w); dir = t == 3;
		}
		if(l == r && l == v) continue ;
		solve(1, 1, n, l, r, v, w, dir);
	}
	G :: dijkstra(num[s]);
	return 0;
}