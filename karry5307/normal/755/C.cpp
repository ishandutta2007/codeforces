#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=2e5+51;
ll n,res;
ll d[MAXN],vis[MAXN];
vector<ll>rd[MAXN];
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
inline void calc(ll x)
{
	ll u=d[x],v=d[u];
	for(register int i:rd[u])
	{
		vis[i]=1;
	}
	for(register int i:rd[v])
	{
		vis[i]=1;
	}
}
int main()
{
	n=read();
	for(register int i=1;i<=n;i++)
	{
		rd[d[i]=read()].push_back(i);
	}
	for(register int i=1;i<=n;i++)
	{
		!vis[i]?calc(i),res++:1;
	}
	cout<<res<<endl;
}