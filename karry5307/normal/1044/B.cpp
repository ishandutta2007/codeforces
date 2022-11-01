#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,n,u,v,kk;
ll r[MAXN],r2[MAXN],depth[MAXN];
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
	depth[node]=depth[fa]+1;
	for(register int i:vg[node])
	{
		i!=fa?dfs(i,node):(void)1;
	}
}
inline void solve()
{
	n=read();
	for(register int i=1;i<=n;i++)
	{
		vg[i].clear(),r[i]=r2[i]=0;
	}
	for(register int i=1;i<=n-1;i++)
	{
		u=read(),v=read(),vg[u].push_back(v),vg[v].push_back(u);
	}
	kk=read();
	for(register int i=1;i<=kk;i++)
	{
		r[read()]=1;
	}
	kk=read(),r2[u=read()]=1;
	for(register int i=2;i<=kk;i++)
	{
		r2[read()]=1;
	}
	cout<<"B "<<u<<endl,depth[0]=0,dfs(read(),0),depth[v=0]=1e9;
	for(register int i=1;i<=n;i++)
	{
		depth[i]<depth[v]&&r[i]?v=i:1;
	}
	cout<<"A "<<v<<endl,cout<<"C "<<(r2[read()]?v:-1)<<endl;
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}