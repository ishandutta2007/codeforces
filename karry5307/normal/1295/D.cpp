#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=1;
ll test,x,y,res;
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
inline void solve()
{
	x=read(),y=read(),y/=__gcd(x,y),res=y;
	for(register int i=2;i<=sqrt(y);i++)
	{
		if(y%i==0)
		{
			res=res/i*(i-1);
			while(y%i==0)
			{
				y/=i;
			}
		}
	}
	if(y-1)
	{
		res=res/y*(y-1);
	}
	printf("%lld\n",res);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}