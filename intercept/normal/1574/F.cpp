#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
const int M=3e5+9;
int n,m,k;
int s[M],b[M],vis[M],f[M],dp[M],t[M];
vector<int>p[M],c[M],h;  
vector<pii>g[M];
map<int,int>mp[M],mm;
bool in[M];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
int l,r;
void dfs(int u,int fa,int w){
	in[u]=1;
	if(fa){
		int x=mm[w],y=mp[u][w];
		for(int i=x,j=y;j>=0;--i,--j){
			if(i<l)l--,mm[c[u][j]]=i;
			else if(mm[c[u][j]]!=i)vis[u]=-1;
		}
		for(int i=x,j=y;j<s[u];++i,++j){
			if(i>r)r++,mm[c[u][j]]=i;
			else if(mm[c[u][j]]!=i)vis[u]=-1;
		}
	}
	else {
		l=0,r=s[u]-1;
		for(int i=0;i<=r;++i)mm[c[u][i]]=i;
	}
	for(auto o:g[u]){
		if(!in[o.first]){
			dfs(o.first,u,o.second);
			vis[u]|=vis[o.first];
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)f[i]=i;
	for(int i=1,l;i<=n;++i){
		scanf("%d",&l);
		c[i].resize(l);
		s[i]=l;
		for(int j=0;j<l;++j){
			scanf("%d",&c[i][j]);
			p[c[i][j]].push_back(i);
			mp[i][c[i][j]]=j;
		}
	}
	for(int i=1;i<=k;++i){
		if(p[i].size()==0)continue;
		sort(p[i].begin(),p[i].end(),[&](const int&l,const int&r){return s[l]<s[r];});
		bool bol=0;
		for(auto v:p[i]){
			bol|=t[v];
			t[v]++;
		}
		int u=find(p[i][0]);
		for(auto v:p[i])t[v]--,vis[v]=bol;
		for(auto v:p[i]){
			f[find(v)]=u;
			g[p[i][0]].emplace_back(v,i);
			g[v].emplace_back(p[i][0],i);
		}
	}
	for(int i=1;i<=n;++i){
		if(i==f[i]&&!vis[i]){
			mm.clear();
			dfs(i,0,0);
			vis[i]|=(mm.size()!=r-l+1);
			if(!vis[i])b[mm.size()]++;
			for(auto v:c[i])t[v]--;
		}
	}
	for(int i=1;i<=k;++i)if(p[i].size()==0)b[1]++;
	for(int i=1;i<=k;++i)if(b[i])h.push_back(i);
	dp[0]=1;
	for(int i=1;i<=m;++i){
		for(auto v:h){
			if(i>=v)dp[i]=(dp[i]+1ll*dp[i-v]*b[v]%mod)%mod;
		}
	}
	printf("%d\n",dp[m]);
	return 0;
}