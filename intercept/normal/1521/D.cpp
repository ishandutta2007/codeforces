#include<bits/stdc++.h>
#define pii pair<int,int>
#define ppp pair<pii,pii>
#define eb emplace_back
#define fi first
#define se second
using namespace std;
const int M=2e5+9;
int n,ans;
int dp[M][5],d[M];
vector<int>g[M];
vector<ppp>op;
int dfs(int u,int fa){
	if(d[u]==1&&fa){
		dp[u][1]=u;
		return 1;
	}
	int num=0;
	vector<pii>id;
	for(auto v:g[u]){
		if(v!=fa)id.eb(dfs(v,u),v);
	}
	sort(id.begin(),id.end());
	for(auto o:id){
		int v=o.se,du=o.fi;
		if(du==1){
			if(num<2)dp[u][++num]=dp[v][1];
			else {
				op.eb(ppp{pii{u,v},pii{v,dp[u][1]}});
				ans++;
				dp[u][1]=dp[v][1];
			}
		}
		else {
			if(!num){
				op.eb(ppp{pii{u,v},pii{u,dp[v][1]}});
				ans++;
				dp[u][++num]=dp[v][2];
			}
			else{
				op.eb(ppp{pii{u,v},pii{dp[u][1],dp[v][1]}});
				ans++;
				dp[u][1]=dp[v][2];
			}	
		}
	}
	return num;
}
void work(){
	ans=0;op.clear();
	scanf("%d",&n);
	for(int i=1;i<=n;++i)g[i].clear(),d[i]=0;;
	for(int i=1,u,v;i<n;++i){
		scanf("%d%d",&u,&v);
		g[u].eb(v);
		g[v].eb(u);
		d[u]++,d[v]++;
	}
	for(int i=1;i<=n;++i){
		if(d[i]==1){
			dfs(i,0);
			break;
		}
	}
	printf("%d\n",ans);
	for(auto o:op){
		printf("%d %d %d %d\n",o.fi.fi,o.fi.se,o.se.fi,o.se.se);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}