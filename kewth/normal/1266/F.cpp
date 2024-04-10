/*
 * Since g++10 is released, some characters is not valid inside #if 0 :(
 * So, why not using clang++? :D

 * Date:
  echo -n '  ' && date +%Y.%m.%d # Just Run this (Type !!sh in Vim).

 * Solution:
  To be updated after "Accept".

 * Digression:

 * CopyRight:
          
            
          
              
             
          
            
  
        
 */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 500005;
int ans[maxn << 1];
std::vector<int> G[maxn];
int fa[maxn];
int flen[maxn], len[maxn];
/* std::vector<int> L[maxn], S[maxn]; */
std::map<int, int> map[maxn];

void dfs1 (int u) {
	len[u] = 0;
	for (int v : G[u])
		if (v != fa[u]) {
			fa[v] = u;
			dfs1(v);
			len[u] = std::max(len[u], len[v] + 1);
			/* L[u].push_back(len[v] + 1); */
			++ map[u][len[v] + 1];
		}
}

void dfs2 (int u) {
	/* S[u] = L[u]; */
	/* if (fa[u]) L[u].push_back(flen[u] + 1); */
	if (fa[u]) ++ map[u][flen[u] + 1];
	/* std::sort(L[u].begin(), L[u].end()); */
	/* std::sort(S[u].begin(), S[u].end()); */
	int max = flen[u], semax = -1;
	for (int v : G[u])
		if (v != fa[u]) {
			if (len[v] > max)
				semax = max, max = len[v];
			else if (len[v] > semax)
				semax = len[v];
		}
	for (int v : G[u])
		if (v != fa[u]) {
			flen[v] = len[v] == max ? semax + 1 : max + 1;
			dfs2(v);
		}
}

int main () {
	int n = read;
	for (int i = 1; i < n; i ++) {
		int u = read, v = read;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	flen[1] = -1;
	dfs1(1);
	dfs2(1);

	for (int u = 1; u <= n; u ++) {
		int las = 0;
		for (auto it = map[u].rbegin(); it != map[u].rend(); ++ it) {
			it -> second += las;
			las = it -> second;
		}
		las = 0;
		for (auto p : map[u]) {
			int x = p.first, y = p.second;
			ans[x * 2] = std::max(ans[x * 2], y);
			ans[x * 2 - 1] = std::max(ans[x * 2 - 1], y);
			if (las < x)
				ans[las * 2 + 1] = std::max(ans[las * 2 + 1], y + 1);
			las = x;
		}
	}

	for (int u = 2; u <= n; u ++) {
		int f = fa[u];
		auto it1 = map[f].begin(), it2 = map[u].begin();
		while (it1 != map[f].end() and it2 != map[u].end()) {
			int x = std::min(it1 -> first, it2 -> first),
				y = it1 -> second + it2 -> second;
			if (it1 -> first <= len[u] + 1) -- y;
			if (it2 -> first <= flen[u] + 1) -- y;
			ans[x * 2] = std::max(ans[x * 2], y);
			if (it1 -> first == x) ++ it1;
			else ++ it2;
		}
	}

	ans[n + 1] = ans[n + 2] = 1;
	for (int i = n; i; i --)
		ans[i] = std::max(ans[i + 2], ans[i]);
	for (int i = 1; i <= n; i ++)
		printf("%d ", ans[i]);
	puts("");
}