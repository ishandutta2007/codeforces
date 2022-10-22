#if 0
2020.02.29

 AC  x  y  x -> y 

#endif
#include <cstdio>
#include <algorithm>
#include <queue>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 755, maxs = 10000005;

bool to[maxn][maxn];
int match[maxn];
bool matched[maxn];

int n;
bool vis[maxn];
bool find(int x) {
	for(int y = 1; y <= n; y ++)
		if(!vis[y] and to[x][y]) {
			vis[y] = 1;
			if(!match[y] or find(match[y])) {
				match[y] = x;
				matched[x] = 1;
				return 1;
			}
		}
	return 0;
}

bool visa[maxn], visb[maxn];
void dfs(int x) {
	visa[x] = 1;
	for(int y = 1; y <= n; y ++)
		if(to[x][y] and match[y] != x and !visb[y] and !visa[match[y]]) {
			visb[y] = 1;
			dfs(match[y]);
		}
}

char s[maxs];
int ch[maxs][2], fa[maxs], tp = 1;
int fail[maxs], fir[maxs];
int word[maxs];
int pos[maxn];

int main() {
	n = read;

	for(int i = 1; i <= n; i ++) {
		scanf("%s", s);
		int &now = pos[i] = 1;
		for(int j = 0; s[j]; j ++) {
			int &to = ch[now][s[j] - 'a'];
			if(!to) fa[to = ++ tp] = now;
			now = to;
		}
		pos[word[now]] = 0;
		word[now] = i;
	}

	std::queue<int> q;
	q.push(1);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		fir[u] = word[u] ? u : fir[fail[u]];
		for(int i = 0; i < 2; i ++)
			if(ch[u][i]) {
				int v = ch[u][i];
				int p = fail[u];
				while(p and !ch[p][i])
					p = fail[p];
				fail[v] = p ? ch[p][i] : 1;
				q.push(v);
			}
	}

	for(int i = 1; i <= n; i ++) {
		int x = fail[pos[i]];
		if(fir[x])
			to[i][word[fir[x]]] = 1;
		for(x = fa[pos[i]]; x; x = fa[x])
			if(fir[x])
				to[i][word[fir[x]]] = 1;
	}

	for(int k = 1; k <= n; k ++)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				to[i][j] |= to[i][k] & to[k][j];

	int ans = n;
	for(int i = 1; i <= n; i ++)
		if(pos[i]) {
			std::fill(vis, vis + n + 1, 0);
			ans -= find(i);
		} else
			-- ans;

	printf("%d\n", ans);

	for(int x = 1; x <= n; x ++)
		if(!matched[x])
			dfs(x);

	// for(int i = 1; i <= n; i ++)
		// debug("%d %d\n", visa[i], visb[i]);

	for(int i = 1; i <= n; i ++)
		if(pos[i] and visa[i] and !visb[i])
			printf("%d ", i);
	puts("");
}