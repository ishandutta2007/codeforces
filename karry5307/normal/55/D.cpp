#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll tot,test,l,r;
ll num[151],mp[2521],dp[25][2521][50];
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
inline ll __lcm(ll x,ll y)
{
	return x/__gcd(x,y)*y;
}
inline ll dfs(ll cur,ll rem,ll lcm,ll kk)
{
	if(!cur)
	{
		return rem%lcm==0;
	}
	if(!kk&&dp[cur][rem][mp[lcm]]!=0x3f3f3f3f3f3f3f3f)
	{
		return dp[cur][rem][mp[lcm]];
	}
	ll res=0,nxtRem,nxtLcm,maxn=kk?num[cur]:9;
	for(register int i=0;i<=maxn;i++)
	{
		nxtRem=(rem*10+i)%2520,nxtLcm=i?__lcm(lcm,i):lcm;
		res+=dfs(cur-1,nxtRem,nxtLcm,kk&(i==maxn));
	}
	if(!kk)
	{
		dp[cur][rem][mp[lcm]]=res;
	}
	return res;
}
inline ll calc(ll x)
{
	memset(num,0,sizeof(num)),tot=0;
	while(x)
	{
		num[++tot]=x%10,x/=10;
	}
	return dfs(tot,0,1,1); 
}
int main()
{
	for(register int i=1,j=1;i<=2520;i++)
	{
		if(!(2520%i))
		{
			mp[i]=j++;
		}
	}
	memset(dp,0x3f,sizeof(dp));
	test=read();
	for(register int i=0;i<test;i++)
	{
		l=read()-1,r=read();
		cout<<calc(r)-calc(l)<<endl;
	}
}