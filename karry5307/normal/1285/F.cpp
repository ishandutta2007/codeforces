#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,ptot,mx,tp,s,el;
li res;
ll prime[MAXN],np[MAXN],mu[MAXN],x[MAXN],vis[MAXN];
ll st[MAXN],cnt[MAXN];
vector<ll>v,dv[MAXN];
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
inline void sieve(ll limit)
{
    mu[1]=1;
    for(register int i=2;i<=limit;i++)
    {
	if(!np[i])
	{
	    prime[++ptot]=i,mu[i]=-1;
	}
	for(register int j=1;j<=ptot&&i*prime[j]<=limit;j++)
	{
	    np[i*prime[j]]=1;
	    if(!(i%prime[j]))
	    {
		break;
	    }
	    mu[i*prime[j]]=-mu[i];
	}
    }
    for(register int i=1;i<=limit;i++)
    {
	for(register int j=i;j<=limit;j+=i)
	{
	    dv[j].push_back(i);
	}
    }
}
int main()
{
    sieve(1e5),n=read();
    for(register int i=1;i<=n;i++)
    {
	mx=max(mx,x[i]=read()),vis[x[i]]++;
    }
    for(register int d=1;d<=mx;d++)
    {
	v.clear();
	for(register int i=d;i<=mx;i+=d)
	{
	    for(register int j=1;j<=vis[i];j++)
	    {
		v.push_back(i/d);
	    }
	}
	sort(v.begin(),v.end(),greater<ll>());
	for(register int i:v)
	{
	    s=0;
	    for(register int j:dv[i])
	    {
		s+=mu[j]*cnt[j];
	    }
	    while(s)
	    {
		el=st[tp--];
		if(__gcd(i,el)==1)
		{
		    res=max(res,(li)d*i*el),s--;
		}
		for(register int j:dv[el])
		{
		    cnt[j]--;
		}
	    }
	    st[++tp]=i;
	    for(register int j:dv[i])
	    {
		cnt[j]++;
	    }
	}
	while(tp)
	{
	    el=st[tp--];
	    for(register int i:dv[el])
	    {
		cnt[i]--;
	    }
	}
    }
    printf("%lld\n",res);
}