#if 0
2020.02.29

 AC 
 fail 
id  [l, r] 

 [l, r]  [1, l - 1]  [1, r]  r 
 r 

 m  B 

 B 
 O(B)  fail 
 dfs 
 dfs  O(q B + n sqrt(m)) 

 B 
 m / B 

 1  fail 

 O(q + m^2 / B) 

 n, m, q B = O(sqrt(n))  O(n sqrt(n) + n logn) 
#endif
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 100005, S = 340, B = 340;

struct Que {
	int r, k, id, o;
} qu[maxn << 1];
char s[maxn];
int ch[maxn][26], from[maxn], fail[maxn], tp = 1;
int pos[maxn];
std::vector<int> G[maxn];
int id[maxn], size[maxn], ip;

void get_fail() {
	std::queue<int> q;
	q.push(1);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		G[fail[u]].push_back(u);
		for(int x = 0; x < 26; x ++)
			if(ch[u][x]) {
				int p = fail[u];
				while(p and !ch[p][x])
					p = fail[p];
				fail[ch[u][x]] = p ? ch[p][x] : 1;
				q.push(ch[u][x]);
			}
	}
}

void dfs(int u, int *val) {
	if(!id[u]) id[u] = ++ ip;
	for(int v : G[u]) {
		dfs(v, val);
		val[u] += val[v];
	}
}

const int AB = 340;
struct Array {
	int a[maxn], t[AB];
	void add(int l, int r) {
		// debug("%d %d\n", l, r);
		if(l / AB == r / AB)
			for(int i = l; i <= r; i ++)
				++ a[i];
		else {
			for(int i = l; i / AB == l / AB; i ++)
				++ a[i];
			for(int i = r; i / AB == r / AB; i --)
				++ a[i];
			for(int i = l / AB + 1; i < r / AB; i ++)
				++ t[i];
		}
	}
	inline int get(int k) { return a[k] + t[k / AB]; }
} ar;

int big[S], bid[maxn], bp;
int bval[S][maxn];
ll ans[maxn], bans[S];

void add(int k) {
	int p = pos[k];
	ar.add(id[p], id[p] + size[p] - 1);
	for(int i = 1; i <= bp; i ++)
		bans[i] += bval[i][p];
}

int main() {
	int n = read, q = read;
	for(int i = 1; i <= n; i ++) {
		int &now = pos[i] = 1, len = 0;
		scanf("%s", s);
		for(int &j = len; s[j]; j ++) {
			int &to = ch[now][s[j] - 'a'];
			if(!to) from[to = ++ tp] = now;
			now = to;
		}
		if(len >= B)
			big[bid[i] = ++ bp] = i;
	}

	get_fail();
	for(int i = 1; i <= tp; i ++)
		size[i] = 1;
	dfs(1, size);

	// for(int i = 1; i <= tp; i ++)
		// debug("%d: {%d %d} fa=%d id=%d sz=%d\n",
				// i, ch[i][0], ch[i][1], fail[i], id[i], size[i]);

	for(int i = 1; i <= bp; i ++) {
		for(int x = pos[big[i]]; x; x = from[x])
			bval[i][x] = 1;
		dfs(1, bval[i]);
	}

	for(int i = 1; i <= q; i ++) {
		int l = read, r = read, k = read;
		qu[i * 2 - 1] = {l - 1, k, i, -1};
		qu[i * 2] = {r, k, i, 1};
	}

	std::sort(qu + 1, qu + q * 2 + 1, [](Que a, Que b) {
				return a.r < b.r;
			});

	int now = 0;
	for(int i = 1; i <= q * 2; i ++) {
		int r = qu[i].r, k = qu[i].k, I = qu[i].id, o = qu[i].o;
		while(now < r)
			add(++ now);
		if(bid[k])
			ans[I] += bans[bid[k]] * o;
		else
			for(int x = pos[k]; x; x = from[x])
				ans[I] += ar.get(id[x]) * o;
	}

	for(int i = 1; i <= q; i ++)
		printf("%lld\n", ans[i]);
}