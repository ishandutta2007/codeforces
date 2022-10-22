#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=100009;
int n,num,sz;
int c[M],head[M],rt[M],ls[M*23],rs[M*23],sum[M*23];
ll val[M*23];
struct P{int to,ne;}e[M<<1];
int read(){
	int rex=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){rex=rex*10+ch-'0';ch=getchar();}
	return rex*f;
}
void update(int&now,int l,int r,int x){
	if(!now)now=++sz;
	sum[now]=1;
	val[now]=x;
	if(l==r)return;
	int mid=(l+r)>>1;
	if(x<=mid)update(ls[now],l,mid,x);
	else update(rs[now],mid+1,r,x);
}
void pushup(int u){
	sum[u]=max(sum[ls[u]],sum[rs[u]]);
	val[u]=0;
	if(sum[ls[u]]==sum[u])val[u]+=val[ls[u]];
	if(sum[rs[u]]==sum[u])val[u]+=val[rs[u]];
}
int merge(int u,int v,int l,int r){
	if(!u||!v)return u|v;
	if(l==r){
		sum[u]+=sum[v];
		return u;
	}
	int mid=(l+r)>>1;
	ls[u]=merge(ls[u],ls[v],l,mid);
	rs[u]=merge(rs[u],rs[v],mid+1,r);
	pushup(u);
	return u;
}
void dfs(int u,int fa){
	update(rt[u],1,n,c[u]);
	for(int i=head[u];i;i=e[i].ne){
		int v=e[i].to;
		if(v!=fa){
			dfs(v,u);
			merge(rt[u],rt[v],1,n);
		}
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i)c[i]=read();
	for(int i=1,u,v;i<n;++i){
		u=read(),v=read();
		e[++num]=(P){v,head[u]};head[u]=num;
		e[++num]=(P){u,head[v]};head[v]=num;
	}
	dfs(1,0);
	for(int i=1;i<=n;++i)printf("%lld ",val[rt[i]]);
	return 0;
}