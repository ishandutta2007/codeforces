#if 0
2019.04.05

 + Hash 
 dijkstra 
 +  <  O(x)  O(m x log(n))
 + 

+  1  0  0  1 
<  lcs 
 O(log^2)
 dijkstra  log 
 <  log 
+  O(m)  O(m log(n) log(x) + m log^2(x)) 
#endif
#include <bits/stdc++.h>

typedef unsigned long long Hash;

Hash power(Hash x, int k) {
	Hash res = 1;
	while(k) {
		if(k & 1) res *= x;
		x *= x;
		k >>= 1;
	}
	return res;
}

class Tree {
private:
	int L, R, sum;
	bool fuck_memory[4];
	Hash hash, Rpow; //  Rpow,  log
	Tree *lt, *rt;
	void update() {
		sum = lt -> sum + rt -> sum;
		hash = lt -> hash * Rpow + rt -> hash;
	}
	void get_son() {
		int mid = (L + R) >> 1;
		if(lt == null) lt = new Tree(L, mid);
		if(rt == null) rt = new Tree(mid + 1, R);
	}
public:
	static Tree *const null;
	Tree *lain(int p) {
		Tree *node = new Tree(*this);
		if(L == R) {
			node -> sum ++;
			node -> hash ++;
			return node;
		}
		int mid = (L + R) >> 1;
		get_son();
		if(p <= mid)
			node -> lt = lt -> lain(p);
		else
			node -> rt = rt -> lain(p);
		node -> update();
		return node;
	}
	Tree *clear(int l, int r) {
		if(r < L or l > R) return this;
		Tree *node = new Tree(*this);
		if(l <= L and R <= r) {
			node -> sum = 0;
			node -> hash = 0;
			node -> lt = node -> rt = null;
			return node;
		}
		get_son();
		node -> lt = lt -> clear(l, r);
		node -> rt = rt -> clear(l, r);
		node -> update();
		return node;
	}
	int query_sum(int l, int r) {
		if(not sum or r < L or l > R) return 0;
		if(l <= L and R <= r) return sum;
		return lt -> query_sum(l, r) + rt -> query_sum(l, r);
	}
	static int cmp(Tree *a, Tree *b) {
		if(a -> hash == b -> hash) return 0;
		if(not a -> sum) return -1;
		if(not b -> sum) return 1;
		if(a -> L == b -> R)
			return a -> sum < b -> sum ? -1 : 1;
		int rres = cmp(a -> rt, b -> rt);
		if(rres) return rres;
		return cmp(a -> lt, b -> lt);
	}
	Tree(int l, int r): L(l), R(r), sum(0), hash(0), lt(null), rt(null) {
		Rpow = power(3, R - ((L + R) >> 1));
	}
	Tree(): L(-1), R(-1), sum(0), hash(0), lt(nullptr), rt(nullptr) { }
};
Tree *const Tree::null = new Tree();

const int maxn = 100050, maxv = 100100; // maxv  wei
class Value {
private:
	Tree *T;
public:
	bool operator < (Value an) const {
		return Tree::cmp(T, an.T) == -1;
	}
	Value operator + (int k) {
		int l = k, r = maxv;
		while(l < r) {
			int mid = (l + r) >> 1;
			if(T -> query_sum(k, mid) == mid - k + 1)
				l = mid + 1;
			else
				r = mid;
		}
		Tree *node = T;
		if(k <= l - 1)
			node = T -> clear(k, l - 1);
		node = node -> lain(l);
		return Value(node);
	}
	bool empty() { return T == Tree::null; }
	void init() {
		T = new Tree(0, maxv);
	}
	int fuck_ans() {
		int ans = 0, pp = 1, mod = 1000000007;
		for(int i = 0; i <= maxv; i ++) {
			if(T -> query_sum(i, i))
				(ans += pp) %= mod;
			(pp <<= 1) %= mod;
		}
		return ans;
	}
	Value(Tree *T = Tree::null): T(T) { }
};

struct Edge {
	int to, val;
	Edge(int to, int val): to(to), val(val) { }
};
Value dist[maxn];
int last[maxn];
bool vis[maxn];
std::vector<Edge> G[maxn];

void dijk(int s) {
	typedef std::pair<Value, int> par;
	std::priority_queue<par, std::vector<par>, std::greater<par>> q;
	dist[s].init();
	q.push(par(dist[s], s));
	while(not q.empty()) {
		int u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(Edge &e : G[u])
			if(not vis[e.to]) {
				Value d = dist[u] + e.val;
				if(dist[e.to].empty() or d < dist[e.to]) {
					dist[e.to] = d;
					last[e.to] = u;
					q.push(par(d, e.to));
				}
			}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	int n, m;
	std::cin >> n >> m;
	for(int i = 1; i <= m; i ++) {
		int u, v, w;
		std::cin >> u >> v >> w;
		G[u].push_back(Edge(v, w));
		G[v].push_back(Edge(u, w));
	}
	int s, t;
	std::cin >> s >> t;
	dijk(s);
	std::vector<int> path;
	for(int u = t; u; u = last[u])
		path.push_back(u);
	if(path[path.size() - 1] == s) {
		std::cout << dist[t].fuck_ans() << std::endl;
		std::cout << path.size() << std::endl;
		for(size_t i = path.size() - 1; i; i --)
			std::cout << path[i] << ' ';
		std::cout << path[0] << std::endl;
	} else {
		std::cout << -1 << std::endl;
	}
}