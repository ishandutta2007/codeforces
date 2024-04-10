/*
	Time: 2020/12/21 9:06 - 9:13
*/
#include<bits/stdc++.h>
using namespace std;
int n,p[210000],fa[210000],dep[210000];
bool vis[210000]; vector<int> vec[210000];
bool cmp(int a,int b){ return dep[a]>dep[b];}
void dfs(int u,int f){
	dep[u]=dep[f]+1; fa[u]=f;
	for (int v:vec[u])
		if (v!=f) dfs(v,u);
}
int main(){
	scanf("%d",&n); int u,v;
	for (int i=1;i< n;i++){
		scanf("%d%d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	dfs(1,0);
	for (int i=1;i<=n;i++) p[i]=i;
	sort(p+1,p+n+1,cmp);
	int ans=0;
	for (int i=1;i<=n&&dep[p[i]]>3;i++)
		if (!vis[p[i]]){
			ans++; u=fa[p[i]];
			vis[u]=true;
			for (int v:vec[u]) vis[v]=true;
		}
	printf("%d\n",ans);
	return 0;
}