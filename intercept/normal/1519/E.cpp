#include<bits/stdc++.h>
#define eb emplace_back
#define pii pair<int,int>
#define pll pair<long long,long long>
using namespace std;
const int M=4e5+9;
int n,num,ans;
bool vis[M],be[M];
map<pll,int>mp;
vector<pii>g[M];
pii s[M];
vector<int>f[M];
void dfs(int u,int fa,int w){
	vis[u]=1;
	for(auto o:g[u]){
		int v=o.first,id=o.second;
		if(v!=fa){
			if(!vis[v])dfs(v,u,id);
			if(!be[id])f[u].eb(id);
		}
	}
	for(int i=0,S=f[u].size();i<S;i+=2){
		if(i+1<S){
			s[++ans]=pii{f[u][i],f[u][i+1]};
			be[f[u][i]]=1;
			be[f[u][i+1]]=1;
		}
		else if(w){
			s[++ans]=pii{f[u][i],w};
			be[f[u][i]]=be[w]=1;
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		long long a,b,c,d,z;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		z=__gcd((a+b)*d,c*b);
		pll x=pll{(a+b)*d/z,c*b/z};
		z=__gcd(a*d,(c+d)*b);
		pll y=pll{a*d/z,(c+d)*b/z};
		if(!mp.count(x))mp[x]=++num;
		if(!mp.count(y))mp[y]=++num;
		int u=mp[x];
		int v=mp[y];
		g[u].eb(v,i);
		g[v].eb(u,i);
	}
	for(int i=1;i<=num;++i){
		if(!vis[i])dfs(i,0,0);
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;++i){
		printf("%d %d\n",s[i].first,s[i].second);
	}
	return 0;
}