#include<bits/stdc++.h>
using namespace std;
int n,fa[310],num[310];
int p[310],q[310],tot;
int ans,Ans[610];
vector<int> vec[310];
bool cmp(int x,int y){ return num[x]<num[y];}
void dfs(int u,int f){
	fa[u]=f;
	if (f) vec[u].erase(find(vec[u].begin(),vec[u].end(),f));
	for (int v:vec[u]) dfs(v,u); 
	if (!vec[u].size()) tot++;
}
void dfs2(int u){
	Ans[++ans]=u;
	sort(vec[u].begin(),vec[u].end(),cmp);
	for (int v:vec[u]){
		dfs2(v);
		Ans[++ans]=u;
	}
	if (!vec[u].size()) q[++tot]=u;
}
int main(){
	scanf("%d",&n); int u,v;
	for (int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	tot=0; dfs(1,0);
	for (int i=1;i<=tot;i++){
		scanf("%d",&p[i]); u=p[i];
		while (u&&!num[u]){
			num[u]=i;
			u=fa[u];
		}
	}
	tot=0; dfs2(1);
	for (int i=1;i<=tot;i++)
		if (p[i]!=q[i]){
			puts("-1");
			return 0;
		}
	for (int i=1;i<=ans;i++) printf("%d ",Ans[i]);
	return 0;
}