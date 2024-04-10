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
int dp[2020][2020];
bool haverain[2020];
int weight[2020];
int main()
{
	int a,n,m;
	cin>>a>>n>>m;
	while(n--)
	{
		int l,r;
		cin>>l>>r;
		for(int i=l;i<r;i++)
			haverain[i]=1;
	}
	while(m--)
	{
		int p,x;
		cin>>p>>x;
		if(!weight[p+1]||x<weight[p+1])
			weight[p+1]=x;
	}
	memset(dp,0x3f3f3f3f,sizeof(dp));
	dp[0][0]=0;
//	priority_queue<pii> pq;
	for(int i=0;i<=a;i++)
	{
//		pq.push(mp(weight[i],i));
		for(int j=0;j<=i+1;j++)
		{
			if(weight[i+1])
				dp[i][i+1]=min(dp[i][i+1],dp[i][j]);
			dp[i][0]=min(dp[i][0],dp[i][j]);
			if(i<a)
			{
				if(!haverain[i]||j)
					dp[i+1][j]=min(dp[i+1][j],dp[i][j]+weight[j]);
			}
		}
		for(int j=0;j<=i+1;j++)
		{
			if(weight[i+1])
				dp[i][i+1]=min(dp[i][i+1],dp[i][j]);
			dp[i][0]=min(dp[i][0],dp[i][j]);
			if(i<a)
			{
				if(!haverain[i]||j)
					dp[i+1][j]=min(dp[i+1][j],dp[i][j]+weight[j]);
			}
		}
	}
//	for(int i=0;i<=a;i++)
//		for(int j=0;j<=a;j++)
//			printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
	int ans=0x3f3f3f3f;
	for(int i=0;i<=a;i++)
		ans=min(ans,dp[a][i]);
	if(ans==0x3f3f3f3f)
		die("-1");
	cout<<ans<<endl;
	return 0;
}