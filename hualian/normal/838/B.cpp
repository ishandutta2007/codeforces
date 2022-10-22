#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=4e5+9;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)&&(x=y);}
void chmn(int &x,int y){(x>y)&&(x=y);}
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,q; 
vector<int>e[N];
int fa[N],To[N];
int dfn[N],idx,sz[N];
void dfs(int x){
	dfn[x]=++idx;sz[x]=1;
	for(int to:e[x])dfs(to),sz[x]+=sz[to];
}
struct tree{
	#define ls (p<<1)
	#define rs (p<<1|1)
	int mn[N<<2],tag[N<<2];
	void push_down(int p){
		if(!tag[p])return;
		mn[ls]+=tag[p];
		mn[rs]+=tag[p];
		tag[ls]+=tag[p];
		tag[rs]+=tag[p];
		tag[p]=0;
	}
	void add(int p,int l,int r,int nl,int nr,int v){
		if(nl<=l&&r<=nr){mn[p]+=v;tag[p]+=v;return;}
		int mid=(l+r)>>1;push_down(p);
		if(mid>=nl)add(ls,l,mid,nl,nr,v);
		if(mid<nr) add(rs,mid+1,r,nl,nr,v);
		mn[p]=min(mn[ls],mn[rs]);
	}
	int get(int p,int l,int r,int nl,int nr){
		if(nl<=l&&r<=nr)return mn[p];
		int mid=(l+r)>>1,res=1e18;push_down(p);
		if(mid>=nl)chmn(res,get(ls,l,mid,nl,nr));
		if(mid<nr)chmn(res,get(rs,mid+1,r,nl,nr));
		mn[p]=min(mn[ls],mn[rs]);
		return res;
	}
}T1,T2;
int w1[N],w2[N];
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	n=read();q=read();
	rep(i,n-1){
		int x=read(),y=read();
		To[i]=y;fa[y]=x;
		e[x].push_back(y);
		w1[y]=read();
	}
	rep(i,n-1){
		int x=read(),y=read();
		To[i+n-1]=x;
		assert(y==1);
		w2[x]=read();
	}
	dfs(1);
	rep(i,n){
		T1.add(1,1,n,dfn[i],dfn[i]+sz[i]-1,w1[i]);
		T2.add(1,1,n,dfn[i],dfn[i]+sz[i]-1,w1[i]);
		T2.add(1,1,n,dfn[i],dfn[i],w2[i]);
	}
	while(q--){
		int op=read();
		if(op==1){
			int i=read(),w=read();
			if(i<=n-1){
				i=To[i];
				T1.add(1,1,n,dfn[i],dfn[i]+sz[i]-1,-w1[i]+w);
				T2.add(1,1,n,dfn[i],dfn[i]+sz[i]-1,-w1[i]+w);
				w1[i]=w;
			}else{
				i=To[i];
				T2.add(1,1,n,dfn[i],dfn[i],-w2[i]+w);
				w2[i]=w;
			}
		}else{
			int x=read(),y=read(),res=1e18;
			if(dfn[x]<=dfn[y]&&dfn[y]<dfn[x]+sz[x]){
				chmn(res,T1.get(1,1,n,dfn[y],dfn[y])-T1.get(1,1,n,dfn[x],dfn[x]));
			}
			chmn(res,T2.get(1,1,n,dfn[x],dfn[x]+sz[x]-1)-T1.get(1,1,n,dfn[x],dfn[x])+T1.get(1,1,n,dfn[y],dfn[y]));
			printf("%lld\n",res);
		}
	}
	return 0;
}