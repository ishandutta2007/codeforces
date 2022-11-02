#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e6+51;
set<ll>st;
ll n,prv,nxt;
li mx,mn;
ll x[MAXN],c[MAXN];
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
	n=read(),st.insert(0),st.insert(n+1);
	for(register int i=1;i<=n;i++)
	{
		x[i]=read(),c[i]=i;
	}
	sort(c+1,c+n+1,[&](ll u,ll v){return x[u]>x[v];});
	for(register int i=1;i<=n;i++)
	{
		prv=*(--st.lower_bound(c[i])),nxt=*(st.lower_bound(c[i]));
		mx+=(li)(c[i]-prv)*(nxt-c[i])*x[c[i]],st.insert(c[i]);
	}
	st.clear(),st.insert(0),st.insert(n+1);
	for(register int i=n;i;i--)
	{
		prv=*(--st.lower_bound(c[i])),nxt=*(st.lower_bound(c[i]));
		mn+=(li)(c[i]-prv)*(nxt-c[i])*x[c[i]],st.insert(c[i]);
	}
	printf("%lld\n",mx-mn);
}