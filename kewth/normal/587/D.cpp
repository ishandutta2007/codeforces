#if 0
date



 2-SAT 
 2-SAT  O(m^2) 
 O(m) 
#endif
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 50005, maxp = 500005;
std::vector<int> E[maxn], tmp[maxn];
int w[maxn], c[maxn];

inline int T(int x) { return x << 1; }
inline int F(int x) { return x << 1 | 1; }

std::vector<int> G[maxp];
int stack[maxp], sp;
int dfn[maxp], low[maxp], dp;
int bl[maxp], bp;
bool ins[maxp];

void tarjan(int u) {
	low[u] = dfn[u] = ++ dp;
	stack[++ sp] = u;
	ins[u] = 1;
	for(int v : G[u]) {
		if(!dfn[v]) {
			tarjan(v);
			low[u] = std::min(low[u], low[v]);
		} else if(ins[v])
			low[u] = std::min(low[u], dfn[v]);
	}
	if(dfn[u] == low[u]) {
		++ bp;
		while(stack[sp + 1] != u) {
			int x = stack[sp --];
			ins[x] = 0;
			bl[x] = bp;
		}
	}
}

bool check(int n, int m, int p, int x) {
	for(int i = 1; i <= m; i ++)
		if(w[i] > x)
			G[T(i)].push_back(F(i));

	bp = dp = 0;
	for(int i = 2; i <= p * 2 + 1; i ++)
		dfn[i] = 0;
	for(int i = 2; i <= p * 2 + 1; i ++)
		if(!dfn[i])
			tarjan(i);

	bool res = 1;
	for(int i = 1; i <= m; i ++)
		if(bl[T(i)] == bl[F(i)])
			res = 0;

	for(int i = 1; i <= m; i ++)
		if(w[i] > x)
			G[T(i)].pop_back();
	return res;
}

int ans[maxn], ap;

int main() {
	int n = read, m = read;
	for(int i = 1; i <= m; i ++) {
		int u = read, v = read;
		c[i] = read;
		w[i] = read;
		E[u].push_back(i);
		E[v].push_back(i);
	}

	int p = m;
	for(int i = 1; i <= n; i ++) {
		int las;
		int ip = 0;
		std::map<int, int> id;

		las = 0;
		for(int e : E[i]) {
			++ p;
			G[T(e)].push_back(T(p));
			G[F(p)].push_back(F(e));
			if(las) {
				G[T(las)].push_back(T(p));
				G[T(las)].push_back(F(e));
				G[F(p)].push_back(F(las));
				G[T(e)].push_back(F(las));
			}
			las = p;
			if(!id[c[e]])
				id[c[e]] = ++ ip;
			tmp[id[c[e]]].push_back(e);
		}

		for(int j = 1; j <= ip; j ++) {
			las = 0;
			for(int e : tmp[j]) {
				++ p;
				G[F(e)].push_back(F(p));
				G[T(p)].push_back(T(e));
				if(las) {
					G[F(las)].push_back(F(p));
					G[F(las)].push_back(T(e));
					G[T(p)].push_back(T(las));
					G[F(e)].push_back(T(las));
				}
				las = p;
			}
			tmp[j].clear();
		}
	}

	int l = 0, r = 1000000001;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(check(n, m, p, mid))
			r = mid;
		else
			l = mid + 1;
	}

	if(l == 1000000001)
		return puts("No"), 0;
	puts("Yes");

	check(n, m, p, l);
	for(int i = 1; i <= m; i ++)
		if(bl[T(i)] < bl[F(i)])
			ans[++ ap] = i;

	printf("%d %d\n", l, ap);
	for(int i = 1; i <= ap; i ++)
		printf("%d ", ans[i]);
	puts("");
}