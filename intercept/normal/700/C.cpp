#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int M=1e3+9;
int n,m,rt,en;
struct P{
	int v,w,id;
};
vector<P>g[M];
int dp[M],dep[M],ep[M],p[M];
bool vis[M],in[M],g1[M],g2[M];
int ans=2e9+1,s[2];
void pfs(int u,int w,int id,int pw,int pid){
	in[u]=1;
	if(u==en)g2[u]=1;
	for(auto o:g[u]){
		int v=o.v;
		if(o.id==pid)continue;
		if(!in[v])ep[v]=ep[u]+1,pfs(v,o.w,o.id,pw,pid),g2[u]|=g2[v],p[u]+=p[v];
		else{
			if(ep[v]<ep[u]){
				p[u]++;
				p[v]--;
			}
		}
	}
	if(p[u]==1&&g2[u]){
		if(ans>w+pw){
			ans=w+pw;
			s[0]=id;
			s[1]=pid;
		}
	}
}
void dfs(int u,int w,int id){
	vis[u]=1;
	if(u==en)g1[u]=1;
	for(auto o:g[u]){
		int v=o.v;
		if(!vis[v])dfs(v,o.w,o.id),g1[u]|=g1[v],dp[u]+=dp[v];
		else{
			if(dep[v]<dep[u]){
				dp[u]++;
				dp[v]--;
			}
		}
	}
	if(dp[u]==1&&g1[u]){
		if(ans>w){
			ans=w;
			s[0]=id;
			s[1]=0;
		}
	}
	if(g1[u]){
		memset(in,0,sizeof(in));
		memset(p,0,sizeof(p));
		memset(g2,0,sizeof(g2));
		pfs(rt,0,0,w,id);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>rt>>en;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].eb(P{v,w,i});
		g[v].eb(P{u,w,i});
	}
	dfs(rt,0,0);
	if(g1[rt]&&s[0]==0){
		cout<<"-1\n";
		return 0;
	}
	cout<<(s[0]?ans:0)<<"\n";
	if(s[0]==0)cout<<0<<"\n";
	else if(s[1]==0){
		cout<<1<<"\n"<<s[0]<<"\n";
	}
	else cout<<2<<"\n"<<s[0]<<" "<<s[1]<<"\n";
	return 0;
}
/*
5 9
1 5
1 2 1
2 3 1
3 3 1
3 4 1
4 5 1
3 5 1
2 4 1
4 2 1
4 2 1
*/