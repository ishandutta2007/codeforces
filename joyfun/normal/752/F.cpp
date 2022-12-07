#include <bits/stdc++.h>

using namespace std;

vector<int> g[200005], lst[2];

int n, k, c, s[200005], p;
bool f[200005];

void dfs(int x, int fa = -1) {
	if(f[x]) 
		lst[++c > k].push_back(x);
	for(auto y: g[x]) {
		if(y == fa) continue;
		dfs(y, x);
		s[x] += s[y];
		if(s[x] >= k and !p) p = x;
	}
}

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1;i < n;i++) {
		int a, b; scanf("%d%d", &a, &b);
		g[a].push_back(b), g[b].push_back(a);
	}
	for(int i = 0;i < 2 * k;i++) {
		int x; scanf("%d", &x);
		f[x] = true; s[x] = 1;
	}
	dfs(1);
	printf("1\n%d\n", p);
	for(int i = 0;i < k;i++)
			printf("%d %d %d\n", lst[0][i], lst[1][i], p);
}