#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
void die(string S){puts(S.c_str());exit(0);}
ll dp[100005][505];
ll x[100005];
ll psum[100005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",x+i);
		for(int i=1;i<=n;i++)
			psum[i]=psum[i-1]+x[i];
		for(int i=0;i<=n;i++)
			for(int j=0;j<505;j++)
				dp[i][j]=0;
		dp[n][0]=inf;
		for(int i=n;i;i--)
			for(int j=0;j<505;j++)
			{
				dp[i-1][j]=max(dp[i-1][j],dp[i][j]);
				if(i-j>0&&psum[i]-psum[i-j-1]<dp[i][j])
					dp[i-j-1][j+1]=max(dp[i-j-1][j+1],psum[i]-psum[i-j-1]);
			}
		for(int i=504;i>=0;i--)
			if(dp[0][i])
			{
				printf("%d\n",i);
				break;
			}
	}
	return 0;
}