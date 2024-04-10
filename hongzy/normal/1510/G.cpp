#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define vit vector<int>::iterator
#define sit set<pr>::iterator
#define pb push_back
#define ll long long
using namespace std;
const int N=1e6+6; 
int r,fa[N],d[N],tg[N]; vector<int> G[N];
void dfs(int u){
	printf("%d ",u);
	if (!tg[u]) --r; bool in=false;
	rep0(i,G[u].size())
		if (r&&!tg[G[u][i]]){ dfs(G[u][i]),in=true; printf("%d ",u); }
	rep0(i,G[u].size()) if (tg[G[u][i]]) dfs(G[u][i]);
}
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n,k,mx=0; scanf("%d%d",&n,&k);
		rep(i,1,n) tg[i]=0,G[i].clear();
		rep(i,2,n){
			scanf("%d",&fa[i]); d[i]=d[fa[i]]+1;
			if (d[i]>mx) mx=d[i];
			G[fa[i]].push_back(i);
		}
		int t=min(k-1,mx); printf("%d\n",2*(k-1)-t);
		int u=1; rep(i,1,n) if (d[i]==t) u=i;
		for (int i=u;i;i=fa[i]) tg[i]=1;
		r=k-t-1; dfs(1); putchar('\n');
	}
	return 0;
}