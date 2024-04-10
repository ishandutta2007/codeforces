#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll n,op,x,kk,d;
ll rot[64];
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
inline void rotate(ll d,ll kk)
{
	while(d!=63)
	{
		rot[d]=(rot[d]+kk)&((1ll<<d)-1),d++,kk<<=1;
	}
}
inline void query(ll d,ll x)
{
	x=((x+rot[d])&((1ll<<d)-1))+(1ll<<d);
	while(d)
	{
		printf("%lld ",((x-rot[d])&((1ll<<d)-1))+(1ll<<d)),x>>=1,d--;
	}
	puts("1");
}
int main()
{
	n=read();
	for(register int i=1;i<=n;i++)
	{
		op=read(),x=read(),d=63-__builtin_clzll(x);
		if(op==1)
		{
			kk=(read()&((1ll<<d)-1)+(1ll<<d))&((1ll<<d)-1);
			rot[d]=(rot[d]+kk)&((1ll<<d)-1);
		}
		if(op==2)
		{
			kk=(read()&((1ll<<d)-1)+(1ll<<d))&((1ll<<d)-1),rotate(d,kk);
		}
		if(op==3)
		{
			query(d,x);
		}
	}
}