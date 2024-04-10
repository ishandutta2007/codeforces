#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=5e5+51;
ll cnt,res;
ll num[MAXN],dp[MAXN][2];
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
	} 
	dp[1][0]=1,dp[1][1]=0;
	for(register int i=2;i<=cnt;i++)
	{
		dp[i][0]=1,dp[i][1]=0;
		if(num[i-1]<num[i])
		{
			dp[i][0]=max(dp[i][0],dp[i-1][0]+1);
			dp[i][1]=max(dp[i][1],dp[i-1][1]+1);
		}	
		if(num[i-2]<num[i])
		{
			dp[i][1]=max(dp[i][1],dp[i-2][0]+1);
		}
	} 
	for(register int i=1;i<=cnt;i++)
	{
		res=max(res,max(dp[i][0],dp[i][1]));
	}
	printf("%d\n",res);
}