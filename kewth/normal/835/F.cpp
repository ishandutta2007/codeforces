#if 0
2019.09.07

 dp 
 O(n^2) 

dp  d[x]  x 

 p a[i]  i  u  d[u] 
b[i]  p  i 

 1  p 
 pre1[i]  1  i  a[j] + b[j] 
pre2[i]  1  i  a[j] + a[k] + b[j] - b[k] 
pre1, pre2 
 pre2  pre0[i]  1  i  a[j] + b[p] - b[j] 
 suf0, suf1, suf2  i  i + 1 
 max(pre2[i], suf2[i + 1], pre1[i] + suf1[i]) 
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long lolong;

inline int input() { int x; scanf("%d", &x); return x; }

const int maxn = 200005;
int head[maxn], nxt[maxn << 1], to[maxn << 1], val[maxn << 1], hp = 1;

inline void add(int u, int v, int w) {
	nxt[++ hp] = head[u];
	head[u] = hp;
	to[hp] = v;
	val[hp] = w;
}

int stack[maxn], sp;
int du[maxn];

void sort(int n) {
	for(int i = 1; i <= n; i ++)
		if(du[i] == 1)
			stack[++ sp] = i;

	while(sp) {
		int u = stack[sp --];
		for(int i = head[u]; i; i = nxt[i])
			if(du[to[i]]) {
				du[to[i]] --;
				du[u] --;
				if(du[to[i]] == 1)
					stack[++ sp] = to[i];
			}
	}
}

lolong ans;
lolong d[maxn];

void dp(int u, int fa) {
	lolong max = 0;
	for(int i = head[u]; i; i = nxt[i])
		if(to[i] != fa and not du[to[i]]) {
			dp(to[i], u);
			lolong dt = d[to[i]] + val[i];
			if(dt >= d[u]) {
				max = d[u];
				d[u] = dt;
			} else if(dt >= max)
				max = dt;
		}
	ans = std::max(ans, d[u] + max);
}

int id[maxn];
lolong a[maxn], b[maxn];
lolong pre0[maxn], pre1[maxn], pre2[maxn];
lolong suf0[maxn], suf1[maxn], suf2[maxn];

int main() {
	int n = input();

	for(int i = 1; i <= n; i ++) {
		int u = input(), v = input(), w = input();
		add(u, v, w);
		add(v, u, w);
		du[u] ++;
		du[v] ++;
	}

	sort(n);

	for(int u = 1; u <= n; u ++)
		if(du[u]) {
			id[0] = u;
			dp(u, 0);
			a[0] = d[u];
		}

	int p = 0;
	bool shit = true;
	while(shit)
		for(int i = head[id[p]]; i; i = nxt[i])
			if(du[to[i]] and (not p or to[i] != id[p - 1])) {
				id[p + 1] = to[i];
				a[p + 1] = d[to[i]];
				b[p + 1] = b[p] + val[i];
				if(to[i] == id[0])
					shit = false;
				p ++;
				break;
			}

	for(int i = 1; i <= p; i ++) {
		pre0[i] = std::max(pre0[i - 1], b[p] - b[i] + a[i]);
		pre1[i] = std::max(pre1[i - 1], b[i] + a[i]);
		pre2[i] = std::max(pre2[i - 1], pre0[i - 1] - (b[p] - b[i]) + a[i]);
	}

	for(int i = p; i; i --) {
		suf0[i] = std::max(suf0[i + 1], b[i] + a[i]);
		suf1[i] = std::max(suf1[i + 1], b[p] - b[i] + a[i]);
		suf2[i] = std::max(suf2[i + 1], suf0[i + 1] - b[i] + a[i]);
	}

	lolong min = pre2[p];
	for(int i = 1; i < p; i ++)
		min = std::min(min, std::max(
					std::max(pre2[i], suf2[i + 1]), pre1[i] + suf1[i + 1]));

	ans = std::max(ans, min);

	printf("%lld\n", ans);
}