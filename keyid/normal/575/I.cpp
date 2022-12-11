#include <bits/stdc++.h>
using namespace std;

const int MAXN=5005,MAXQ=100005;

struct query
{
	int ty,dir,x,y,len;
}qu[MAXQ];

int n,_2n,f[MAXN*2],g[2][MAXN][MAXN*2];

void add1(int C[],int l,int r)
{
	for (;l<=_2n;l+=l&-l)
		C[l]++;
	for (r++;r<=_2n;r+=r&-r)
		C[r]--;
}

void add3(int C[][MAXN*2],int x,int l2,int r2,int d)
{
	for (;x<=n;x+=x&-x)
	{
		for (int i=l2;i<=_2n;i+=i&-i)
			C[x][i]+=d;
		for (int i=r2+1;i<=_2n;i+=i&-i)
			C[x][i]-=d;
	}
}

void add2(int C[][MAXN*2],int l1,int r1,int l2,int r2)
{
	add3(C,l1,l2,r2,1);
	add3(C,r1+1,l2,r2,-1);
}

int sum1(int C[],int x)
{
	int ret=0;
	for (;x;x-=x&-x)
		ret+=C[x];
	return ret;
}

int sum2(int C[][MAXN*2],int x,int y)
{
	int ret=0;
	for (int i=x;i;i-=i&-i)
		for (int j=y;j;j-=j&-j)
			ret+=C[i][j];
	return ret;
}

int main()
{
	int q;
	scanf("%d%d",&n,&q);
	_2n=n*2;
	for (int i=0;i<q;i++)
	{
		scanf("%d",&qu[i].ty);
		if (qu[i].ty==1)
			scanf("%d%d%d%d",&qu[i].dir,&qu[i].x,&qu[i].y,&qu[i].len);
		else
			scanf("%d%d",&qu[i].x,&qu[i].y);
	}
	for (int i=0;i<q;i++)
		if (qu[i].ty==1)
		{
			int x=qu[i].x,y=qu[i].y,len=qu[i].len;
			if (qu[i].dir==1)
			{
				add1(f,x+y,x+y+len);
				add2(g[0],1,x-1,x+y,x+y+len);
				add2(g[1],1,y-1,x+y,x+y+len);
			}
			else if (qu[i].dir==4)
			{
				add1(f,x-len+y,x+y);
				add2(g[0],x+1,n,x-len+y,x+y);
				add2(g[1],y+1,n,x-len+y,x+y);
			}
		}
		else
		{
			int x=qu[i].x,y=qu[i].y;
			qu[i].len=sum1(f,x+y)-sum2(g[0],x,x+y)-sum2(g[1],y,x+y);
		}
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	for (int i=0;i<q;i++)
		if (qu[i].ty==1)
		{
			int x=qu[i].x,y=qu[i].y,len=qu[i].len;
			if (qu[i].dir==2)
			{
				add1(f,y-len-x+n,y-x+n);
				add2(g[0],1,x-1,y-len-x+n,y-x+n);
				add2(g[1],y+1,n,y-len-x+n,y-x+n);
			}
			else if (qu[i].dir==3)
			{
				add1(f,y-x+n,y+len-x+n);
				add2(g[0],x+1,n,y-x+n,y+len-x+n);
				add2(g[1],1,y-1,y-x+n,y+len-x+n);
			}
		}
		else
		{
			int x=qu[i].x,y=qu[i].y;
			qu[i].len+=sum1(f,y-x+n)-sum2(g[0],x,y-x+n)-sum2(g[1],y,y-x+n);
		}
	for (int i=0;i<q;i++)
		if (qu[i].ty==2)
			printf("%d\n",qu[i].len);
	return 0;
}