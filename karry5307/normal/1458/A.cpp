#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=1e6+51;
ll n,m,xgzc;
ll x[MAXN],y[MAXN];
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
	n=read(),m=read();
	for(register int i=1;i<=n;i++)
	{
		x[i]=read(),i>=2?xgzc=__gcd(xgzc,abs(x[i]-x[i-1])):1;
	}
	for(register int i=1;i<=m;i++)
	{
		y[i]=read(),printf("%lld ",__gcd(xgzc,x[1]+y[i]));
	}
}