#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) ((x).begin(),(x).end)
#define rALL(x) ((x).rbegin(),(x).rend)
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
void die(string S){puts(S.c_str());exit(0);}
double dp[100100][15];
bool ok[100100][15];
pair<int,int> prv[100100][15];
double x[100100];
int y[100100];
int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int n,k;
	cin>>n>>k;
	bool f=0;
	for(int i=0;i<n;i++)
	{
		cin>>y[i];
		if(y[i]==1)
			f=true;
		x[i]=log(y[i]);
//		cout<<fixed<<x[i]<<endl;
	}
	for(int i=0;i<=n;i++)
		for(int j=0;j<10;j++)
			dp[i][j]=-2.0;
	ok[0][1]=true;
	dp[0][1]=0.0;
	prv[0][1]=mp(-1,-1);
	for(int i=0;i<n;i++)
		for(int j=0;j<10;j++)
		if(ok[i][j])
		{
//			cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
			int to=j*y[i]%10;
			ok[i+1][to]=1;
			if(dp[i][j]+x[i]>dp[i+1][to])
			{
				dp[i+1][to]=dp[i][j]+x[i];
				prv[i+1][to]=mp(j,1);
			}
			ok[i+1][j]=1;
			if(dp[i][j]>dp[i+1][j])
			{
				dp[i+1][j]=dp[i][j];
				prv[i+1][j]=mp(j,0);
			}
		}
	if(!ok[n][k])
		die("-1");
	int u=n,v=k;
	vector<int> ans;
	while(u)
	{
		if(prv[u][v].second)
			ans.pb(y[u-1]);
		v=prv[u][v].first;
		u--;
	}
	if(ans.empty())
		die("-1");
	cout<<(int)ans.size()<<endl;
	for(int i=0;i<(int)(ans.size());i++)
		cout<<ans[i]<<" ";
	return 0;
}