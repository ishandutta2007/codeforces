#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=1;
ll test,res,p,q,r;
ll x[4];
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
inline ll Abs(ll x,ll y)
{
	return x>y?x-y:y-x;
}
inline void solve()
{
	x[0]=read(),x[1]=read(),x[2]=read(),res=1e18;
	for(register int i=-1;i<=1;i++)
	{
		for(register int j=-1;j<=1;j++)
		{
			for(register int k=-1;k<=1;k++)
			{
				p=x[0]+i,q=x[1]+j,r=x[2]+k;
				res=min(res,Abs(p,q)+Abs(p,r)+Abs(q,r));
			}
		}
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