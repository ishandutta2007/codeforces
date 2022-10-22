#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
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

int n,k,pre[maxn],dp[maxn][2];
char s[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); k=read(); scanf("%s",s+1); int cnt=0;
		rep(i,1,n) cnt+=(s[i]=='1');
		rep(i,1,n) pre[i]=pre[i-1]+(s[i]=='1');
		rep(i,1,(k-1)) dp[i][1]=inf;
		rep(i,1,n)
		{
			dp[i][0]=dp[i-1][0]+(s[i]=='0')-(s[i-1]=='0')+(s[i-1]=='1');
			if(i>=k) dp[i][1]=min(dp[i-k][0],dp[i-k][1])+pre[i-1]-pre[i-k]+(s[i]=='0');
		}
		int ans=cnt;
		rep(i,1,n) ans=min(ans,min(dp[i][0],dp[i][1])+(pre[n]-pre[i]));
		cout<<ans<<endl;
	}
	return 0;
}