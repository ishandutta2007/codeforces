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
#define N 410005
int si[N],a[N],c[N][3],tot,n,u,v,w;
long long Ans;
void df(int p, int pr)
{
	si[p]=1; int u;
	for(int o=a[p];o;o=c[o][1]){
		u=c[o][0];
		if(u==pr)continue;
		df(u,p); si[p]+=si[u];
		if(si[u]&1)Ans+=c[o][2];
	}
}

void dfs(int p, int pr)
{
	int u,_;
	for(int o=a[p];o;o=c[o][1]){
		u=c[o][0];if(u==pr)continue;
		dfs(u,p);
		_=min(si[u],n-si[u]);
		Ans+=(long long)_*c[o][2];
	}
}

int main()
{
	int T=read();
	while(T--){
		n=read();n<<=1;memset(a,0,(n+1)*sizeof(int)); tot=0;
		for(int i=1;i<n;++i){
			u=read();v=read(); w=read();
			c[++tot][0]=v; c[tot][1]=a[u]; a[u]=tot; c[tot][2]=w;
			c[++tot][0]=u; c[tot][1]=a[v]; a[v]=tot; c[tot][2]=w;
		}
		Ans=0; df(1,0); printf("%lld ",Ans); 
		Ans=0; dfs(1,0); printf("%lld\n",Ans); 
	}
}