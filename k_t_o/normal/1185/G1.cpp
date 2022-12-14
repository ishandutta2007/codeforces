#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;
#define MO 1000000007 
inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
int t[15][15][15][4],f[15][15][15][4],ans,n,T,s[55],g[55];


int dfs(int i, int j, int k, int p)
{
	if(t[i][j][k][p])return f[i][j][k][p];
	t[i][j][k][p]=1;
	if(!i&&!j&&!k)return f[i][j][k][p]=1;
	int ans=0;
	if(i&&p!=1)ans=(ans+(long long)i*dfs(i-1,j,k,1)%MO)%MO;
	if(j&&p!=2)ans=(ans+(long long)j*dfs(i,j-1,k,2)%MO)%MO;
	if(k&&p!=3)ans=(ans+(long long)k*dfs(i,j,k-1,3)%MO)%MO;
	return f[i][j][k][p]=ans;
}

void df(int p,int ti, int i, int j, int k)
{
	if(ti>T)return;
	if(ti==T){
		int ii=i,jj=j,kk=k;
		if(ii<jj)swap(ii,jj);
		if(ii<kk)swap(ii,kk);
		if(jj<kk)swap(kk,jj);
		ans=(ans+f[ii][jj][kk][0])%MO;
		return;
	}
	if(p>n)return;
	df(p+1,ti,i,j,k);
	if(g[p]==1)df(p+1,ti+s[p],i+1,j,k);
	else if(g[p]==2)df(p+1,ti+s[p],i,j+1,k);
	else df(p+1,ti+s[p],i,j,k+1);
}

int main()
{
	for(int i=1;i<=13;++i)
	for(int j=0;j<=i;++j)
	for(int k=0;k<=j;++k){
		f[i][j][k][0]=dfs(i,j,k,0);
	}
	n=read(); T=read();
	for(int i=1;i<=n;++i){
		s[i]=read();
		g[i]=read();
	}
	df(1,0,0,0,0);
	printf("%d\n",ans);
}