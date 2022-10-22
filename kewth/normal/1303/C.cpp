#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 205;
char s[maxn];
std::set<int> G[26];
char ans[30];
int ap;

bool vis[maxn];
void dfs(int u) {
	vis[u] = 1;
	ans[++ ap] = 'a' + u;
	for(int v : G[u])
		if(!vis[v])
			dfs(v);
}

int main() {
	int t = read;
	while(t --) {
		scanf("%s", s + 1);
		int n = int(strlen(s + 1));

		for(int i = 0; i < 26; i ++)
			G[i].clear();

		for(int i = 2; i <= n; i ++) {
			G[s[i] - 'a'].insert(s[i - 1] - 'a');
			G[s[i - 1] - 'a'].insert(s[i] - 'a');
		}

		for(int i = 0; i < 26; i ++)
			if(G[i].size() > 2) {
				puts("NO");
				goto fail;
			}

		for(int i = 0; i < 26; i ++)
			vis[i] = 0;

		ap = 0;
		for(int i = 0; i < 26; i ++)
			if(!vis[i] and G[i].size() <= 1)
				dfs(i);

		if(ap < 26) {
			puts("NO");
			goto fail;
		}

		ans[ap + 1] = 0;
		puts("YES");
		puts(ans + 1);
fail:;
	}
}