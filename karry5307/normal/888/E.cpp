#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
vector<ll>v1,v2;
ll n,m,res,ptrr;
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
inline void dfs(ll cur,ll ed,ll sm,vector<ll>&v)
{
	if(cur==ed+1)
	{
		return v.push_back(sm);
	}
	dfs(cur+1,ed,sm,v),dfs(cur+1,ed,(sm+x[cur])%m,v);
}
int main()
{
	n=read(),m=read();
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	dfs(1,n/2,0,v1),dfs(n/2+1,n,0,v2),ptrr=v2.size()-1;
	sort(v1.begin(),v1.end()),sort(v2.begin(),v2.end());
	for(register int i:v1)
	{
		while(v2[ptrr]+i>=m)
		{
			ptrr--;
		}
		res=max(res,v2[ptrr]+i);
	}
	printf("%d\n",max(res,(v1.back()+v2.back())%m));
}