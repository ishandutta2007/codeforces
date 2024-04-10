#include<bits/stdc++.h>
using namespace std;
#define MAXN 600005
const char D[]="ACGT";
char c[MAXN],*s[MAXN];
int n,m,d[300],a[2][MAXN][4],b[MAXN][2][4],P[2][2],p[4],ans[4],A,N,i,j,k;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		s[i]=c+i*(m+1);
		scanf("%s",s[i]);
	}
	d['A']=0;
	d['C']=1;
	d['G']=2;
	d['T']=3;
	for(i=0;i<n;i++)for(j=0;j<m;j++)for(k=0;k<4;k++)if(k!=d[s[i][j]])
	{
		a[i&1][j][k]++;
		b[i][j&1][k]++;
	}
	for(i=0;i<4;i++)p[i]=i;
	N=n*m+1;
	do
	{
		for(i=0;i<2;i++)for(j=0;j<2;j++)P[i][j]=p[i<<1|j];
		for(j=k=0;j<m;j++)k+=min(a[0][j][P[0][j&1]]+a[1][j][P[1][j&1]],a[1][j][P[0][j&1]]+a[0][j][P[1][j&1]]);
		if(k<N)
		{
			N=k;
			A=0;
			for(i=0;i<4;i++)ans[i]=p[i];
		}
		for(i=k=0;i<n;i++)k+=min(b[i][0][P[i&1][0]]+b[i][1][P[i&1][1]],b[i][1][P[i&1][0]]+b[i][0][P[i&1][1]]);
		if(k<N)
		{
			N=k;
			A=1;
			for(i=0;i<4;i++)ans[i]=p[i];
		}
	}while(next_permutation(p,p+4));
	for(i=0;i<2;i++)for(j=0;j<2;j++)P[i][j]=ans[i<<1|j];
	if(!A)
	{
		for(j=0;j<m;j++)if(a[0][j][P[0][j&1]]+a[1][j][P[1][j&1]]<a[1][j][P[0][j&1]]+a[0][j][P[1][j&1]])
		{
			s[0][j]=D[P[0][j&1]];
			s[1][j]=D[P[1][j&1]];
		}
		else
		{
			s[0][j]=D[P[1][j&1]];
			s[1][j]=D[P[0][j&1]];
		}
		for(i=2;i<n;i++)for(j=0;j<m;j++)s[i][j]=s[i&1][j];
	}
	else
	{
		for(i=0;i<n;i++)if(b[i][0][P[i&1][0]]+b[i][1][P[i&1][1]]<b[i][1][P[i&1][0]]+b[i][0][P[i&1][1]])
		{
			s[i][0]=D[P[i&1][0]];
			s[i][1]=D[P[i&1][1]];
		}
		else
		{
			s[i][0]=D[P[i&1][1]];
			s[i][1]=D[P[i&1][0]];
		}
		for(i=0;i<n;i++)for(j=2;j<m;j++)s[i][j]=s[i][j&1];
	}
	for(i=0;i<n;i++)puts(s[i]);
	return 0;
}