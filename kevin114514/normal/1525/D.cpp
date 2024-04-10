#include<bits/stdc++.h>
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
void die(string S){puts(S.c_str());exit(0);}
ll dp[5050][5050];
int main()
{
	for(int i=0;i<5050;i++)
		for(int j=0;j<5050;j++)
			dp[i][j]=1e18;
	int n;
	cin>>n;
	vector<int> v1,v0;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		if(x)
			v1.pb(i);
		else	v0.pb(i);
	}
	int n1=sz(v1);
	int n0=sz(v0);
	swap(n0,n1);
	dp[0][0]=0;
	for(int i=0;i<=n0;i++)
		for(int j=i;j<n1;j++)
		{
			if(i<n0)
				dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+abs(v1[i]-v0[j]));
			dp[i][j+1]=min(dp[i][j+1],dp[i][j]);
		}
	cout<<dp[n0][n1]<<endl;
	return 0;
}