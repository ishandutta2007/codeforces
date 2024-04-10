#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn=200000;
typedef long long ll;
int n,k;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int sz[Maxn+5],dep[Maxn+5];
void init_dfs(int u,int fa){
	sz[u]=1;
	dep[u]=dep[fa]+1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		init_dfs(v,u);
		sz[u]+=sz[v];
	}
}
int a[Maxn+5];
bool cmp(int p,int q){
	return p>q;
}
int main(){
	scanf("%d%d",&n,&k);
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	init_dfs(1,0);
	for(int i=1;i<=n;i++){
		a[i]=dep[i]-sz[i];
	}
	sort(a+1,a+1+n,cmp);
	ll ans=0;
	for(int i=1;i<=k;i++){
		ans+=a[i];
	}
	cout<<ans<<endl;
	return 0;
}