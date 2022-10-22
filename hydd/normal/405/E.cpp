#include<bits/stdc++.h>
using namespace std;
int n,m,dep[110000];
vector<int> vec[110000];
bool dfs(int u,int f){
	dep[u]=dep[f]+1; int w=0;
	for (int v:vec[u]){
		if (v==f) continue;
		bool ok;
		if (!dep[v]){ dep[v]=dep[u]+1; ok=dfs(v,u);}
		else ok=(dep[v]<dep[u]);
		if (ok){
			if (w) printf("%d %d %d\n",w,u,v),w=0;
			else w=v;
		}
	}
	if (w){ printf("%d %d %d\n",w,u,f); return false;}
	return true;
}
int main(){
	scanf("%d%d",&n,&m);
	if (m&1){ puts("No solution"); return 0;}
	int u,v;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	dfs(1,0);
	return 0;
}