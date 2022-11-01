#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;
const ll MAXN=2e5+51;
ll n,cur,syk,res=1e18;
ll c[7],x[MAXN],f[MAXN];
pii r[MAXN*6];
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
	for(register int i=1;i<=6;i++)
	{
		c[i]=read();
	}
	n=read();
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
		for(register int j=1;j<=6;j++)
		{
			r[(i-1)*6+j]=(pii){x[i]-c[j],i};
		}
	}
	sort(r+1,r+6*n+1),cur=1;
	for(register int i=1;i<=6*n;i++)
	{
		!f[r[i].second]++?syk++:1;
		while(f[r[cur].second]>1)
		{
			f[r[cur++].second]--;
		}
		syk==n?res=min(res,r[i].first-r[cur].first):1;
	}
	printf("%lld\n",res);
}