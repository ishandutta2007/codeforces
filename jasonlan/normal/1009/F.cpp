#include<iostream>
#include<cstdio>
#include<cstring>
#define mid ((l+r)>>1)
using namespace std;
const int maxn=1010000,maxm=2020000;
int n,maxd;
int ans[maxn],dep[maxn];
int head[maxn],rdc[maxm],nxt[maxm],tnt;
int rt[maxn<<4],son[2][maxn<<4],cnt[maxn<<4],no[maxn<<4];
int ver,bin[maxn<<4],btop;
inline int read(){
    int res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
int getnew(){
	if(btop)return bin[btop--];
	return ++ver;
}
void recycle(int p){
	bin[++btop]=p;
	son[0][p]=son[1][p]=0;
	cnt[p]=0;
}
void update(int p){
	if(cnt[son[0][p]]>=cnt[son[1][p]]){
		cnt[p]=cnt[son[0][p]];
		no[p]=no[son[0][p]];
	}
	else{
		cnt[p]=cnt[son[1][p]];
		no[p]=no[son[1][p]];
	}
}
void modify(int &p,int x,int l,int r){
	if(!p)p=getnew();
	if(l==r){
		++cnt[p];no[p]=l;
		return;
	}
	if(x<=mid)modify(son[0][p],x,l,mid);
	else modify(son[1][p],x,mid+1,r);
	update(p);
}
int merge(int u,int v,int l,int r){
	if(!u||!v)return u|v;
	if(l==r)
		cnt[u]+=cnt[v];
	else{
		son[0][u]=merge(son[0][u],son[0][v],l,mid);
		son[1][u]=merge(son[1][u],son[1][v],mid+1,r);
		update(u);
	}
	recycle(v);
	return u;
}
void add(int u,int v){
	nxt[++tnt]=head[u];
	head[u]=tnt;
	rdc[tnt]=v;
}
void dfs1(int p){
	maxd=max(maxd,dep[p]);
	for(register int i=head[p];i;i=nxt[i])
		if(!dep[rdc[i]]){
			dep[rdc[i]]=dep[p]+1;
			dfs1(rdc[i]);
		}
}
void dfs2(int p){
	for(register int i=head[p];i;i=nxt[i])
		if(dep[rdc[i]]>dep[p]){
			dfs2(rdc[i]);
			rt[p]=merge(rt[p],rt[rdc[i]],1,maxd);
		}
	modify(rt[p],dep[p],1,maxd);
	ans[p]=no[rt[p]]-dep[p];
}
int main(){
	n=read();
	for(register int i=1,u,v;i<n;++i){
		u=read();v=read();
		add(u,v);add(v,u);
	}
	dep[1]=1;
	dfs1(1);
	dfs2(1);
	for(register int i=1;i<=n;++i)
		printf("%d\n",ans[i]);
	return 0;
}