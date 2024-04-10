#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e6+51;
vector<ll>res;
ll n,sm;
ll x[MAXN],r[MAXN],vis[MAXN];
vector<ll>v[MAXN];
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
inline void dfs(ll x,ll d)
{
	vis[x]=1,!d?res.push_back(x):(void)1;
	ll nxt=vis[r[x]]?x>n?x-n:x+n:r[x];
	!vis[nxt]?dfs(nxt,d^1):(void)1;
}
int main()
{
	n=read();
	if(!(n&1))
	{
		cout<<"First"<<endl;
		for(register int i=1;i<=2*n;i++)
		{
			cout<<(i-1)%n+1<<" ";
		}
		return cout<<endl,0;
	}
	cout<<"Second"<<endl,n;
	for(register int i=1;i<=n*2;i++)
	{
		x[i]=read(),v[x[i]].push_back(i);	
	}
	for(register int i=1;i<=n;i++)
	{
		r[v[i][0]]=v[i][1],r[v[i][1]]=v[i][0];
	}
	for(register int i=1;i<=n;i++)
	{
		!vis[i]?dfs(i,0):(void)1;
	}
	for(register int i:res)
	{
		sm=(sm+i)%(n*2);
	}
	for(register int i:res)
	{
		cout<<(sm?r[i]:i)<<" ";
	}
	cout<<endl;
}