#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51,inf=1e15;
multiset<ll>st,gap;
multiset<ll>::iterator it;
ll n,qcnt,op,u,prv,nxt,mx,mn;
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
inline void erase(ll x)
{
	gap.erase(gap.find(x));
}
inline ll query()
{
	if(*gap.begin()>=1e12)
	{
		return 0;
	}
	it=st.begin(),mn=*(++it),it=st.end(),--it,mx=*(--it);
	return it=gap.end(),--it,--it,mx-mn-*(--it);
}
int main()
{
	n=read(),qcnt=read(),st.insert(inf),st.insert(-inf);
	for(register int i=1;i<=n;i++)
	{
		st.insert(x[i]=read());
	}
	sort(x+1,x+n+1),x[0]=-inf,x[n+1]=inf;
	for(register int i=1;i<=n+1;i++)
	{
		gap.insert(x[i]-x[i-1]);
	}
	printf("%lld\n",query());
	for(register int i=0;i<qcnt;i++)
	{
		op=read(),u=read();
		if(op==0)
		{
			it=st.find(u),prv=u-*(--it),it++,nxt=*(++it)-u;
			st.erase(u),erase(prv),erase(nxt),gap.insert(nxt+prv);
		}
		if(op==1)
		{
			it=st.upper_bound(u),nxt=*(it--),prv=*it,st.insert(u);
			erase(nxt-prv),gap.insert(nxt-u),gap.insert(u-prv);
		}
		if(*gap.begin()>=1e12)
		{
			puts("0");
			continue;
		}
		printf("%lld\n",query());
	}
}