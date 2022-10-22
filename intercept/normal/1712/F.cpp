#include<bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second
#define ll long long
using namespace std;
const int M=1e6+9;
int n,q,t,ans;
int dp[M],len[M],son[M];
vector<int>g[M],f[M];
void pre(int u,int fa){
	if(g[u].size()==1)dp[u]=0;
	else dp[u]=1e9;
	for(auto v:g[u]){
		if(v!=fa){
			pre(v,u);
			dp[u]=min(dp[u],dp[v]+1);
		}
	}
}
void dow(int u,int fa){
	for(auto v:g[u]){
		if(v!=fa){
			dp[v]=min(dp[v],dp[u]+1);
			dow(v,u);
		}
	}
}
void dfs(int u,int fa,int deep){
	f[u].clear();
	son[u]=0;
	for(auto v:g[u]){
		if(v!=fa){
			dfs(v,u,deep+1);
			if(len[v]>len[son[u]]||son[u]==0)son[u]=v;
		}
	}
	swap(f[u],f[son[u]]);
	len[u]=max(len[son[u]],dp[u]);
	if(f[u].size()<len[u]+1)f[u].eb(0);
	f[u][dp[u]]=max(f[u][dp[u]],deep);
	for(auto v:g[u]){
		if(v!=fa&&v!=son[u]){
			for(int l=0;l<=len[v];++l){
				int L=0,R=len[u];
				while(L<R){
					int mid=L+R>>1;
					if(l+mid+t>f[u][mid]+f[v][l]-2*deep)R=mid;
					else L=mid+1;
				}
				ans=max(ans,min(R+l+t,f[u][R]+f[v][l]-2*deep));
				if(R)R--;
				ans=max(ans,min(R+l+t,f[u][R]+f[v][l]-2*deep));
			}
			for(int l=0;l<=len[v];++l)f[u][l]=max(f[u][l],f[v][l]);
		}
	}
	int l=0,r=len[u];
	while(l<r){
		int mid=l+r>>1;
		if(dp[u]+mid+t>f[u][mid]-deep)r=mid;
		else l=mid+1;
	}
	ans=max(ans,min(dp[u]+r+t,f[u][r]-deep));
	if(r)r--;
	ans=max(ans,min(dp[u]+r+t,f[u][r]-deep));
}
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;++i){
		int x;
		scanf("%d",&x);
		g[x].eb(i);
		g[i].eb(x);
	}
	pre(1,0);
	dow(1,0);
	scanf("%d",&q);
	for(int i=1;i<=q;++i){
		ans=0;
		scanf("%d",&t);
		dfs(1,0,0);
		printf("%d\n",ans);
	}
	return 0;
}
/*
7
1 2 3 4 2 1
1
3


*/