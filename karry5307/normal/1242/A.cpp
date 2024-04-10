#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
vector<ll>v;
ll x;
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
	x=read();
	for(register int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)
		{
			v.push_back(i);
			while(x%i==0)
			{
				x/=i;
			}
		}
	}
	if(x!=1)
	{
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	if(v.size()==1)
	{
		return printf("%lld\n",v.front()),0;
	}
	if(v.empty())
	{
		return printf("%lld\n",x),0;
	}
	puts("1");
}