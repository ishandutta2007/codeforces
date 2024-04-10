#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
mt19937 mt(20050103);
ll n;
li rx,ry,lx,ly;
ll x[MAXN],y[MAXN],c[MAXN];
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
int main()
{
	n=read();
	for(register int i=1;i<=n;i++)
	{
		x[i]=read(),y[i]=read();
	}
	for(register int i=1;i<=600;i++)
	{
		rx=ry=lx=ly=0;
		for(register int j=1;j<=n;j++)
		{
			c[j]=mt()%2?1:-1,c[j]==1?rx+=x[j],ry+=y[j]:(rx-=x[j],ry-=y[j]);
			if(sqrt(rx*rx+ry*ry)>=1500000)
			{
				c[j]=-c[j],rx=lx,ry=ly;
				c[j]==1?rx+=x[j],ry+=y[j]:(rx-=x[j],ry-=y[j]);
			}
			lx=rx,ly=ry;
		}
		if(sqrt(rx*rx+ry*ry)<1500000)
		{
			for(register int j=1;j<=n;j++)
			{
				printf("%d ",c[j]);
			}
			return 0;
		}
	}
}