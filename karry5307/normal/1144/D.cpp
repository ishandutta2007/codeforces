#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
map<ll,ll>mp,mp2;
ll n,c;
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
	n=read(),x[0]=x[n+1]=1e9;
	for(register int i=1;i<=n;i++)
	{
		mp2[x[i]=read()]++;
	}
	for(auto i:mp2)
	{
		mp[i.second]=i.first;
	}
	c=(*mp.rbegin()).second,printf("%d\n",n-(*mp.rbegin()).first);
	for(register int i=n;i;i--)
	{
		if(x[i+1]==c&&x[i]!=c)
		{
			x[i]<c?printf("1 %d %d\n",i,i+1):printf("2 %d %d\n",i,i+1),x[i]=c;
		}
	}
	for(register int i=1;i<=n;i++)
	{
		if(x[i-1]==c&&x[i]!=c)
		{
			x[i]<c?printf("1 %d %d\n",i,i-1):printf("2 %d %d\n",i,i-1),x[i]=c;
		}
	}
}