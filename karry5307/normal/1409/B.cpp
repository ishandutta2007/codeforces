#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll test,u,v,x,y,n,du,dv,res;
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
	u=read(),v=read(),x=read(),y=read(),n=read(),res=1e18;
	du=min(n,u-x),dv=min(n-du,v-y),res=min(res,(u-du)*(v-dv));
	du=min(n,v-y),dv=min(n-du,u-x),res=min(res,(v-du)*(u-dv));
	printf("%lld\n",res);
}
int main()
{
	test=read();
	for(register int i=1;i<=test;i++)
	{
		solve();
	}
}