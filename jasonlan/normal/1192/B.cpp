#include<iostream>
#include<cstdio>
#define mid ((l+r)>>1)
#define ls son[0][p]
#define rs son[1][p]
using namespace std;
typedef long long ll;
const int maxn=201000,maxt=801000;
int n,q;
int dfn[maxn],dfe[maxn],tin[maxt],ts;
int head[maxn],nxt[maxt],rdc[maxt],tnt=1;
int rt,son[2][maxt];
ll len[maxt],dep[maxn],lastans,w;
ll lrdep[maxt],mdep[maxt],lm[maxt],rm[maxt],lmr[maxt],tag[maxt];
inline ll read(){
	ll res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void add(int u,int v,ll z){
	nxt[++tnt]=head[u];
	head[u]=tnt;
	rdc[tnt]=v;
	len[tnt]=z;
}
void addedge(int u,int v,ll z){
	add(u,v,z);add(v,u,z);
}
void dfs(int p){
	dfn[p]=++ts;
	tin[ts]=p;
	for(register int i=head[p];i;i=nxt[i])
		if(!dfn[rdc[i]]){
			dep[rdc[i]]=dep[p]+len[i];
			dfs(rdc[i]);
			tin[++ts]=p;
		}
	dfe[p]=ts;
}
void update(int p){
	mdep[p]=min(mdep[ls],mdep[rs]);
	lrdep[p]=max(lrdep[ls],lrdep[rs]);
	lm[p]=max(max(lm[ls],lm[rs]),lrdep[ls]-mdep[rs]*2);
	rm[p]=max(max(rm[ls],rm[rs]),lrdep[rs]-mdep[ls]*2);
	lmr[p]=max(max(lmr[ls],lmr[rs]),max(lm[ls]+lrdep[rs],lrdep[ls]+rm[rs]));
}
void pushtag(int p,ll x){
	lrdep[p]+=x;mdep[p]+=x;
	lm[p]-=x;rm[p]-=x;
	tag[p]+=x;
}
void pushdown(int p){
	if(!tag[p])return;
	pushtag(ls,tag[p]);
	pushtag(rs,tag[p]);
	tag[p]=0;
}
void build(int &p,int l,int r){
	p=++tnt;
	if(l==r){
		mdep[p]=lrdep[p]=dep[tin[l]];
		lm[p]=rm[p]=-dep[tin[l]];
		lmr[p]=0;
		return;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(p);
}
void modify(int p,int lr,int rr,ll x,int l,int r){
	if(lr<=l&&r<=rr){
		pushtag(p,x);return;
	}
	if(lr>r||l>rr)return;
	pushdown(p);
	modify(ls,lr,rr,x,l,mid);
	modify(rs,lr,rr,x,mid+1,r);
	update(p);
}
int main(){
	n=read();q=read();w=read();
	for(register int i=1,u,v;i<n;++i){
		u=read();v=read();
		addedge(u,v,read());
	}
	dfs(1);
	tnt=0;
	build(rt,1,ts);
	for(register int i=0,u,v;i<q;++i){
		ll d=(read()+lastans)%(n-1)+1,e=(read()+lastans)%w;
		u=rdc[d<<1];v=rdc[d<<1|1];
		if(dfn[u]<dfn[v])swap(u,v);
		modify(rt,dfn[u],dfe[u],e-len[d<<1],1,ts);
		len[d<<1]=len[d<<1|1]=e;
		printf("%lld\n",(lastans=lmr[rt]));
	}
	return 0;
}