#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n;
ll x[MAXN],d[MAXN],ffa[MAXN];
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
	return x==ffa[x]?x:ffa[x]=find(ffa[x]);
}
inline void merge(ll x,ll y)
{
	ll fx=find(x),fy=find(y);
	return (void)(fx!=fy?ffa[fy]=fx:1);
}
int main()
{
	n=read();
	for(register int i=1;i<=n;i++)
	{
		x[i]=read(),ffa[i]=i;	
	}	
	for(register int i=1;i<=n;i++)
	{
		d[i]=read();
		i-d[i]>=1?merge(i,i-d[i]):(void)1,i+d[i]<=n?merge(i,i+d[i]):(void)1;
	}
	for(register int i=1;i<=n;i++)
	{
		if(find(i)!=find(x[i]))
		{
			return puts("NO"),0;
		}
	}
	puts("YES");
}