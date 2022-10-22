#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int mod=998244353;
const int M=5e5+9;
int n,m;
int dep[M],f[M],vis[M],in[M];
vector<int>g[M];
vector<pii>ans;
set<pii>s[M];
bool flag=0;
void dfs(int u,int fa){
	f[u]=fa;
	dep[u]=dep[fa]+1;
	vis[u]=1;
	for(auto v:g[u]){
		if(v!=fa){
			if(!vis[v]){
				dfs(v,u);
				if(s[u].size()<s[v].size())swap(s[u],s[v]);
				while(s[v].size()){
					auto o=*s[v].rbegin();
					auto t=*s[u].rbegin();
					ans.eb(o.se,t.se);
					s[v].erase(o);
					s[u].erase(t);
				}
				s[v].clear();
			}
			else if(dep[u]-dep[v]+1>=(n+1)/2&&!flag){
				cout<<"PATH\n";
				cout<<dep[u]-dep[v]+1<<"\n";
				while(u!=f[v])cout<<u<<" ",u=f[u];
				cout<<"\n";
				flag=1;
			}
		}
	}
	s[u].insert(make_pair(dep[u],u));
}
void work(){
	flag=0;
	cin>>n>>m;
	ans.clear();
	for(int i=1;i<=n;++i)g[i].clear(),s[i].clear(),vis[i]=0,in[i]=0;
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		g[u].eb(v);
		g[v].eb(u);
	}
	dfs(1,0);
	if(flag)return;
	while(s[1].size()>1){
		if(s[1].rbegin()->fi-s[1].begin()->fi+1>=(n+1)/2){
			ans.eb(s[1].rbegin()->se,s[1].begin()->se);
			s[1].erase(s[1].begin());
			auto o=*s[1].rbegin();
			s[1].erase(o);
		}
		else break;
	}
	cout<<"PAIRING\n";
	cout<<ans.size()<<"\n";
	for(auto o:ans)cout<<o.fi<<" "<<o.se<<"\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}