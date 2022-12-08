#include <cstdio>
#include <algorithm>
#include <iostream>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define efo(i,q) for(int i=A[q];i;i=B[i][0])
#define min(q,w) ((q)>(w)?(w):(q))
#define max(q,w) ((q)<(w)?(w):(q))
using namespace std;
typedef long long LL;
const int N=100500,M=202,mo=1e9+7;
int read(int &n)
{
	char ch=' ';int q=0,w=1;
	for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
	if(ch=='-')w=-1,ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;n=q*w;return n;
}
int m,n;
int B[2*N][2],A[N],B0;
int Si[N];
LL ans;
LL f[N][M],f1[N][M],Ans[M];
LL st1[M][M];
void link(int q,int w)
{
	B[++B0][0]=A[q],A[q]=B0,B[B0][1]=w;
	B[++B0][0]=A[w],A[w]=B0,B[B0][1]=q;
}
void dfs(int q,int fa)
{
	f[q][0]=2;Si[q]=1;
	efo(i,q)if(B[i][1]!=fa)
	{
		dfs(B[i][1],q);
		for(int k=0;k<=m&&k<=Si[q];++k)
			for(int j=0;j<=Si[B[i][1]]&&j+k<=m;++j)f[0][k+j]=(f[0][k+j]+f[q][k]*f[B[i][1]][j])%mo;
		Si[q]+=Si[B[i][1]];
		for(int j=0;j<=m&&j<=Si[q];++j)
		{
			f[q][j]=f[0][j],f[0][j]=0;
			f1[q][j]=(f1[q][j]+f[B[i][1]][j])%mo;
		}
	}
	fo(i,0,m)Ans[i]=(Ans[i]+f[q][i]-f1[q][i])%mo;
	fod(i,m,1)f[q][i]=(f[q][i]+f[q][i-1])%mo;
	--f[q][1];
}
int main()
{
	int q,w;
	read(n),read(m);
	fo(i,2,n)read(q),read(w),link(q,w);
	st1[0][0]=1;
	fo(i,1,m)
	{
		fo(j,1,i)st1[i][j]=(st1[i-1][j-1]+st1[i-1][j]*j)%mo;
	}
	dfs(1,0);
	ans=0;
	LL t=1;
	fo(i,0,m)
	{
		ans=(ans+st1[m][i]*t%mo*Ans[i])%mo;
		t=t*(i+1LL)%mo;
	}
	printf("%lld\n",(ans+mo)%mo);
	return 0;
}