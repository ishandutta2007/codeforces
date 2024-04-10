#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51,MOD=1e9+7;
ll nc,x,y,fx,fy,res=1;
ll ffa[MAXN],sz[MAXN],loop[MAXN],selfLoop[MAXN];
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
inline ll find(ll x)
{
	return ffa[x]==x?x:ffa[x]=find(ffa[x]);
}
int main()
{
	nc=read();
	for(register int i=1;i<=nc<<1;i++)
	{
		ffa[i]=i,sz[i]=1;
	}
	for(register int i=1;i<=nc;i++)
	{
		x=read(),y=read(),fx=find(x),fy=find(y);
		if(!(x^y))
		{
			selfLoop[fx]=1;
		}
		if(fx^fy)
		{
			ffa[fy]=fx,selfLoop[fx]|=selfLoop[fy],loop[fx]|=loop[fy],sz[fx]+=sz[fy];
			loop[fy]=0;
			continue;
		}
		loop[fx]=1;
	}
	for(register int i=1;i<=nc<<1;i++)
	{
		if((find(i)^i)||selfLoop[i])
		{
			continue;
		}
		if(loop[i]) 
		{
			res=(res<<1)%MOD;
			continue;
		}
		res=(li)res*sz[i]%MOD;
	}
	printf("%d\n",res);
}