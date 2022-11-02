#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e3+51;
vector<ll>v1,v2,v3,v4;
ll test,n,m,sm1,sm2,cx,cy;
ll x[MAXN],y[MAXN];
bitset<MAXN*MAXN>f[MAXN];
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
inline ll calc(ll n,ll sm,ll *x,vector<ll>&v1,vector<ll>&v2)
{
	ll cur=sm>>1;
	for(register int i=1;i<=n;i++)
	{
		f[i]=f[i-1]|(f[i-1]<<x[i]);
	}
	if(!f[n][cur])
	{
		return 0;
	}
	for(register int i=n;i;i--)
	{
		if(cur>=x[i]&&f[i-1][cur-x[i]])
		{
			v1.push_back(x[i]),cur-=x[i];
			continue;	
		}
		v2.push_back(x[i]);
	}
	return 1;
}
inline void solve()
{
	n=read(),f[0][0]=1,cx=cy=sm1=sm2=0;
	for(register int i=1;i<=n;i++)
	{
		x[i]=read(),sm1+=x[i];
	} 
	m=read(),v1.clear(),v2.clear(),v3.clear(),v4.clear();
	for(register int i=1;i<=m;i++)
	{
		y[i]=read(),sm2+=y[i];
	}
	if(n!=m||(sm1&1)||(sm2&1)||!calc(n,sm1,x,v1,v2)||!calc(m,sm2,y,v3,v4))
	{
		return (void)puts("No");
	}
	sort(v1.begin(),v1.end(),greater<ll>()),sort(v3.begin(),v3.end());
	sort(v2.begin(),v2.end(),greater<ll>()),sort(v4.begin(),v4.end());
	v1.size()>v3.size()?swap(v1,v2),swap(v3,v4),1:1,puts("Yes");
	for(register int i:v2)
	{
		v1.push_back(-i);
	}
	for(register int i:v4)
	{
		v3.push_back(-i);
	}
	for(register int i=0;i<n;i++)
	{
		cx+=v1[i],printf("%d %d\n",cx,cy),cy+=v3[i],printf("%d %d\n",cx,cy);
	}
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}