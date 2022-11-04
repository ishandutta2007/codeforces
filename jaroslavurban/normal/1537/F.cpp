#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N=200100;
vector<int>g[N];
int val[N],t[N],vis[N],par[N];
int isp;

int dfs(int u,int pr){
	vis[u]=true;
	par[u]=pr;
	for(auto v:g[u])if(!vis[v])val[u]+=dfs(v,!pr);
	else isp&=!pr==par[v];
	int diff=t[u]-val[u];
	t[u]=val[u];
	return diff;
}

void ProGamerMove(){
	isp=true;
	int n,m;cin>>n>>m;
	for(int i=0;i<n;++i)cin>>val[i];
	for(int i=0;i<n;++i)cin>>t[i];
	for(int i=0;i<n;++i){
		g[i].clear();
		vis[i]=0;
		par[i]=-1;
	}
	for(int i=0;i<m;++i){
		int u,v;cin>>u>>v;--u;--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int diff=dfs(0,0);
	if((diff&&isp)||(!isp&&(diff&1))){
		cout<<"NO\n";return;
	}
	cout<<"YES\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}