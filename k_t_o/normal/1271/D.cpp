#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
#define N 5005
int ma,o[N],sz[N],f[N][N],G[N][N],u,v,n,m,k,a[N],b[N],c[N];
int main()
{
	n=read(); m=read(); k=read();
	for(int i=1;i<=n;++i)a[i]=read(),b[i]=read(),c[i]=read();
	for(int i=1;i<=m;++i){
		u=read(); v=read();
		o[v]=max(o[v],u);
	}for(int i=1;i<=n;++i)o[i]=max(o[i],i);
	for(int i=1;i<=n;++i)G[o[i]][++sz[o[i]]]=c[i];
	for(int i=1;i<=n;++i)sort(G[i]+1,G[i]+sz[i]+1);
	
	memset(f,-1,sizeof(f));
	f[0][k]=0;
	for(int i=1;i<=n;++i){
		for(int j=a[i];j<=5000;++j){
			if(f[i-1][j]==-1)continue; 
			f[i][j+b[i]]=f[i-1][j];
		}
		for(int k=sz[i];k;--k){
			for(int j=1;j<=5000;++j){
				if(f[i][j]==-1)continue;
				f[i][j-1]=max(f[i][j-1],f[i][j]+G[i][k]);
			}
		}
	}
	ma=-1;
	for(int i=5000;i>=0;--i){
		ma=max(ma,f[n][i]);
	}
	printf("%d\n",ma);
}