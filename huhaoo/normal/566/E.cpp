/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-03-05 20:50:08
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
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
#include<bitset>
const int N=1010;
std::bitset<N> b[N],e[N],a[N];
int n,d[N],cnt,p[N];
int check1()
{
	fr(i,1,n) if(d[i]!=n) return 0;
	return 1;
}
int cmp(int u,int v){ return d[u]<d[v]; }
int main()
{
	n=read();
	fr(i,1,n)
	{
		int c=read();
		fr(j,1,c){ int v=read(); d[v]++; b[i][v]=1; }
	}
	if(check1()) fr(i,2,n) printf("%d %d\n",1,i);
	else
	{
		fr(i,1,n) fr(j,i+1,n)
		{
			std::bitset<N> B=b[i]&b[j];
			if(B.count()==2)
			{
				int i=B._Find_first(),j=B._Find_next(i);
				if(!e[i][j])
				{
					e[i][j]=e[j][i]=1;
					printf("%d %d\n",i,j);
				}
			}
		}
		fr(i,1,n) if(e[i].count()){ e[i][i]=1; p[i]=1; cnt++; }
		if(cnt==2)
		{
			int u=0,v=0;
			fr(i,1,n) if(p[i]) (u?v:u)=i;
			fr(i,1,n) if(int(b[i].count())!=n)
			{
				fr(k,1,n) if(!p[k]) printf("%d %d\n",k,b[i][k]?u:v);
				return 0;
			}
		}
		fr(i,1,n) if(!p[i])
		{
			int x=0,y=n;
			fr(j,1,n) if(b[j][i]&&int(b[j].count())<y){ y=b[j].count(); x=j; }
			fr(j,1,n) if(p[j]&&b[x][j]) a[i][j]=1;
		}
		fr(i,1,n) if(!p[i]) fr(j,1,n) if(p[j]&&e[j]==a[i]) printf("%d %d\n",i,j);
	}
	return 0;
}