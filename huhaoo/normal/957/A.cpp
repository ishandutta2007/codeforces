#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
int read()
{
	int t=1,r=0,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
int n;
char s[1100];
int dp[1100][10];
int main()
{
	n=read();
	fr(i,1,n)
	{
		s[i]=getchar();
		while(s[i]!='C'&&s[i]!='M'&&s[i]!='Y'&&s[i]!='?')s[i]=getchar();
		if(s[i]=='C')s[i]=1;
		if(s[i]=='M')s[i]=2;
		if(s[i]=='Y')s[i]=3;
		if(s[i]=='?')s[i]=0;
	}
	if(s[1])dp[1][s[1]]=1;
	else dp[1][1]=dp[1][2]=dp[1][3]=1;
	fr(i,2,n)
	{
		int l=1,r=3;
		if(s[i])l=r=s[i];
		fr(j,l,r)if(j!=s[i-1])
			if(s[i-1]==0)
			{
				dp[i][j]+=dp[i-1][1]+dp[i-1][2]+dp[i-1][3]-dp[i-1][j];
				dp[i][j]=min(dp[i][j],2);
			}
			else
			{
				dp[i][j]+=dp[i-1][s[i-1]];
				dp[i][j]=min(dp[i][j],2);
			}
	}
	if(dp[n][1]+dp[n][2]+dp[n][3]>=2)printf("Yes\n");
	else printf("No\n");
	return 0;
}