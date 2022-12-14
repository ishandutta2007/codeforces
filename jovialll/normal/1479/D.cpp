#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define N 300005
#define mid (l+r>>1)
#define pb push_back
ull s,t[N],v[N<<5];vector<int>son[N];
int ls[N<<5],rs[N<<5],node_cnt,n,fa[N][20],dep[N],a[N],rt[N];
void nxt(){s^=(s<<13);s^=(s>>21);s^=(s<<5);}
void modify(int &now,int las,int l,int r,int x,ull val){
	now=++node_cnt;v[now]=v[las]^val;if(l==r)return ;
	if(x<=mid)rs[now]=rs[las],modify(ls[now],ls[las],l,mid,x,val);
	else ls[now]=ls[las],modify(rs[now],rs[las],mid+1,r,x,val);
}void dfs(int now,int fat){
	modify(rt[now],rt[fat],1,n,a[now],t[a[now]]);fa[now][0]=fat;dep[now]=dep[fat]+1;
	for(int T,i=0;i<son[now].size();++i)if((T=son[now][i])!=fat)dfs(T,now);
}int query(int z1,int z2,int f1,int f2,int l,int r,int x,int y){
	if(x<=l&&r<=y){
		if((v[z1]^v[z2]^v[f1]^v[f2])==0)return -1;
		if(l==r)return l;
		return (v[ls[z1]]^v[ls[z2]]^v[ls[f1]]^v[ls[f2]])?query(ls[z1],ls[z2],ls[f1],ls[f2],l,mid,x,y):query(rs[z1],rs[z2],rs[f1],rs[f2],mid+1,r,x,y);
	}if(x>r||y<l)return -1;
	int ret=query(ls[z1],ls[z2],ls[f1],ls[f2],l,mid,x,y);
	if(~ret)return ret;
	return query(rs[z1],rs[z2],rs[f1],rs[f2],mid+1,r,x,y);
}int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);int i;for(i=18;~i;--i)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];if(x==y)return x;
	for(i=18;~i;--i)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];return fa[x][0];
}int i,j,U,V,x,y,q,LCA;signed main(){
	for(cin>>n>>q,i=1;i<=n;++i)cin>>a[i];
	for(i=1;i<n;++i)cin>>x>>y,son[x].pb(y),son[y].pb(x);
	s=1ll*rand()*rand();nxt();nxt();nxt();nxt();
	for(i=1;i<=n;++i)t[i]=s,nxt();dfs(1,0);
	for(i=1;i<=18;++i)for(j=1;j<=n;++j)fa[j][i]=fa[fa[j][i-1]][i-1];
	while(q--)cin>>U>>V>>x>>y,LCA=lca(U,V),cout<<query(rt[U],rt[V],rt[LCA],rt[fa[LCA][0]],1,n,x,y)<<'\n';
}