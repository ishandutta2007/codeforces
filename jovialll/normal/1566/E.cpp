#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define pb push_back
vector<int>son[N],to[N]; 
int ans,sy[N],dep[N],mxd[N],fa[N];
void dfs(int now,int fat){
	fa[now]=fat;
	for(int T,i=0;i<son[now].size();++i){
		if((T=son[now][i])!=fat)to[now].push_back(T),dep[T]=dep[now]+1,dfs(T,now);
	}
}
void cal(int now){
	if(to[now].size()==0)mxd[now]=dep[now];
	int yz=0;
	for(int T,i=0;i<to[now].size();++i){
		cal(T=to[now][i]),mxd[now]=max(mxd[now],mxd[T]);
		if(mxd[T]==dep[T])++yz;
	}
	if(mxd[now]==dep[now]){sy[now]=0;++ans;return ;}
	if(mxd[now]==dep[now]+1){
		sy[now]=1;return ; 
	}
	int sum=0;
	for(int i=0;i<to[now].size();++i){
		sum+=sy[to[now][i]];
	}
	if(yz)ans-=sum,sy[now]=1;
	else ans-=sum-1,dep[now]=mxd[now],sy[now]=0;
} 
int T,i,n,x,y;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;++i)son[i].clear(),to[i].clear();
		for(i=1;i<n;++i)cin>>x>>y,son[x].pb(y),son[y].pb(x);
		ans=0;dfs(1,0);cal(1);cout<<ans<<'\n';
	}
}