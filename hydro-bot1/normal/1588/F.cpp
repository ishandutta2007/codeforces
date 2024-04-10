// Hydro submission #62a34aa6cd1ee6a7e1688896@1654868647595
#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
namespace code{
	#define int long long
	inline int read(){
		int a=0,b=1;char s=getchar();
		while(s<48||s>57){if(s=='-'){b=-1;}s=getchar();}
		while(s>=48&&s<=57)a=(a<<1)+(a<<3)+s-48,s=getchar();
		return a*b;
	}
	#define R register
	const int maxn=2e5,B=500;
	int n,a[maxn+5],b[maxn+5],p[maxn+5],q,block,d[maxn+5];
	struct node{int opt,x,y;}que[maxn+5];
	int bel[maxn+5],ed[2*B+5];bool use[maxn+5];
	struct pr{int x,y;};vector<pr> vec[maxn+5];
	int num[2*B+5],val[2*B+5][B+5],tag[2*B+5];
	inline void main(){
		n=read();
		for(R int i=1;i<=n;i=-~i)a[i]=read();
		for(R int i=1;i<=n;i=-~i)b[i]=b[i-1]+a[i];
		for(R int i=1;i<=n;i=-~i)p[i]=read(),d[p[i]]=i;
		q=read();block=sqrt(n);
		for(R int i=1;i<=q;i=-~i)que[i]=(node){read(),read(),read()};
		for(R int l=1,r;l<=q;l=r+1){
			r=min(q,l+block-1);
			for(R int i=l;i<=r;i=-~i){
				if(que[i].opt==2)use[que[i].x]=true;
				if(que[i].opt==3)use[que[i].x]=use[que[i].y]=true;
			}
			int cnt=0;
			for(R int i=1;i<=n;i=-~i)
				if(use[i]){
					++cnt;ed[cnt]=i,bel[i]=cnt;
					for(R int j=d[i];!use[j];j=d[j])bel[j]=cnt;
				}
			for(R int i=l;i<=r;i=-~i)if(que[i].opt==1)vec[que[i].x-1].push_back((pr){i,-1}),vec[que[i].y].push_back((pr){i,1});
			for(R int i=1;i<=n;i=-~i){
				++num[bel[i]];
				for(R int k=0;k<(int)vec[i].size();k=-~k)
					for(R int j=1;j<=cnt;j=-~j)
						val[j][vec[i][k].x-l]+=vec[i][k].y*num[j];
			}
			for(R int i=l;i<=r;i=-~i){
				switch(que[i].opt){
					case 1:{
						int ans=b[que[i].y]-b[que[i].x-1];
						for(R int j=1;j<=cnt;j=-~j)ans+=tag[j]*val[j][i-l];
						printf("%lld\n",ans);break;
					}
					case 2:{
						tag[bel[que[i].x]]+=que[i].y;
						for(R int j=bel[p[ed[bel[que[i].x]]]];j!=bel[que[i].x];j=bel[p[ed[j]]])tag[j]+=que[i].y;
						break;
					}
					case 3:{swap(d[p[que[i].x]],d[p[que[i].y]]),swap(p[que[i].x],p[que[i].y]);break;}
				}
			}
			for(R int i=1;i<=n;i=-~i)a[i]+=tag[bel[i]];
			for(R int i=1;i<=n;i=-~i)b[i]=b[i-1]+a[i];
			for(R int i=1;i<=n;i=-~i)bel[i]=0;
			for(R int i=1;i<=cnt;i=-~i)tag[i]=num[i]=0;
			for(R int i=1;i<=cnt;i=-~i)for(R int j=l;j<=r;j=-~j)val[i][j-l]=0;
			for(R int i=l;i<=r;i=-~i){
				if(que[i].opt==1)vec[que[i].x-1].clear(),vec[que[i].y].clear();
				if(que[i].opt==2)use[que[i].x]=false;
				if(que[i].opt==3)use[que[i].x]=use[que[i].y]=false;
			}
		}
	}
	#undef int
}
int main(){return code::main(),0;}