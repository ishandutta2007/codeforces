#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=3e5+51,inf=0x7f7f7f7f7f7f7f7f;
struct Item{
	ll x,id;
	inline bool operator <(const Item &rhs)const
	{
		return this->x<rhs.x;
	}
};
Item item[MAXN];
ll cnt,cur,res;
ll dp[MAXN],pos[MAXN],rp[MAXN];
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
	cnt=read();
	item[cnt]=item[cnt+1]=item[cnt+2]=item[cnt+3]=(Item){inf,inf};
	for(register int i=0;i<cnt;i++)
	{
		item[i]=(Item){read(),i};
	}
	sort(item,item+cnt),memset(dp,0x7f,sizeof(dp)),dp[0]=0,cur=cnt,res=1;
	for(register int i=0;i<cnt;i++)
	{
		for(register int j=5;j>=3;j--)
		{
			if(dp[i+j]>dp[i]+item[i+j-1].x-item[i].x)
			{
				pos[i+j]=i,dp[i+j]=dp[i]+item[i+j-1].x-item[i].x;
			}
		}
	}
	while(cur)
	{
		for(register int i=cur-1;i>=pos[cur];i--)
		{
			rp[item[i].id]=res;
		}
		res++,cur=pos[cur];
	}
	printf("%lld %lld\n",dp[cnt],res-1);
	for(register int i=0;i<cnt;i++)
	{
		printf("%lld ",rp[i]);
	}
}