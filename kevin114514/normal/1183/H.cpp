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
int n;
ll k;
ll dp[110][110];
int lst[256];
ll total[110];
int main()
{
	cin>>n>>k;
	string S;
	cin>>S;
	memset(lst,-1,sizeof(lst));
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=n;j++)
		{
//			cout<<lst[S[i]]<<endl;
			if(lst[S[i]]==-1)
			{
				dp[i+1][j]=dp[i][j]+(j>0?dp[i][j-1]:0)+(bool)(j==1);
				dp[i+1][j]=min(dp[i+1][j],100000000000000000ll);
			}
			else
			{
				dp[i+1][j]=dp[i][j]+(j>0?dp[i][j-1]:0)-(j>0?dp[lst[S[i]]][j-1]:0);
				dp[i+1][j]=min(dp[i+1][j],100000000000000000ll);
			}
		}
		lst[S[i]]=i;
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=i;j++)
//		{
//			cout<<dp[i][j]<<" ";
//		}
//		puts("");
//	}
	ll result=0;
	dp[n][0]=1;
	for(int i=n;i>=0;i--)
	{
		result+=min(k,dp[n][i])*(n-i);
		k-=min(k,dp[n][i]);
	}
	if(k)
		die("-1");
	cout<<result<<endl;
	return 0;
}