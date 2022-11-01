#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,u,v;
ll d[2];
vector<ll>vg[MAXN];
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
inline void dfs(ll node,ll fa,ll depth)
{
	d[depth]++;
	for(register int i:vg[node])
	{
		i!=fa?dfs(i,node,depth^1):(void)1;
	}
}
int main()
{
	n=read();
	for(register int i=1;i<=n-1;i++)
	{
		u=read(),v=read(),vg[u].push_back(v),vg[v].push_back(u);
	}
	dfs(1,0,1),printf("%d\n",min(d[0],d[1])-1);
}