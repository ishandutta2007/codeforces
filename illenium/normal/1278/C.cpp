#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;
 
inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}
 
int a[maxn],s[maxn],s2[maxn],dp[maxn],dp2[maxn];
 
int main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=2*n;i++) a[i]=read();
		for(int i=1;i<=n;i++) s[i]=0,s2[i+n]=0;
		for(int i=1e5-n;i<=1e5+n;i++) dp[i]=-1,dp2[i]=-1;
		s[0]=1e5; dp[100000]=0; dp2[100000]=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==2) s[i]=s[i-1]+1;
			else s[i]=s[i-1]-1;
			dp[s[i]]=max(dp[s[i]],i); //cout<<s[i]<<" "<<dp[s[i]]<<endl;
		}
		s2[2*n+1]=1e5;
		for(int i=2*n;i>=n+1;i--)
		{
			if(a[i]==2) s2[i]=s2[i+1]-1;
			else s2[i]=s2[i+1]+1;
			dp2[s2[i]]=max(dp2[s2[i]],2*n-i+1); //cout<<s2[i]<<" "<<dp2[s2[i]]<<endl;
		}
		int ans=0;
		for(int i=1e5-n;i<=1e5+n;i++)
		{
			if(dp[i]==-1||dp2[i]==-1) continue;
			ans=max(ans,dp[i]+dp2[i]);
		}
		cout<<2*n-ans<<endl;
	}
	return 0;
}