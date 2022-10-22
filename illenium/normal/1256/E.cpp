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
#define maxn 200050
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

ll dp[maxn],ans[maxn],cnt[maxn],f[maxn];
struct node{ll x,id;}p[maxn];
inline bool cmp(node a,node b){return a.x<b.x;}

int main()
{
	int n=read();
	for(int i=1;i<=n;i++) p[i].x=read(),p[i].id=i;
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n+1;i++) dp[i]=inf; dp[1]=0;
	for(int i=3;i<=n+1;i++)
	{
		ll tmp=inf;
		int fl=0;
		if(i>3)
		{
			if(tmp>dp[i-3]+p[i-1].x-p[i-3].x)
			{
				tmp=dp[i-3]+p[i-1].x-p[i-3].x;
				fl=3;
			}
		}
		if(i>4)
		{
			if(tmp>dp[i-4]+p[i-1].x-p[i-4].x)
			{
				tmp=dp[i-4]+p[i-1].x-p[i-4].x;
				fl=4;
			}
		}
		if(i>5)
		{
			if(tmp>dp[i-5]+p[i-1].x-p[i-5].x)
			{
				tmp=dp[i-5]+p[i-1].x-p[i-5].x;
				fl=5;
			}
		}
		dp[i]=min(dp[i],tmp);
		cnt[i]=cnt[i-fl]+1; f[i]=fl;
	}
	cout<<dp[n+1]<<" "<<cnt[n+1]<<endl;
	int cnt2=1; int x=n+1;
	while(x!=1)
	{
		for(int j=1;j<=f[x];j++) ans[p[x-j].id]=cnt2;
		cnt2++; x-=f[x];
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" "; cout<<endl;
	return 0;
}