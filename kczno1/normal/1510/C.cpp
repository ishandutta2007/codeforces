#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T &x,const T &y){
	if(x>y)x=y;
}
const int N=1e5+5;
vector<int> lk[N];
int dfn[N],low[N],tot,dp[N],fa[N];
vector<pair<int,int>> ans;

void dfs(int x,int fr){
	fa[x]=fr;
	dfn[x]=low[x]=++tot;
	int now=0;
	for(auto y:lk[x])
	if(y!=fr){
		if(!dfn[y]){
			dfs(y,x);
			chmin(low[x],low[y]);
			if(dp[y]&&dp[y]!=y){
				if(now){
					ans.push_back({dp[y],now});
					now=0;
				}
				else now=dp[y];
			}
		}
		else chmin(low[x],dfn[y]);
	}
	if((x==1||low[x]<dfn[x])){
		for(auto y:lk[x])
		if(fa[y]==x&&dp[y]==y){
				if(now){
					ans.push_back({dp[y],now});
					now=0;
				}
				else now=dp[y];
		}
		if(now&&fa[now]!=x)ans.push_back({x,now});
	}
	else{
		dp[x]=now;
		int leave=0;
		for(auto y:lk[x])
		if(fa[y]==x&&dp[y]==y){
			if(dp[x]==0)dp[x]=y;
			else
			if(leave==0)leave=y;
			else {
				ans.push_back({dp[x],leave});
				leave=0;
				dp[x]=y;
			}
		}	
		if(dp[x]==0)dp[x]=x;
	}
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m),n){
		for(int i=1;i<=n;++i){
			lk[i].clear();
			dfn[i]=low[i]=dp[i]=0;
		}
		tot=0;ans.clear();
		for(int i=1;i<=m;++i){
			int s;
			scanf("%d",&s);
			vector<int> a(s);
			for(int j=0;j<s;++j)scanf("%d",&a[j]);
			for(int j=1;j<s;++j){
				lk[a[j]].push_back(a[j-1]);
				lk[a[j-1]].push_back(a[j]);
			}
		}
		dfs(1,0);
		printf("%d\n",int(ans.size()));
		for(auto p:ans)printf("%d %d\n",p.first,p.second);
	}
}