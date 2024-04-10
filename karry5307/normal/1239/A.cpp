#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51,MOD=1e9+7;
ll x,y;
ll fib[MAXN];
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
inline void setup(ll cnt)
{
	fib[0]=fib[1]=1;
	for(register int i=2;i<=cnt;i++)
	{
		fib[i]=(fib[i-1]+fib[i-2])%MOD;
	}
}
int main()
{
	x=read(),y=read(),setup(max(x,y));
	printf("%d\n",(li)(fib[x]+fib[y]-1)%MOD*2%MOD);
}