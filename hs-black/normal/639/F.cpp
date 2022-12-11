#include<bits/stdc++.h>
const int maxn = 1001000;
int st[20][maxn];
struct T{
	struct { int to,nxt; } way[maxn << 1];
	int h[maxn], num = 1;
	inline void link(int x,int y){
		way[++num] = {x,h[y]},h[y] = num;
		way[++num] = {y,h[x]},h[x] = num;
	}
	int dfn[maxn],size[maxn],low[maxn],stack[maxn],bel[maxn],top,tot,cl;
	inline int min(int x,int y) { return dfn[x] < dfn[y] ? x : y; }
	inline int lca(int x,int y) {
		if(dfn[x] > dfn[y]) std::swap(x, y);
		const int lg = std::__lg(dfn[y] - dfn[x]);
		return x == y ? x : min(st[lg][dfn[x]],st[lg][dfn[y] - (1 << lg)]);
	}
	inline void dfs0(int x,int id) {
		low[x] = dfn[x] = ++tot, stack[++top] = x;
		for(int i = h[x];i;i = way[i].nxt) if(i != id) {
			if(!dfn[way[i].to]) {
				dfs0(way[i].to,i ^ 1);
				low[x] = std::min(low[x],low[way[i].to]);
			} else {
				low[x] = std::min(low[x],dfn[way[i].to]);
			}
		}
		if(low[x] == dfn[x]) {
			++cl;
			do bel[stack[top]] = cl; while(stack[top--] != x);
		}
	}
	inline void dfs1(int x,int f = 0) {
		st[0][tot] = f;
		dfn[x] = ++tot, size[x] = 1;
		for(int i = h[x];i;i = way[i].nxt) if(way[i].to != f)
			dfs1(way[i].to, x), size[x] += size[way[i].to];
	}
} t1,t2,t3;
inline bool cmp(int x,int y){ return t2.dfn[x] < t2.dfn[y]; }
int n, m, q;
int x[maxn], y[maxn];
int u[maxn], v[maxn];
int main(){
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m >> q;
	for(int i = 1;i <= m;++i) std::cin >> x[i] >> y[i], t1.link(x[i],y[i]);
	for(int i = 1;i <= n;++i) if(!t1.dfn[i]) t1.dfs0(i,0);
	for(int i = 1;i <= m;++i) if(t1.bel[x[i]] != t1.bel[y[i]])
		t2.link(t1.bel[x[i]],t1.bel[y[i]]);
	for(int i = 1;i <= t1.cl;++i) if(!t2.dfn[i])
		t2.dfs1(i,0);
	for(int i = 1;i < 20;++i) for(int j = 1;j + (1 << i) - 1 < n;++j)
		st[i][j] = t2.min(st[i - 1][j],st[i - 1][j + (1 << i - 1)]);
	long long R = n - 1;
	for(int i = 1, $, $$;i <= q;++i) {
		std::vector<int> v0, v1;
		std::cin >> $ >> $$;
		for(int i = 0, x;i < $;++i) {
			std::cin >> x;
			x = t1.bel[(x + R) % n + 1];
			v0.push_back(x);
			v1.push_back(x);
		}
		for(int i = 0;i < $$;++i) {
			std::cin >> u[i] >> v[i];
			u[i] = t1.bel[(u[i] + R) % n + 1];
			v[i] = t1.bel[(v[i] + R) % n + 1];
			v1.push_back(u[i]);
			v1.push_back(v[i]);
		}
		std::sort(v1.begin(),v1.end(),cmp), v1.erase(std::unique(v1.begin(),v1.end()),v1.end());
		for(int i (0), s (v1.size());i + 1 < s;++i) {
			if(int x = t2.lca(v1[i],v1[i + 1]))
				v1.push_back(x);
		}
		std::sort(v1.begin(),v1.end(),cmp), v1.erase(std::unique(v1.begin(),v1.end()),v1.end());
		static int st[maxn]; int top = 0;
		for(auto i : v1) {
			for(;top && t2.dfn[st[top]] + t2.size[st[top]] <= t2.dfn[i];) -- top;
			if(top) t3.link(st[top], i);
			st[++top] = i;
		}
		for(int i = 0;i < $$;++i) t3.link(u[i], v[i]);
		for(int i : v1) if(!t3.dfn[i]) t3.dfs0(i,0);
		int ok = 1;
		for(int i : v0) ok &= t3.bel[i] == t3.bel[v0.back()];
		std::cout << (ok ? "YES" : "NO") << '\n';
		if(ok) R += i;
		for(int i : v1) t3.h[i] = t3.dfn[i] = t3.bel[i] = 0; t3.num = 1;
	}
}