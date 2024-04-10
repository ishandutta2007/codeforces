// Hydro submission #62a284fdcd1ee6a7e1681d26@1661005671018
#include<iostream>
#include<cstdio>
#include<cmath>
#define R register
using namespace std;
namespace ysx{
	const int maxn=1e4;
	inline int read(){
		int a=0,b=1;char s=getchar();
		while(s<48||s>57){if(s=='-'){b=-1;}s=getchar();}
		while(s>=48&&s<=57)a=(a<<1)+(a<<3)+s-48,s=getchar();
		return a*b;
	}
	int n,m;
	struct node{int u,v;}t[maxn+5];
	inline void input(){
		n=read(),m=read();
		for(R int i=1;i<=m;i=-~i)t[i]=(node){read(),read()};
	}
	int sq,bel[maxn+5],lc[105],rc[105];
	inline void prework(){
		if(m){
			sq=sqrt(m);
			for(R int i=1;i<=m;i=-~i)bel[i]=(i-1)/sq+1;
			sq=(m-1)/sq+1;
			for(R int i=1;i<=m;i=-~i)lc[bel[i]]=!lc[bel[i]]?i:lc[bel[i]],rc[bel[i]]=i;
		}
	}
	namespace dsu{
		int fa[maxn+5],siz[maxn+5],top,val[maxn+5];
		struct Sta{int u,v,siz;}sta[maxn+5];
		inline void init(){for(R int i=1;i<=n;i=-~i)fa[i]=i,siz[i]=1;}
		inline int find(int u,int &du){while(fa[u]!=u){du^=val[u],u=fa[u];}return u;}
		inline void swap(int &a,int &b){a^=b^=a^=b;}
		inline void merge(int u,int v,int w){
			if(siz[u]>siz[v])swap(u,v);
			sta[++top]=(Sta){u,v,siz[u]};
			fa[u]=v,siz[v]+=siz[u],val[u]=w^1;
		}
		inline void del(int now){
			while(top>now)val[sta[top].u]=0,fa[sta[top].u]=sta[top].u,siz[sta[top].v]-=sta[top].siz,--top;
		}
	}
	inline bool work(int x){
		for(R int i=1;i<=m;i=-~i){
			if(bel[i]!=x){
				int du=0,dv=0,u=dsu::find(t[i].u,du),v=dsu::find(t[i].v,dv);
				if(u!=v)dsu::merge(u,v,du^dv);
				else if(!(du^dv))return false;
			}
		}
		return true;
	}
	inline bool work(int x,int y){
		for(R int i=lc[x];i<=rc[x];i=-~i){
			if(i!=y){
				int du=0,dv=0,u=dsu::find(t[i].u,du),v=dsu::find(t[i].v,dv);
				if(u!=v)dsu::merge(u,v,du^dv);
				else if(!(du^dv))return false;
			}
		}
		return true;
	}
	int ans,sta[maxn+5],top;
	inline void solve(){
		if(m){
			dsu::init();
			for(R int i=1;i<=sq;i=-~i){
				if(work(i)){
					int now=dsu::top;
					for(R int j=lc[i];j<=rc[i];j=-~j){
						if(work(i,j))++ans,sta[++top]=j;
						dsu::del(now);
					}
				}
				dsu::del(0);
			}
		}
		printf("%d\n",ans);for(R int i=1;i<=top;i=-~i)printf("%d ",sta[i]);
	}
	inline void run(){input(),prework(),solve();}
}
int main(){return ysx::run(),0;}