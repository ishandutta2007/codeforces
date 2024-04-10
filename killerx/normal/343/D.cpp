#include<bits/stdc++.h>
using namespace std;
const int N=1<<20;
struct SegT{
	int lazy[N<<1],sum[N<<1];
	SegT(){
		memset(lazy,-1,sizeof lazy);
		memset(sum,0,sizeof sum);
	}
	void pd(int i,int l){
		if(~lazy[i]){
			sum[i]=lazy[i]*l;
			if(i<N){
				lazy[i<<1]=lazy[i<<1|1]=lazy[i];
			}
			lazy[i]=-1;
		}
	}
	void upd(int i,int a,int b,int l,int r,int v){
		pd(i,b-a);
		if(l<=a&&b<=r){
			lazy[i]=v;
			pd(i,b-a);return;
		}
		if(r<=a||b<=l)return;
		upd(i<<1,a,(a+b)>>1,l,r,v);
		upd(i<<1|1,(a+b)>>1,b,l,r,v);
		sum[i]=sum[i<<1]+sum[i<<1|1];
	}
	int qry(int i,int a,int b,int x){
		pd(i,b-a);
		if(a+1==b)return sum[i];
		if(x<((a+b)>>1))return qry(i<<1,a,(a+b)>>1,x);
		return qry(i<<1|1,(a+b)>>1,b,x);
	}
}segt;
int n;
int head[N],nxt[N],to[N],tot;
void add(int u,int v){
	nxt[tot]=head[u],head[u]=tot;
	to[tot]=v;++tot;
}
int dfn[N],id[N],top[N],sz[N],fa[N],cnt,Tm;
void dfs(int u,int p){
	sz[u]=1;
	fa[u]=p;
	for(int e=head[u];~e;e=nxt[e]){
		int v=to[e];
		if(v!=p){
			dfs(v,u);
			sz[u]+=sz[v];
		}
	}
}
void hld(int u,int p){
	int mx=-1;
	for(int e=head[u];~e;e=nxt[e]){
		int v=to[e];
		if(v!=p)if(!~mx||sz[mx]<sz[v])mx=v;
	}
	dfn[u]=Tm++;
	id[u]=cnt;
	if(!~top[id[u]])top[id[u]]=u;
	if(~mx)hld(mx,u);
	for(int e=head[u];~e;e=nxt[e]){
		int v=to[e];
		if(v!=p&&v!=mx)++cnt,hld(v,u);
	}
}
int main(){
	memset(head,-1,sizeof head);
	memset(top,-1,sizeof top);
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		int u,v;scanf("%d%d",&u,&v);
		--u,--v;add(u,v);add(v,u);
	}
	dfs(0,-1);
	hld(0,-1);
	int q;scanf("%d",&q);
	while(q--){
		int tp,u;scanf("%d%d",&tp,&u);--u;
		if(tp==1){
			segt.upd(1,0,N,dfn[u],dfn[u]+sz[u],1);
		}else if(tp==2){
			while(~u){
				segt.upd(1,0,N,dfn[top[id[u]]],dfn[u]+1,0);
				u=fa[top[id[u]]];
			}
		}else{
			printf("%d\n",segt.qry(1,0,N,dfn[u]));
		}
	}
	return 0;
}