// Hydro submission #6331c9d45741ce0221174169@1664207316496
#include<bits/stdc++.h>
using namespace std;
int n,q,fa[100001],vis[100001],Size[100001],id[100001];
long long dep[100001],dis[100001];
vector <pair<int,long long> > G[100001];
int find(int x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
int query(long long x){
	for(int i=1;i<=n;i++){
		fa[i]=i;
		vis[i]=0;
		Size[i]=1;
	}
	int r=n,ans=1;
	for(int l=n;l>=1;l--){
		while(dis[id[r]]-dis[id[l]]>x){
			Size[find(id[r])]--;
			r--;
		}
		vis[id[l]]=1;
		for(int i=0;i<G[id[l]].size();i++){
			int to=G[id[l]][i].first,x=find(id[l]),y=find(to);
			if(!vis[to]||x==y) continue;
			fa[x]=y;
			Size[y]+=Size[x];
			ans=max(ans,Size[y]);
		}
	}
	return ans;
}
void dfs(int rt,int fa,int edge){
	dep[rt]=dep[fa]+edge;
	dis[rt]=max(dis[rt],dep[rt]);
	for(int i=0;i<G[rt].size();i++){
		int to=G[rt][i].first,w=G[rt][i].second;
		if(fa!=to) dfs(to,rt,w);
	}
}
bool cmp(int x,int y){
	return dis[x]<dis[y];
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
    	int l,r;
		long long w;
    	scanf("%d%d%lld",&l,&r,&w);
    	G[l].push_back({r,w});
    	G[r].push_back({l,w});
	}
	int rt=1,to=1;
	dfs(1,0,0);
	for(int i=2;i<=n;i++) if(dep[rt]<dep[i]) rt=i;
	dfs(rt,0,0);
	for(int i=2;i<=n;i++) if(dep[to]<dep[i]) to=i;
	dfs(to,0,0);
	for(int i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+1+n,cmp);
	scanf("%d",&q);
	while(q--){
		long long l;
		scanf("%lld",&l);
		printf("%d\n",query(l));
	}
    return 0;
}