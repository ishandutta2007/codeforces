#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll n,kk,r,res;
ll f[MAXN];
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
inline void upd(ll v,ll w)
{
	for(register int i=kk;i>=v;i--)
	{
		f[i]=max(f[i],f[i-v]+w);
	}
}
inline void calc(ll l,ll r)
{
	if(l==r)
	{
		for(register int i=0;i<v[l].size();i++)
		{
			res=max(res,f[kk-i-1]+v[l][i]);
			if(kk==i+1)
			{
				break;
			}
		}
		return;
	}
	ll mid=(l+r)>>1;
	vector<ll>g(kk+1);
	copy(f,f+kk+1,g.begin());
	for(register int i=mid+1;i<=r;i++)
	{
		upd(v[i].size(),v[i].back());
	}
	calc(l,mid),copy(g.begin(),g.end(),f);
	for(register int i=l;i<=mid;i++)
	{
		upd(v[i].size(),v[i].back());
	}
	calc(mid+1,r),copy(g.begin(),g.end(),f);
}
int main()
{
    n=read(),kk=read();
    for(register int i=1;i<=n;i++)
    {
    	v[i].resize(r=read()),v[i][0]=read();
    	for(register int j=1;j<r;j++)
    	{
    		v[i][j]=read()+v[i][j-1];
		}
	}
	calc(1,n),printf("%lld\n",res);
}