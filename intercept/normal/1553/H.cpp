#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int M=2000009;
int n,k,sz=1;
int c[M][2],a[M];
vector<int>ls[M],rs[M],ans[M];
void dfs(int u,int s){
	if(!u)return;
	if(!s){
		ls[u].eb(a[u]);
		rs[u].eb(a[u]);
		ans[u].eb((int)1e9);
		return;
	}
	int l=c[u][0],r=c[u][1];
	dfs(l,s-1);
	dfs(r,s-1);
	if(!l)l=r;
	if(!r)r=l;
	for(int i=0;i<1<<s-1;++i){
		ls[u].eb(ls[l][i]);
		rs[u].eb(rs[r][i]);
		int x=min(ans[l][i],ans[r][i]);
		if(l!=r)x=min(x,ls[r][i]-rs[l][i]);
		ans[u].eb(x);
	}
	for(int i=0;i<1<<s-1;++i){
		if(c[u][1])ls[u].eb(ls[r][i]-(1<<s-1));
		else ls[u].eb(ls[l][i]+(1<<s-1));
		if(c[u][0])rs[u].eb(rs[l][i]+(1<<s-1));
		else rs[u].eb(rs[r][i]-(1<<s-1));
		int x=min(ans[l][i],ans[r][i]);
		if(l!=r)x=min(x,ls[l][i]+(1<<s)-rs[r][i]);
		ans[u].eb(x);
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1,x;i<=n;++i){
		scanf("%d",&x);
		for(int j=k-1,u=1;j>=0;--j){
			int o=x>>j&1;
			if(!c[u][o])c[u][o]=++sz;
			u=c[u][o];
			a[u]=x;
		}
	}
	dfs(1,k);
	for(auto o:ans[1])printf("%d ",o);
	return 0;
}