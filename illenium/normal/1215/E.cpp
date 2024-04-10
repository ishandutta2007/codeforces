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
#define maxn 2000005
#define re register
#define inf 1e18
#define eps 1e-10
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,a[maxn],ed;
ll pr[25][25],cnt[25];
ll dp[maxn];

int main()
{
	n=read(); ed=(1<<20)-1;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		cnt[a[i]]++;
		for(int j=1;j<=20;j++) if(j!=a[i]) pr[a[i]][j]+=cnt[j];
	}
	for(int i=1;i<=ed;i++) dp[i]=inf;
	for(int s=1;s<=ed;s++)
	{
		for(int i=1;i<=20;i++)
		{
			if((s&(1<<(i-1)))==0) continue;
			ll tmp=0;
			for(int j=1;j<=20;j++)
			{
				if(j==i||(s&(1<<(j-1)))) continue;
				tmp+=pr[i][j];
			}
			dp[s]=min(dp[s],dp[(s^(1<<(i-1)))]+tmp);
		}
	}
	cout<<dp[ed]<<endl;
	return 0;
}