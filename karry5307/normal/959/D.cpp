#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
set<ll>st;
ll n,limit=2e6,flg;
ll x[MAXN],r[MAXN];
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
inline void sieve(ll x)
{
	for(register int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)
		{
			for(register int j=1;j<=limit/i;j++)
			{
				st.find(i*j)!=st.end()?st.erase(i*j),1:1;
			}
			while(x%i==0)
			{
				x/=i;
			}
		}
	}
	if(x!=1)
	{
		for(register int i=1;i<=limit/x;i++)
		{
			st.find(i*x)!=st.end()?st.erase(i*x),1:1;
		}
	}
}
int main()
{
	n=read();
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	for(register int i=2;i<=limit;i++)
	{
		st.insert(i);
	}
	for(register int i=1;i<=n;i++)
	{
		r[i]=flg?*st.begin():*(st.lower_bound(x[i]));
		r[i]>x[i]?flg=1:1,sieve(r[i]),printf("%d ",r[i]);
	}
}