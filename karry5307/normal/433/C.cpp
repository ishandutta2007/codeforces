#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,m,c;
li res,sm,r,rr;
ll x[MAXN];
vector<ll>v[MAXN];
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
	for(register int i=1;i<=m;i++)
	{
		x[i]=read();
	}
	for(register int i=1;i<=m;i++)
	{
		i>1&&x[i]!=x[i-1]?v[x[i-1]].push_back(x[i]):(void)1;
		i<m&&x[i]!=x[i+1]?v[x[i+1]].push_back(x[i]):(void)1;	
	}	
	for(register int i=1;i<=n;i++)
	{
		if(!v[i].size())
		{
			continue;
		}
		sort(v[i].begin(),v[i].end()),c=v[i][v[i].size()>>1],r=0,rr=0;
		for(register int j:v[i])
		{
			r+=abs(i-j)-abs(c-j),rr+=abs(i-j);
		}
		res=max(res,r),sm+=rr;
	}
	printf("%lld\n",sm/2-res);
}