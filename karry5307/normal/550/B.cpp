#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,l,r,x,res;
ll c[MAXN];
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
inline void dfs(ll cur,ll sm,ll mn,ll mx)
{
	if(cur==n+1)
	{
		return (void)(res+=(l<=sm&&sm<=r&&mx-mn>=x));
	}
	dfs(cur+1,sm,mn,mx),dfs(cur+1,sm+c[cur],min(mn,c[cur]),max(mx,c[cur]));
}
int main()
{
	n=read(),l=read(),r=read(),x=read();
	for(register int i=1;i<=n;i++)
	{
		c[i]=read();
	}
	dfs(1,0,2e9,0),printf("%d\n",res);
}