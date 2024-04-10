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

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll dp[maxn][2],a[maxn],b[maxn];

int main()
{
	ll n=read(),c=read();
	for(int i=1;i<=n-1;i++) a[i]=read();
	for(int i=1;i<=n-1;i++) b[i]=read();
	dp[0][1]=c;
	for(int i=1;i<=n-1;i++)
	{
		dp[i][1]=min(dp[i-1][0]+c+b[i],dp[i-1][1]+b[i]);
		dp[i][0]=min(dp[i-1][0],dp[i-1][1])+a[i];
	}
	cout<<0<<" ";
	for(int i=1;i<=n-1;i++) printf("%d ",min(dp[i][0],dp[i][1]));
	return 0;
}