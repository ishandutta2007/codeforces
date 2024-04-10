/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2019-10-26 19:35:53
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
const int N=2010,mod=1000000007;
int n,m;
char s[N][N];
int d[N][N],r[N][N],D[N][N],R[N][N],sd[N][N],sr[N][N];
int main()
{
	n=read();
	m=read();
	fr(i,1,n)
		scanf("%s",s[i]+1);
	if(s[1][1]!='.')
	{
		printf("0\n");
		return 0;
	}
	if(n==1&&m==1)
	{
		printf("1\n");
		return 0;
	}
	fd(i,n,1)
		fd(j,m,1)
		{
			D[i][j]=(s[i+1][j]=='.')+D[i+1][j];
			R[i][j]=(s[i][j+1]=='.')+R[i][j+1];
		}
	fd(i,n,1)
		if(s[i][m]=='.'&&i+D[i][m]==n)
			d[i][m]=sd[i][m]=1;
	fd(i,m,1)
		if(s[n][i]=='.'&&i+R[n][i]==m)
			r[n][i]=sr[n][i]=1;
	fd(i,n-1,1)
		fd(j,m-1,1)
		{
			d[i][j]=(sr[i+1][j]-sr[i+D[i][j]+1][j]+mod)%mod;
			r[i][j]=(sd[i][j+1]-sd[i][j+R[i][j]+1]+mod)%mod;
			sd[i][j]=(sd[i][j+1]+d[i][j])%mod;
			sr[i][j]=(sr[i+1][j]+r[i][j])%mod;
		}
	printf("%d\n",(d[1][1]+r[1][1])%mod);
	return 0;
}