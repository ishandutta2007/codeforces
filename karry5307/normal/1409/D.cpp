#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
const ll MAXN=2e5+51;
ll test,n,s,res,cur;
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
	ll res=0;
	while(x)
	{
		res+=x%10,x/=10;
	}
	return res;
}
inline void solve()
{
	n=read(),s=read(),cur=1,res=0;
	while(calc(n)>s)
	{
		res+=cur*(10-n%10),n=(n+(10-n%10))/10,cur*=10;
	}
	printf("%llu\n",res);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}