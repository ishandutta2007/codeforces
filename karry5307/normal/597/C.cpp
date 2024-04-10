#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
struct BIT{
	ll sz;
	ll num[MAXN];
	inline void add(ll pos,ll val)
	{
		for(;pos<=sz;pos+=pos&-pos)
		{
			num[pos]+=val;
		}
	}
	inline ll query(ll pos)
	{
		ll res=0;
		for(;pos;pos-=pos&-pos)
		{
			res+=num[pos];
		}
		return res;
	}
};
BIT bit[15];
ll n,kk,res;
ll x[MAXN],f[MAXN][15];
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
int main()
{
	n=read(),kk=read()+1;
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	for(register int i=1;i<=10;i++)
	{
		bit[i].sz=n;
	}
	for(register int i=1;i<=n;i++)
	{
		f[i][1]=1,bit[1].add(x[i],1);
		for(register int j=2;j<=kk;j++)
		{
			f[i][j]=bit[j-1].query(x[i]-1),bit[j].add(x[i],f[i][j]);
		}
	}
	for(register int i=1;i<=n;i++)
	{
		res+=f[i][kk];
	}
	printf("%lld\n",res);
}