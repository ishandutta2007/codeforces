#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 2000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int dp[10][10];
char s[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",s+1); int len=strlen(s+1);
		rep(i,0,9) rep(j,0,9) dp[i][j]=0;
		rep(i,1,len)
		{
			char c=s[i]-'0';
			rep(i,0,9) dp[c][i]=max(dp[c][i],dp[i][c]+1);
		}
		int tmp=0;
		rep(i,0,9) rep(j,0,9)
		{
			if(dp[i][j]%2==0||i==j) tmp=max(tmp,dp[i][j]);
			else tmp=max(tmp,dp[i][j]-1);
		}
		printf("%d\n",len-tmp);
	}
	return 0;
}