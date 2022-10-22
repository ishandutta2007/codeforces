#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int M=200009;
const int B=450;
int n,q;
vector<int>g[M],b,c;
vector<pii>p[M];
int dp[M],pd[M];
int ans[M],dep[M],f[M];
void pre(int u,int fa){
	dep[u]=dep[fa]+1;
	f[u]=fa;
	for(auto v:g[u]){
		if(v!=fa){
			pre(v,u);
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].eb(v);
		g[v].eb(u);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;++i){
		int v,k;
		scanf("%d%d",&v,&k);
		p[k].eb(v,i);
	}
	for(int i=1;i<=n;++i)c.eb(i);
	pre(1,0);
	sort(c.begin(),c.end(),[&](const int&l,const int&r){return dep[l]>dep[r];});
	for(int k=0;k<=int(2e5);++k){
		if(k<=B){
			for(auto u:c){
				dp[u]=0;
				for(auto v:g[u]){
					if(v!=f[u]){
						dp[u]+=pd[v];
					}
				}
				pd[u]=max(dp[u]-k,1);
			}
		}
		else{
			b=c;
			c.clear();
			for(auto u:b){
				dp[f[u]]=dp[f[u]]-pd[u]+max(dp[u]-k,1);
				pd[u]=max(dp[u]-k,1);
				if(pd[u]>1)c.eb(u);
			}
		}
		for(auto o:p[k]){
			ans[o.se]=dp[o.fi];
		}
	}
	for(int i=1;i<=q;++i)printf("%d\n",ans[i]);
	return 0;
}
/*
8
6 7
3 2
8 3
5 7
7 4
7 1
7 3
1
1 1
*/