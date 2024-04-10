#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll cnt,flag;
ll num[MAXN],dp[MAXN];
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
	for(register int i=1;i<=cnt;i++)
	{
		num[i]=read();
		if(num[i]&&!flag)
		{
			dp[i]=1,flag=1;
		}
	}
	for(register int i=1;i<=cnt;i++)
	{
		if(num[i])
		{
			for(register int j=i-1;j;j--)
			{
				if(num[j])
				{
					dp[i]+=dp[j];
					break;
				}
				dp[i]+=dp[j];
			}
		}
		else
		{
			dp[i]=dp[i-1];
		}
	}
	printf("%lld\n",dp[cnt]);
}