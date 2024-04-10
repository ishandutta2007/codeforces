#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n;
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
inline void calc(ll n,ll m)
{
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=m;j++)
		{
			putchar("aeiou"[(i+j)%5]);
		}
	}
}
int main()
{
	if((n=read())<25)
	{
		return puts("-1"),0;
	}
	for(register int i=5;i<=sqrt(n);i++)
	{
		if(n%i==0&&n/i>=5)
		{
			return calc(i,n/i),0;
		}
	}
	puts("-1");
}