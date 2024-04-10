/**************************************************************
	File name: 1149B.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 2019/4/29 10:50:59
**************************************************************/
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
const int N=200010,M=300,C=30;
int f[M][M][M],n,q,nex[N][C],lb,lc,ld,g[C];
char a[N],b[N],c[N],d[N],opt[N];
int main()
{
	n=read();
	q=read();
	scanf("%s",a+1);
	fr(i,1,n)
		a[i]-='a';
	fr(i,0,25)
		nex[n+1][i]=g[i]=n+1;
	fd(i,n,0)
	{
		fr(j,0,25)
			nex[i][j]=g[j];
		g[a[i]]=i;
	}
/*	fr(i,0,n)
		fr(j,0,25)
			printf("%d%c",nex[i][j],j==25?'\n':' ');*/
	while(q--)
	{
		scanf("%s",opt);
		if(*opt=='+')
		{
			int k=read();
			scanf("%s",opt);
			*opt-='a';
			if(k==1)
			{
				b[++lb]=*opt;
				fr(i,0,lc)
					fr(j,0,ld)
					{
						f[lb][i][j]=nex[f[lb-1][i][j]][b[lb]];
						if(i)
							f[lb][i][j]=min(f[lb][i][j],nex[f[lb][i-1][j]][c[i]]);
						if(j)
							f[lb][i][j]=min(f[lb][i][j],nex[f[lb][i][j-1]][d[j]]);
/*						if(f[lb][i][j]==0)
						{
							printf("- %d %d %d %d %d\n",lb,i,j,f[lb][i][j-1],d[j]);
							return 0;
						}*/
					}
			}
			else if(k==2)
			{
				c[++lc]=*opt;
				fr(i,0,lb)
					fr(j,0,ld)
					{
						f[i][lc][j]=nex[f[i][lc-1][j]][c[lc]];
						if(i)
							f[i][lc][j]=min(f[i][lc][j],nex[f[i-1][lc][j]][b[i]]);
						if(j)
							f[i][lc][j]=min(f[i][lc][j],nex[f[i][lc][j-1]][d[j]]);
/*						if(f[i][lc][j]==0)
						{
							printf("+ %d %d %d\n",i,lc,j);
							return 0;
						}*/
					}
			}
			else
			{
				d[++ld]=*opt;
				fr(i,0,lb)
					fr(j,0,lc)
					{
						f[i][j][ld]=nex[f[i][j][ld-1]][d[ld]];
						if(i)
							f[i][j][ld]=min(f[i][j][ld],nex[f[i-1][j][ld]][b[i]]);
						if(j)
							f[i][j][ld]=min(f[i][j][ld],nex[f[i][j-1][ld]][c[j]]);
/*						if(f[i][j][ld]==0)
						{
							printf("* %d %d %d\n",i,j,ld);
							return 0;
						}*/
					}
			}
		}
		else
		{
			int k=read();
			if(k==1)
				lb--;
			else if(k==2)
				lc--;
			else
				ld--;
		}
/*		fr(i,1,lb)
			printf("%d%c",b[i],i==lb?'\n':' ');
		fr(i,1,lc)
			printf("%d%c",c[i],i==lc?'\n':' ');
		fr(i,1,ld)
			printf("%d%c",d[i],i==ld?'\n':' ');
		fr(i,0,lb)
			fr(j,0,lc)
				fr(k,0,ld)
					printf("%d %d %d %d\n",i,j,k,f[i][j][k]);*/
		if(f[lb][lc][ld]<=n)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}