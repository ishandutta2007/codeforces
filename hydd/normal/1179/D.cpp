#include<bits/stdc++.h>
#define sqr(x) (1ll*(x)*(x))
using namespace std;
typedef long long ll;
int n,sz[510000],top,s[510000]; ll ans;
ll f[510000],x[510000],y[510000];
vector<int> vec[510000];
bool cmp(int x,int y){ return sz[x]<sz[y];}
void dfs(int u,int fa){
	if (fa) vec[u].erase(find(vec[u].begin(),vec[u].end(),fa));
	sz[u]=1;
	for (int v:vec[u]){
		dfs(v,u); sz[u]+=sz[v];
	}
	f[u]=sqr(sz[u]);
	for (int v:vec[u]){
		f[u]=min(f[u],f[v]+sqr(sz[u]-sz[v]));
		ans=min(ans,f[v]+sqr(n-sz[v]));
	}
	sort(vec[u].begin(),vec[u].end(),cmp); top=0;
	for (int v:vec[u]){
		y[v]=f[v]+1ll*sz[v]*sz[v];
		x[v]=sz[v];
		
		while (top>1&&(y[s[top]]-y[s[top-1]])>(x[s[top]]-x[s[top-1]])*2ll*(n-sz[v])) top--;
		if (top) ans=min(ans,f[s[top]]+f[v]+sqr(n-sz[v]-sz[s[top]]));
		while (top>1&&(y[v]-y[s[top]])*(x[s[top]]-x[s[top-1]])<=(y[s[top]]-y[s[top-1]])*(x[v]-x[s[top]])) top--;
		s[++top]=v;
	}
}
int main(){
	scanf("%d",&n); int u,v;
	for (int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	ans=1ll<<60; dfs(1,0);
	printf("%lld\n",(2ll*n*(n-1)+n-ans)/2);
	return 0;
}