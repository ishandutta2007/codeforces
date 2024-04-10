#include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define xx first
#define yy second

typedef long long ll;
typedef pair<int,int> pii;

const int N = 2005;
vector < int > p[N];
int n, fa[N], c[N], sz[N], s[N];
void dfs2(int x, int sp) {
	if (s[x] >= sp)
		s[x] ++;
	for (int y : p[x])
		dfs2(y, sp);
} 
void dfs(int x, int sp) {
	for (int y : p[x]) {
		dfs(y, sp + sz[x]);
		sz[x] += sz[y];
	} 
	if (c[x] > sz[x]) {
		puts("NO");
		exit(0);
	} 
	dfs2(x, sp + c[x]);
	s[x] = sp + c[x];
	sz[x] ++;
} 
int main() {
	scanf("%d", & n);
	for (int i = 1; i <= n; i ++)
		scanf("%d%d", fa + i, c + i), p[fa[i]].pb(i);
	int rt = 1;
	while (fa[rt])
		rt ++;
	dfs(rt, 1);
	puts("YES");
	for (int i = 1; i <= n; i ++)
		printf("%d ", s[i]);
	puts("");
}