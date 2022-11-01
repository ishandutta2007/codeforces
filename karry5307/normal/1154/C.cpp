#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll u,v,w,res,c;
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
inline ll check(ll u,ll v,ll w,ll c)
{
	ll r=0;
	while(u>=0&&v>=0&&w>=0)
	{
		c==1||c==4||c==7?u--:c==2||c==6?v--:w--,r++,c=c%7+1;
	}
	return r-1;
}
int main()
{
	u=read(),v=read(),w=read(),res+=min(u/3,min(v/2,w/2));
	u-=3*res,v-=2*res,w-=2*res,res*=7;
	for(register int i=1;i<=7;i++)
	{
		c=max(c,check(u,v,w,i));
	}
	printf("%d\n",res+c);
}