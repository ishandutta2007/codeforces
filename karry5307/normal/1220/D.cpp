#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
unordered_map<li,ll>mp;
ll cnt,maxn,res;
ll barrel[64];
li num[MAXN];
inline li read()
{
    register li num=0,neg=1;
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
inline ll ctz(li x)
{
	return mp[x&-x];
}
int main()
{
	for(register int i=0;i<64;i++)
	{
		mp[1ll<<i]=i;
	}
	cnt=read();
	for(register int i=0;i<cnt;i++)
	{
		barrel[ctz(num[i]=read())]++;
	}
	for(register int i=0;i<64;i++)
	{
		if(barrel[i]>res)
		{
			res=barrel[i],maxn=i;
		}
	}
	printf("%d\n",cnt-res);
	for(register int i=0;i<cnt;i++)
	{
		if(ctz(num[i])!=maxn)
		{
			printf("%lld ",num[i]);
		}
	}
}