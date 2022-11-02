#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=1e5+51;
ll n,m,p,u,v;
ll d[MAXN],t[MAXN],prefix[MAXN],q[101][MAXN],dp[101][MAXN];
ll hd[MAXN],tl[MAXN];
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
inline double slope(ll x,ll y,ll z)
{
	return (1.0*prefix[y]+dp[x][y]-prefix[z]-dp[x][z])/(y-z);
}
int main()
{
	n=read(),m=read(),p=read();
	if(p>=m)
	{
		return puts("0"),0;
	}
	for(register int i=2;i<=n;i++)
	{
		d[i]=read()+d[i-1];
	}
	for(register int i=1;i<=m;i++)
	{
		u=read(),v=read(),t[i]=-d[u]+v;
	}
	sort(t+1,t+m+1);
	for(register int i=1;i<=m;i++)
	{
		prefix[i]=prefix[i-1]+t[i];
	}
	for(register int i=1;i<=m;i++)
	{
		for(register int j=1;j<=min((ll)i,p);j++)
		{
			while(hd[j-1]<tl[j-1]&&slope(j-1,q[j-1][hd[j-1]],q[j-1][hd[j-1]+1])<=t[i])
			{
				hd[j-1]++;
			}
			u=q[j-1][hd[j-1]],dp[j][i]=dp[j-1][u]+t[i]*(i-u)-prefix[i]+prefix[u];
			while(hd[j]<tl[j]&&slope(j,q[j][tl[j]],i)<slope(j,q[j][tl[j]-1],q[j][tl[j]]))
			{
				tl[j]--;
			}
			q[j][++tl[j]]=i;
		}
	}
	printf("%lld\n",dp[p][m]);
}