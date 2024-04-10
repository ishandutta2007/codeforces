#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll test,n;
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
	return x<5?max(1ll,x-1):(x%2==1)||(x%4==0)?x-calc(x-1):x-calc(x/2);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		printf("%lld\n",calc(read()));
	}	
}