#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
map<ll,ll>mp;
ll n,kk,MOD,res,u,v,w,x;
ll invf[MAXN],pr[MAXN];
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
inline void dfs(ll l,ll r,ll depth)
{
	if(depth>=kk||l==r)
	{
		return (void)mp[r-l+1]++;
	}
	ll mid=(l+r)>>1;
	dfs(l,mid,depth+1),dfs(mid+1,r,depth+1);
}
inline ll calc(ll x,ll y)
{
	ll res=0;
	for(register int i=1;i<=x;i++)
	{
		res=(res+(pr[i+y]-pr[i]+MOD)%MOD*2%MOD)%MOD;
	}
	return (((li)x*y-res)%MOD+MOD)%MOD;
}
int main()
{
	n=read(),kk=read(),MOD=read(),invf[1]=pr[1]=1,dfs(1,n,1);
	for(register int i=2;i<=max(n,2);i++)
	{
		invf[i]=MOD-(li)(MOD/i)*invf[MOD%i]%MOD,pr[i]=(pr[i-1]+invf[i])%MOD;
	}
	for(auto i:mp)
	{
		tie(u,v)=i,res=(res+(li)u*(u-1)/2%MOD*v)%MOD;
		v>=2?res=(res+(li)v*(v-1)/2%MOD*calc(u,u))%MOD:1;
	}
	for(auto i:mp)
	{
		for(auto j:mp)
		{
			if(i.first<j.first)
			{
				tie(u,v)=i,tie(w,x)=j;
				res=(res+(li)calc(u,w)*v%MOD*x%MOD)%MOD;
			}
		}
	}
	printf("%d\n",(li)res*invf[2]%MOD);
}