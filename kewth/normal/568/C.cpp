#if 0
date
#endif
#include <cstdio>
#include <cstring>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
} read;

const int maxn = 205, maxl = 33;
std::vector<int> G[maxn << 1];
bool link[maxn << 1][maxn << 1];
bool ban[maxn << 1];

int vis[maxn << 1];
int other[maxn << 1];

int nxtdiff[maxl];

char s[maxn], type[maxl], ans[maxn];
int n, len;

void mark(int u) {
	vis[u] = 1;
	for(int v : G[u])
		if(!vis[v])
			mark(v);
}

int first[maxn], second[maxn];
bool check(int x) {
	for(int i = 1; i <= x; i ++) {
		first[i] = s[i] - 'a';
		second[i] = len;
	}

	if(x < n) {
		first[x + 1] = s[x + 1] - 'a' + 1;
		for(int i = x + 2; i <= n; i ++)
			first[i] = 0;
		for(int i = x + 1; i <= n; i ++)
			second[i] = nxtdiff[first[i]];
	}

	for(int i = 1; i <= n * 2; i ++)
		vis[i] = 0;

	for(int i = 1; i <= n; i ++) {
		int u = type[first[i]] == 'V' ? i : i + n;
		if(first[i] < len and !ban[u] and !vis[other[u]]) {
			mark(u);
			ans[i] = 'a' + first[i];
		}
		else {
			u = type[second[i]] == 'V' ? i : i + n;
			if(second[i] < len and !ban[u] and !vis[other[u]]) {
				mark(u);
				ans[i] = 'a' + second[i];
			}
			else
				return 0;
		}
	}

	return 1;
}

int main() {
	scanf("%s", type);
	len = int(strlen(type));
	n = read;
	int m = read;

	nxtdiff[len] = len;
	nxtdiff[len - 1] = len;
	for(int i = len - 1; i; i --)
		nxtdiff[i - 1] = type[i] == type[i - 1] ? nxtdiff[i] : i;

	for(int i = 1; i <= n; i ++) {
		other[i] = i + n;
		other[i + n] = i;
	}

	for(int i = 1; i <= m; i ++) {
		int p1 = read;
		char t1 = read;
		int p2 = read;
		char t2 = read;
		int u = t1 == 'V' ? p1 : p1 + n;
		int v = t2 == 'V' ? p2 : p2 + n;
		G[u].push_back(v);
		G[other[v]].push_back(other[u]);
		link[u][v] = link[other[v]][other[u]] = 1;
	}

	for(int k = 1; k <= n * 2; k ++)
		for(int i = 1; i <= n * 2; i ++)
			for(int j = 1; j <= n * 2; j ++)
				link[i][j] |= link[i][k] & link[k][j];

	for(int i = 1; i <= n * 2; i ++)
		for(int j = 1; j <= n; j ++)
			if(link[i][j] and link[i][j + n])
				// debug("ban %d in (%d, %d)\n", i, j, j + n),
				ban[i] = 1;

	scanf("%s", s + 1);

	for(int x = n; x >= 0; x --)
		if(check(x))
			return puts(ans + 1), 0;

	puts("-1");
}