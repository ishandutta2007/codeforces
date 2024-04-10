#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e7+51;
vector<ll>np(MAXN,0),prime;
mt19937 mt(19260817);
ll n,m,r,rr;
string x,y;
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
inline ll qpow(ll base,ll exponent,ll md)
{
    li res=1;
    while(exponent)
    {
        if(exponent&1)
        {
            res=1ll*res*base%md;
        }
        base=1ll*base*base%md,exponent>>=1;
    }
    return res;
}
inline void sieve(ll limit)
{
	for(register int i=2;i<=limit;i++)
	{
		if(!np[i])
		{
			prime.push_back(i);
		}
		for(register int p:prime)
		{
			if(i*p>=limit)
			{
				break;
			}
			np[i*p]=1;
			if(i%p==0)
			{
				break;
			}
		}
	}
}
int main()
{
	n=read(),m=read(),cin>>x>>y,sieve(10000000);
	for(register int p:prime)
	{
		vector<ll>p0(p);
		for(register int i=0;i<p;i++)
		{
			for(register int j=i;j<n;j+=p)
			{
				p0[i]+=x[j]-y[j];
			}
		}
		for(register int d=(m+p-2)/p*p+1;d<=10000000;d+=p)
		{
			if((mt()&32767)==0)
			{
				break;
			}
			if(np[d])
			{
				continue;
			}
			r=mt()%(d-1)+1;
			while(qpow(r,(d-1)/p,d)==1)
			{
				r=mt()%(d-1)+1;
			}
			r=qpow(r,(d-1)/p,d);
			for(register int i=0,j=1;i<p;i++,j=(li)j*r%d)
			{
				if(j>=2&&j<=d-2)
				{
					rr=0;
					for(register int k=0,l=1;k<p;k++,l=(li)l*j%d)
					{
						rr=(rr+(li)l*p0[k]%d)%d;
					}
					if(!rr)
					{
						return printf("%d %d\n",d,j),0;
					}
				}
			}
		}
	}
}