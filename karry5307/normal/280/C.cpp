#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
typedef double db;
const ll MAXN=2e5+51;
ll n,u,v;
db res;
vector<ll>g[MAXN];
ll depth[MAXN];
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
inline void dfs(ll node,ll fa)
{
	res+=1.0/(depth[node]=depth[fa]+1);
	for(register int i:g[node])
	{
		i!=fa?dfs(i,node):(void)1;
	}
}
int main()
{
	n=read();
	for(register int i=0;i<n-1;i++)
	{
		u=read(),v=read(),g[u].push_back(v),g[v].push_back(u);
	}
	dfs(1,0),printf("%.9lf\n",res);
}