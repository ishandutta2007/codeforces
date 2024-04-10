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

char s[maxn];
int len,dp[maxn],sz[maxn],mp[30],cnt;

int main()
{
	scanf("%s",s+1); len=strlen(s+1);
	for(int i=1;i<=len;i++) if(mp[s[i]-'a']==0) mp[s[i]-'a']=1,cnt++;
	int ed=(1<<20)-1,ans=0;
	for(int i=1;i<=ed;i++) sz[i]=sz[i>>1]+(i&1);
	for(int i=1;i<=len;i++)
	{
		int sta=0;
		for(int j=1;j<=20&&i+j-1<=len;j++)
		{
			if((sta&(1<<(s[i+j-1]-'a')))) break;
			sta|=(1<<(s[i+j-1]-'a')); dp[sta]=sz[sta];
		}
	}
	for(int i=0;i<=ed;i++)
	{
		for(int j=1;j<=20;j++)
		{
			if((i&(1<<(j-1)))) dp[i]=max(dp[i],dp[i^(1<<(j-1))]);
		}
	}
	//for(int i=0;i<=7;i++) cout<<i<<" "<<dp[i]<<endl;
	for(int i=0;i<=ed;i++) ans=max(ans,dp[i]+dp[ed^i]);
	cout<<ans<<endl;
	return 0;
}