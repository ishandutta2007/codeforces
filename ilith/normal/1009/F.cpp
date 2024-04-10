#include<bits/stdc++.h>
#define rgi register int
#define mid (l+r>>1)
typedef long long ll;
using namespace std;
inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){
	T x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	A=x*f,read(As...);
}
inline void write(char a){putchar(a);}
template <typename T> inline void write(T a){
	if(a<0ll)putchar('-'),a=-a;
	if(a>9ll)write(a/10ll);
	putchar(a%10ll+'0');
}
template <typename T,typename... Ts> inline void write(T A,Ts... As){write(A),write(As...);}
const int N=1000010;
int n,m,u,v,w;
int pos[N*25],ls[N*25],rs[N*25],cnt,ma[N*25];
int rt[N<<1],dep[N],q[N<<3],SZ;
inline int newnode(){
	if(SZ>(N<<3)-10)return ++cnt;
	return SZ?q[SZ--]:++cnt;
}
inline int pushup(int k){
	if(ma[ls[k]]>=ma[rs[k]])return ma[k]=ma[ls[k]],pos[k]=pos[ls[k]],k;
	return ma[k]=ma[rs[k]],pos[k]=pos[rs[k]],k;
}
void upd(int& k,int l,int r,int x,int V){
	if(r<x||l>x)return;
	if(!k)k=newnode();
	if(r==x&&l==x)return pos[k]=l,void(ma[k]+=V);
	upd(ls[k],l,mid,x,V),upd(rs[k],mid+1,r,x,V);
	pushup(k);
}
inline void upd(int& rt,int x,int V){upd(rt,1,N,x,V);}
inline void del(int x){
	if(SZ<N-1)q[++SZ]=x,ls[x]=rs[x]=pos[x]=ma[x]=0;
}
int merge(int k1,int k2,int l,int r){
	if(!k1||!k2)return k1^k2;
	if(l==r)return ma[k1]+=ma[k2],pos[k1]=l,del(k2),k1;
	ls[k1]=merge(ls[k1],ls[k2],l,mid),rs[k1]=merge(rs[k1],rs[k2],mid+1,r);
	return del(k2),pushup(k1);
}
int ans[N],to[N<<1],nxt[N<<1],hd[N<<1],tot,fa[N];
inline void link(int u,int v){
	to[++tot]=v,nxt[tot]=hd[u],hd[u]=tot;
}
void dfs(int x,int f){
	dep[x]=dep[f]+1,fa[x]=f;
	for(rgi i=hd[x];i;i=nxt[i]){
		if(to[i]!=fa[x])dfs(to[i],x);
	}
}
void dfs2(int x,int f){
	for(rgi i=hd[x];i;i=nxt[i]){
		if(to[i]!=f)dfs2(to[i],x),rt[x]=merge(rt[x],rt[to[i]],1,N);
	}
	ans[x]=!!ma[rt[x]]*pos[rt[x]];
}
signed main(){
//	freopen("dt.in","r",stdin);
//	freopen("dt.out","w",stdout);
	read(n);
	for(rgi i=1;i<n;++i){
		read(u,v),link(u,v),link(v,u);
	}
	dfs(1,0);
	for(rgi i=1;i<=n;++i)upd(rt[i],dep[i],1);
	dfs2(1,0);
	for(rgi i=1;i<=n;++i)write(ans[i]-dep[i],'\n');
	return 0;
}