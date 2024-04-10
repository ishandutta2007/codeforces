#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
typedef pair<ll,ll>pii;
const ll MAXN=2e5+51;
map<pii,ll>mp;
mt19937 mt(20050103);
ll n,m,u,v,s,t;
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
	n=read(),m=read(),v=read(),u=1+(v==1);
	if(m<n-1||m>(li)(n-1)*(n-2)/2+1)
	{
		return puts("-1"),0;
	}
	for(register int i=1;i<=n;i++)
	{
		i!=v?printf("%d %d\n",i,v),mp[(pii){i,v}]=mp[(pii){v,i}]=1:1;
	}
	for(register int i=1;i<=n;i++)
	{
		mp[(pii){u,i}]=mp[(pii){i,u}]=1;
	}
	m-=n-1;
	for(register int i=1;i<=m;i++)
	{
		s=mt()%n+1,t=mt()%n+1;
		while(mp[(pii){s,t}]||s==t)
		{
			s=mt()%n+1,t=mt()%n+1;
		}
		mp[(pii){s,t}]=mp[(pii){t,s}]=1,printf("%d %d\n",s,t);
	}
}