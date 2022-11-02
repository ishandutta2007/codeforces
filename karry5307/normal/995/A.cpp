#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=251;
struct Item{
	ll c,x,y;
};
vector<Item>s;
ll n,m,cx,cy;
ll g[5][MAXN],prvx[5][MAXN],prvy[5][MAXN],nxtx[5][MAXN],nxty[5][MAXN];
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        neg=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
}
inline void move()
{
	for(register int i=1;i<=n;i++)
	{
		g[1][i]==g[2][i]&&g[1][i]?s.push_back((Item){g[1][i],1,i}),g[2][i]=0:1;
		g[3][i]==g[4][i]&&g[3][i]?s.push_back((Item){g[4][i],4,i}),g[3][i]=0:1;
	}
}
inline void rotate()
{
	ll tx=cx,ty=cy,u,v;
	ll px=prvx[tx][ty],py=prvy[tx][ty];
	for(register int i=px,j=py;i!=tx||j!=ty;i=u,j=v)
	{
		if(g[i][j])
		{
			s.push_back((Item){g[i][j],nxtx[i][j],nxty[i][j]});
			swap(g[i][j],g[nxtx[i][j]][nxty[i][j]]);
		}
		u=prvx[i][j],v=prvy[i][j];
	}
	cx=nxtx[tx][ty],cy=nxty[tx][ty];
}
int main()
{
	n=read(),m=read();
	for(register int i=1;i<=4;i++)
	{
		for(register int j=1;j<=n;j++)
		{
			g[i][j]=read();
		}
	}
	for(register int i=1;i<=n;i++)
	{
		prvx[2][i]=2+(i==1),prvy[2][i]=i==1?1:i-1;
		nxtx[2][i]=2+(i==n),nxty[2][i]=i==n?n:i+1;
		prvx[3][i]=3-(i==n),prvy[3][i]=i==n?n:i+1;
		nxtx[3][i]=3-(i==1),nxty[3][i]=i==1?1:i-1;
	}
	move();
	for(register int i=1;i<=n;i++)
	{
		g[2][i]==0?cx=2,cy=i:1,g[3][i]==0?cx=3,cy=i:0;
	}
	if(!cx)
	{
		return puts("-1"),0;
	}
	for(register int i=1;i<=2*n;i++)
	{
		rotate(),move();
	}
	printf("%d\n",s.size());
	for(register Item i:s)
	{
		printf("%d %d %d\n",i.c,i.x,i.y);
	}
}