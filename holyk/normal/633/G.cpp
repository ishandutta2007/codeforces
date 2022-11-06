#include<bits/stdc++.h>
#define lson o<<1
#define rson o<<1|1
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
inline int read(){
	int w=0,p=0;char c;
	while(!isdigit(c=getchar()))if(c=='-')p=1;
	while(isdigit(c))w=(w<<1)+(w<<3)+(c^'0'),c=getchar();
	return p?-w:w;
}
const int N=1e5+7;
typedef bitset<1007> bts;
int n,m,tot,w[N],head[N],v[N<<1],nxt[N<<1],in[N],rid[N],out[N],cnt;
bts pri;
inline void adde(int x,int y){v[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
void dfs(int x){
	in[x]=++cnt;rid[cnt]=x;
	for(int i=head[x];i;i=nxt[i]){
		int &y=v[i];
		if(!in[y])dfs(y);
	}
	out[x]=cnt;
}

bts val[N<<2];
int tag[N<<2];
inline void pushup(int o){val[o]=val[lson]|val[rson];}
inline void build(int o,int l,int r){
	tag[o]=0;
	if(l==r){
		val[o].reset();val[o][w[rid[l]]]=1;
		return;
	}
	int mid=l+r>>1;
	build(lson,l,mid);build(rson,mid+1,r);
	pushup(o);
}
inline void mov(int o,int x){val[o]=(val[o]<<x)|(val[o]>>(m-x));}
inline void pushdown(int o){
	if(tag[o]){
		(tag[lson]+=tag[o])%=m;(tag[rson]+=tag[o])%=m;
		mov(lson,tag[o]);mov(rson,tag[o]);
		tag[o]=0;
	}
}
inline void update(int o,int l,int r,int x,int y,int k){
	if(x<=l&&r<=y){
		(tag[o]+=k)%=m;mov(o,k);return;
	}
	pushdown(o);
	int mid=l+r>>1;
	if(x<=mid)update(lson,l,mid,x,y,k);
	if(y>mid)update(rson,mid+1,r,x,y,k);
	pushup(o);
}
inline bts query(int o,int l,int r,int x,int y){
	if(x<=l&&r<=y)return val[o];
	pushdown(o);
	int mid=l+r>>1;
	bts ret;
	if(x<=mid)ret|=query(lson,l,mid,x,y);
	if(y>mid)ret|=query(rson,mid+1,r,x,y);
	return ret;
}
int main(){
	n=read(),m=read();
	REP(i,2,m-1)pri[i]=1;
	REP(i,2,m)if(pri[i])
		for(int j=i*i;j<m;j+=i)pri[j]=0;
	REP(i,1,n)w[i]=read()%m;
	REP(i,2,n){
		int x=read(),y=read();
		adde(x,y);adde(y,x);
	}
	dfs(1);build(1,1,n);
	int q=read();
	while(q--){
		int x=read(),u=read();
		if(x==1){
			update(1,1,n,in[u],out[u],read()%m);
		}
		else{
			bts tmp=query(1,1,n,in[u],out[u]);
			printf("%d\n",(pri&tmp).count());
		}
	}
	return 0;
}