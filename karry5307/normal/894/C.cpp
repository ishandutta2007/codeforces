#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,d;
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
		x[i]=read(),d=__gcd(d,x[i]);	
	}	
	for(register int i=1;i<=n;i++)
	{
		x[i]/=d;
	}
	if(x[1]!=1)
	{
		return puts("-1"),0;
	}
	printf("%d\n",2*n);
	for(register int i=1;i<=n;i++)
	{
		printf("%d %d ",x[i]*d,d);
	}
}