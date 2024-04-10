#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 300005;
std::vector<int> G[maxn];
struct Heap {
	int lti, rti;
	int di;
	int val;
	int end;
	int dec;
} pool[maxn];
#define self pool[now]
#define lt pool[self.lti]
#define rt pool[self.rti]

void push_down(int now) {
	if(self.dec) {
		self.val -= self.dec;
		if(self.lti) lt.dec += self.dec;
		if(self.rti) rt.dec += self.dec;
		self.dec = 0;
	}
}

int merge(int now, int x) {
	if(!now) return x;
	if(!x) return now;
	if(self.val - self.dec > pool[x].val - pool[x].dec)
		std::swap(now, x);
	push_down(now);
	self.rti = merge(self.rti, x);
	if(rt.di > lt.di) std::swap(self.lti, self.rti);
	self.di = rt.di + 1;
	return now;
}

int pop(int now) {
	push_down(now);
	int res = merge(self.lti, self.rti);
	self.lti = self.rti = self.di = 0;
	return res;
}

int heap[maxn], hp;
ll ans = 0;
struct path { int t, c; };
std::vector<path> insert[maxn];

void print(int now) {
	if(!now) return;
	debug("%d (-%d)\n", self.val, self.dec);
	print(self.lti);
	print(self.rti);
}

int deep[maxn];
void dfs(int u, int fa) {
	deep[u] = deep[fa] + 1;

	int &now = heap[u];
	for(path p : insert[u]) {
		++ hp;
		pool[hp].val = p.c;
		pool[hp].end = deep[p.t];
		now = merge(now, hp);
	}

	for(int v : G[u])
		if(v != fa) {
			dfs(v, u);
			now = merge(now, heap[v]);
		}

	while(now and self.end >= deep[u])
		now = pop(now);
	// debug("u = %d -------------\n", u), print(now);
	if(u > 1 and !now) ans = 1000000000000000000;
	else {
		ans += self.val - self.dec;
		self.dec = self.val;
	}
}

int main() {
	int n = read, m = read;
	for(int i = 1; i < n; i ++) {
		int u = read, v = read;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	for(int i = 1; i <= m; i ++) {
		int s = read, t = read, c = read;
		insert[s].push_back({t, c});
	}

	dfs(1, 0);
	if(ans >= 1000000000000000000) puts("-1");
	else printf("%lld\n", ans);
}