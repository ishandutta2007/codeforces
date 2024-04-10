#include <bits/stdc++.h>
#define maxn 100086
using namespace std;

int n;
int val[maxn];
int son[maxn][2];
bool tag[maxn];

map<int, bool> mp;
int ans;

void dfs(int x, int l, int r){
	if(val[x] < l && r < val[x]) mp[val[x]] = true;
	if(son[x][0] != -1) dfs(son[x][0], min(l, val[x]), r);
	if(son[x][1] != -1) dfs(son[x][1], l, max(r, val[x]));
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d%d%d", &val[i], &son[i][0], &son[i][1]);
		if(son[i][0] != -1) tag[son[i][0]] = true;
		if(son[i][1] != -1) tag[son[i][1]] = true;
	}
	for(int i = 1;i <= n;i++){
		if(!tag[i]){
			dfs(i, 1e9 + 1, -1);
			break;
		}
	}
	for(int i = 1;i <= n;i++) if(!mp[val[i]]) ans++;
	printf("%d", ans);
}