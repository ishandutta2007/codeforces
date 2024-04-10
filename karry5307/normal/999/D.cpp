#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
typedef pair<ll,ll> pii;
const ll MAXN=2e5+51;
vector<pii>fr;
vector<ll>r[MAXN];
ll n,m,rr,c;
li res;
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
int main()
{
	n=read(),m=read();
	for(register int i=1;i<=n;i++)
	{
		r[(x[i]=read())%m].push_back(i);
	}
	for(register int i=0,j=1;j<=2*m;i=(i+1)%m,j++)
	{
		while(r[i].size()>n/m)
		{
			fr.push_back((pii){r[i].back(),i}),r[i].pop_back();
		}
		while(fr.size()&&r[i].size()<n/m)
		{
			c=fr.back().first,rr=fr.back().second,fr.pop_back();
			r[i].push_back(c),res+=j-1-rr,x[c]+=j-1-rr;
		}
	}
	printf("%lld\n",res);
	for(register int i=1;i<=n;i++)
	{
		printf("%d ",x[i]);
	}
}