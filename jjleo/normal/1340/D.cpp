#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
vector<int> v[maxn];
int x, y;
int deg[maxn], mxd;
int ans[maxn << 3][2], cnt;

void dfs(int i, int fa, int val){
	int x = deg[i] - (i != 1);
	int fin = val - 1;
	ans[++cnt][0] = i, ans[cnt][1] = val;
	for(int j = 0;j < v[i].size();j++){
		if(v[i][j] == fa) continue;
		--x;
		if(val + 1 > mxd) val = fin - x - 1, ans[++cnt][0] = i, ans[cnt][1] = val;
		//if(val + 1 == fin) ++val;
		dfs(v[i][j], i, ++val);
		ans[++cnt][0] = i, ans[cnt][1] = val;
	}
	if((i ^ 1) && val != fin) ans[++cnt][0] = i, ans[cnt][1] = fin;
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
		deg[x]++, deg[y]++;
	}
	for(int i = 1;i <= n;i++) mxd = max(mxd, deg[i]);
	dfs(1, 0, 0);
	printf("%d\n", cnt);
	for(int i = 1;i <= cnt;i++) printf("%d %d\n", ans[i][0], ans[i][1]);
}