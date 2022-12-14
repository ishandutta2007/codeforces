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
#define N 2100005
int u[N],v[N],n,m,a[N],c[N][2],tot,F[N],op[N],_op[N],uu;;
long long Ans;
int cnt[4];
int main()
{
	n=read(); m=read();
	for(int i=1;i<=m;++i){
		u[i]=read();v[i]=read();
		c[++tot][0]=v[i];c[tot][1]=a[u[i]];a[u[i]]=tot;
		c[++tot][0]=u[i];c[tot][1]=a[v[i]];a[v[i]]=tot;
	}
	uu=0;
	for(int o=a[1]; o; o=c[o][1]){
		op[c[o][0]]=1;
		uu=c[o][0];
	}
	F[1]=1;
	for(int i=1;i<=n;++i)if(!op[i])F[i]=1;
	if(!uu){
		puts("-1");return 0;
	}
	F[uu]=2;
	for(int o=a[uu]; o; o=c[o][1]){
		_op[c[o][0]]=1;
	}
	for(int i=1;i<=n;++i)if(!F[i]&&!_op[i])F[i]=2;
	for(int i=1;i<=n;++i){
		++cnt[F[i]];
	}
	Ans=(long long)cnt[0]*(n-cnt[0])+(long long)cnt[1]*cnt[2];
	if(Ans!=m){
		puts("-1");return 0;
	}
	for(int i=1;i<=m;++i)if(F[u[i]]==F[v[i]]){
		puts("-1");return 0;
	}
	if(!cnt[0]){
		puts("-1");return 0;
	}
	for(int i=1;i<=n;++i)printf("%d ",F[i]+1);
}