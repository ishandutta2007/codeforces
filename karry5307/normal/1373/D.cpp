#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll test,n,sum,res,rres;
ll x[MAXN];
vector<ll>v;
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
	n=read(),res=rres=0;
	for(register int i=1;i<=n;i++)
	{
		x[i]=read(),res+=(i&1?x[i]:0);
	}
	v.clear(),sum=0;
	for(register int i=2;i<=n;i+=2)
	{
		v.push_back(x[i]-x[i-1]);
	}
	for(register int i=0;i<v.size();i++)
	{
		sum=max(sum+v[i],0ll),rres=max(rres,sum);
	}
	v.clear(),sum=0;
	for(register int i=3;i<=n;i+=2)
	{
		v.push_back(x[i-1]-x[i]);
	}
	for(register int i=0;i<v.size();i++)
	{
		sum=max(sum+v[i],0ll),rres=max(rres,sum);
	}
	printf("%lld\n",res+rres);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}