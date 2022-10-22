#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define L 1<<20
#define oo 1000000000
#define MAXN 200005
char _buf[L],*S,*T,c;
inline char gc()
{
	if(S==T)
	{
		T=(S=_buf)+fread(_buf,1,L,stdin);
		if(S==T)return 0;
	}
	return *S++;
}
int n,m,i,j,k,l,a[MAXN],f[21][1048576],ans=oo,s;
int main()
{
	for(c=gc();c<'0'||c>'9';c=gc());
	for(n=c^'0',c=gc();c>='0'&&c<='9';c=gc())n=n*10+(c^'0');
	for(i=0;i<n;i++)
	{
		for(c=gc();c!='0'&&c!='1';c=gc());
		for(a[i]=c^'0',m=1,c=gc();c=='0'||c=='1';c=gc(),m++)a[i]=(a[i]<<1)^c^'0';
	}
	if(n==1)
	{
		printf("%d\n",m);
		return 0;
	}
	for(i=1;i<=m;i++)for(j=0;j<1<<i;j++)f[i][j]=m;
	for(s=m,i=1;i<n;i++)
	{
		for(j=m;j;j--)if((a[i-1]&((1<<j)-1))==(a[i]>>m-j))break;
		s+=m-j;
		for(k=0,l=oo;k<=m;k++)l=min(l,f[k][a[i]>>m-k]+j-k);
		for(k=0;k<=m;k++)
		{
			j=a[i-1]&((1<<k)-1);
			f[k][j]=min(f[k][j],l);
		}
	}
	for(i=1;i<=m;i++)for(j=0;j<1<<i;j++)ans=min(ans,f[i][j]+s);
	printf("%d\n",ans);
	return 0;
}