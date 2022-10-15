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
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
void die(string S){puts(S.c_str());exit(0);}
int a[110],b[110];
int dp[110][20010];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		for(int i=0;i<=n;i++)
			memset(dp[i],inf,sizeof(dp[i]));
		dp[0][0]=0;
		int sum=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=sum;j++)
			{
				int bsum=sum-j;
				dp[i+1][j+a[i]]=min(dp[i+1][j+a[i]],dp[i][j]+a[i]*j+b[i]*bsum);
				dp[i+1][j+b[i]]=min(dp[i+1][j+b[i]],dp[i][j]+b[i]*j+a[i]*bsum);
			}
			sum+=a[i]+b[i];
		}
		int x=*min_element(dp[n],dp[n]+sum+1);
		x+=x;
		for(int i=0;i<n;i++)
			x+=(a[i]*a[i]+b[i]*b[i])*(n-1);
		cout<<x<<endl;
	}
	return 0;
}