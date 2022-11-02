#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,d,c;
ll x[MAXN];
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
		x[i]=read(),d=__gcd(d,x[i]),c+=(x[i]==1);
	}
	if(d!=1)
	{
		return puts("-1"),0;
	}
	if(c)
	{
		return printf("%d\n",n-c),0;
	}
	c=0x3f3f3f3f;
	for(register int i=1;i<=n;i++)
	{
		d=x[i];
		for(register int j=i+1;j<=n;j++)
		{
			d=__gcd(d,x[j]),d==1?c=min(c,j-i+1):1;
		}
	}
	printf("%d\n",n+c-2);
}