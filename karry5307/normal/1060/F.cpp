#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
typedef long double db;
const ll MAXN=51;
ll n,u,v;
db res,cur;
ll sz[MAXN];
db f[MAXN][MAXN],g[MAXN];
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
inline void dfs(ll node,ll fa)
{
	sz[node]=f[node][0]=1;
	for(register int i:vg[node])
	{
		if(i!=fa)
		{
			dfs(i,node),memset(g,0,sizeof(g));
			for(register int j=0;j<sz[node];j++)
			{
				for(register int k=0;k<sz[i];k++)
				{
					g[j+k]+=f[node][j]*f[i][k]*(0.5/(sz[i]-k)-1);
					g[j+k+1]+=f[node][j]*f[i][k];
				}
			}
			memcpy(f[node],g,sizeof(g)),sz[node]+=sz[i];
		}
	}
}
int main()
{
    n=read();
    for(register int i=0;i<n-1;i++)
    {
    	u=read(),v=read();
    	vg[u].push_back(v),vg[v].push_back(u);
	}
	for(register int i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f)),dfs(i,0),res=1;
		for(register int j:vg[i])
		{
			cur=0;
			for(register int k=0;k<sz[j];k++)
			{
				cur+=f[j][k]*0.5/(sz[j]-k);
			}
			res*=cur;
		}
		cout<<fixed<<setprecision(10)<<res<<endl;
	}
}