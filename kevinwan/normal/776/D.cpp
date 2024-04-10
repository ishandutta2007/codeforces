#include <bits/stdc++.h>
using namespace std;
int st[100001];
vector<int> g[100001];
vector<int> op[100001];
int de[100001];
int idk(int a, int f) { return op[a][0] == f ? op[a][1] : op[a][0]; }
void dfs(int x) {
	for (int z : g[x]) {
		int y = idk(z, x);
		if (de[y] != -1)continue;
		de[y] = de[x] ^ st[z] ^ 1;
		dfs(y);
	}
}
int main() {
	int n, m,i,j,x,y;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)scanf("%d", st + i);
	for (i = 1; i <=m; i++) {
		scanf("%d", &x);
		for (j = 0; j < x; j++)scanf("%d", &y), g[i].push_back(y), op[y].push_back(i);
	}
	memset(de, -1, sizeof(de));

	for(i=1;i<=m;i++)if(de[i]==-1)de[i]=1,dfs(i);
	int suc = 0,temp=1;
	for (i = 1; i <= n; i++)temp &= de[op[i][0]] ^ de[op[i][1]] ^ st[i];
	if (temp)printf("YES");
	else printf("NO");
	getchar(); getchar();
}