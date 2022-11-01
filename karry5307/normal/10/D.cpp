#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1e3+51;
ll xl,yl,res,top;
ll x[MAXN],y[MAXN],back[MAXN],dp[MAXN],st[MAXN];
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
	xl=read();
	for(register int i=1;i<=xl;i++)
	{
		x[i]=read();
	}
	yl=read();
	for(register int i=1;i<=yl;i++)
	{
		y[i]=read();
	}
	for(register int i=1,k=0;i<=xl;i++,k=0)
	{
		for(register int j=1;j<=yl;j++)
		{
			if(x[i]==y[j])
			{
				dp[j]=dp[k]+1,back[j]=k;
			}
			if(x[i]>y[j]&&dp[k]<dp[j])
			{
				k=j;
			}
		}
	}
	for(register int i=1;i<=yl;i++)
	{
		if(dp[i]>dp[res])
		{
			res=i;
		}
	}
	printf("%d\n",dp[res]);
	if(!dp[res])
	{
		puts("");
		return 0;
	}
	st[++top]=res;
	while(back[res])
	{
		st[++top]=(res=back[res]);
	}
	while(top)
	{
		printf("%d ",y[st[top--]]);
	} 
}