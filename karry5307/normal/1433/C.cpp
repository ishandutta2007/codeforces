#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=6e5+51;
ll test,n,res,mx;
ll x[MAXN];
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
	n=read(),res=mx=-1;
	for(register int i=1;i<=n;i++)
	{
		mx=max(mx,x[i]=read());
	}
	x[0]=x[n+1]=mx;
	for(register int i=1;i<=n;i++)
	{
		x[i]==mx&&(x[i-1]!=mx||x[i+1]!=mx)?res=i:1;
	}
	printf("%d\n",res);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}