#include<bits/stdc++.h>
using namespace std;
int T,n,m,ans,cnt,p[1100000],q[1100000],num[1100000]; bool vis[1100000];
int edgenum,vet[2100000],Next[2100000],Head[1100000];
vector<int> vec[1100000],g[1100000];
set<int> s;
void addedge(int u,int v){
	vet[++edgenum]=v;
	Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
bool dfs(int u){
	vis[u]=true; num[u]=0;
	for (int v:vec[u])
		if (!vis[v]&&(!dfs(v))){
			if (!num[u]) cnt++,num[u]=cnt,g[cnt].push_back(u);
			g[num[u]].push_back(v);
		}
	return (bool)num[u];
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m); int u,v;
		s.clear();
		for (int i=1;i<=n;i++) s.insert(i),vis[i]=false,Head[i]=0;
		for (int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			addedge(u,v); addedge(v,u);
		}
		cnt=0;
		for (int i=1;i<=n;i++){
			for (int e=Head[i];e;e=Next[e]) s.erase(vet[e]);
			s.erase(i);
			if (s.empty()) g[++cnt].push_back(i);
			else vec[i].push_back(*s.begin()),vec[*s.begin()].push_back(i);
			s.insert(i);
			for (int e=Head[i];e;e=Next[e]) s.insert(vet[e]);
		}
		for (int i=1;i<=n;i++)
			if (!vis[i]&&!vec[i].empty())
				if (!dfs(i)) g[num[vec[i][0]]].push_back(i);
		edgenum=0;
		for (int i=1;i<=n;i++) vec[i].clear();
		ans=0;
		for (int i=1;i<=cnt;i++){
			for (int j=0;j<(int)g[i].size();j++){
				ans++;
				p[g[i][j]]=ans; q[g[i][j]]=ans-1;
			}
			q[g[i][0]]=ans; g[i].clear();
		}
		for (int i=1;i<=n;i++) printf("%d ",p[i]); puts("");
		for (int i=1;i<=n;i++) printf("%d ",q[i]); puts("");
	}
	return 0;
}