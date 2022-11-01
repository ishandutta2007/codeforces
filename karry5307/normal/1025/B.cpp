#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll n,x,y,cur;
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
inline ll calc(ll x)
{
	for(register int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)
		{
			return i;
		}
	}
	return x;
}
int main()
{
	n=read(),x=read(),y=read(),cur=x*y/__gcd(x,y);
	for(register int i=2;i<=n;i++)
	{
		x=read(),y=read(),cur=__gcd(cur,x*y/__gcd(x,y));
	}
	printf("%lld\n",cur==1?-1:calc(__gcd(cur,__gcd(cur,x)>1?x:y)));
}