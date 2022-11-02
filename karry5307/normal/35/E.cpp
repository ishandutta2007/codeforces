#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
typedef pair<ll,ll> pii;
const ll MAXN=2e5+51;
struct Event{
	ll tp,id,h;
	inline bool operator <(const Event &rhs)const
	{
		return id==rhs.id?tp<rhs.tp:id<rhs.id;
	}
};
Event ev[MAXN<<1];
multiset<ll>st;
vector<pii>v;
ll n,totd,lst,cur,id;
ll l[MAXN],r[MAXN],h[MAXN],dsc[MAXN];
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
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	n=read();
	for(register int i=1;i<=n;i++)
	{
		dsc[++totd]=h[i]=read(),l[i]=read(),r[i]=read();
	}
	sort(dsc+1,dsc+totd+1),totd=unique(dsc+1,dsc+totd+1)-dsc-1;
	for(register int i=1;i<=n;i++)
	{
		h[i]=lower_bound(dsc+1,dsc+totd+1,h[i])-dsc;
		ev[i*2-1]=(Event){0,l[i],h[i]},ev[i*2]=(Event){1,r[i],h[i]};
	}
	sort(ev+1,ev+2*n+1);
	for(register int i=1;i<=2*n;i++)
	{
		lst=st.empty()?0:dsc[*(st.rbegin())];
		ev[i].tp?st.erase(st.find(ev[i].h)):st.insert(ev[i].h);
		while(ev[i+1].id==ev[i].id)
		{
			i++;
			ev[i].tp?st.erase(st.find(ev[i].h)):st.insert(ev[i].h);
		}
		cur=st.empty()?0:dsc[*(st.rbegin())];
		if(lst!=cur)
		{
			v.push_back((pii){ev[i].id,lst}),v.push_back((pii){ev[i].id,cur});
		}
	}
	printf("%d\n",v.size());
	for(auto i:v)
	{
		printf("%d %d\n",i.first,i.second);
	}
}