#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e3+51;
ll n;
ll x[MAXN],dp[MAXN][MAXN],l[MAXN][MAXN],r[MAXN][MAXN];
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
	n=read();
	for(register int i=1;i<=n;i++)
	{
		x[i]=read(),l[i][i]=r[i][i]=1;
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=i;j<=n;j++)
		{
			if(__gcd(x[i],x[j])>1)
			{
				dp[i][j]=dp[j][i]=1;
			}
		}
	} 
	for(register int i=n;i>=1;i--)
	{
		for(register int j=i;j<=n;j++)
		{
			for(register int k=i;k<=j;k++)
			{
				if(l[i][k]&&r[k][j])
				{
					if(i==1&&j==n)
					{
						return puts("Yes"),0;
					}
					if(dp[i-1][k])
					{
						r[i-1][j]=1;
					}
					if(dp[k][j+1])
					{
						l[i][j+1]=1;
					}
				}
			}
		}
	}
	puts("No");
}