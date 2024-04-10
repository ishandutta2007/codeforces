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
int dp[550][5050];
int cnta[100100],cntb[100100];
int h[100100];
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n*k;i++)
	{
		int x;
		cin>>x;
		cnta[x]++;
	}
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		cntb[x]++;
	}
	for(int i=1;i<=k;i++)
		cin>>h[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<=n*k;j++)
			for(int l=0;l<=k;l++)
				dp[i+1][j+l]=max(dp[i+1][j+l],dp[i][j]+h[l]);
	int ans=0;
	for(int i=0;i<=100000;i++)
	{
//		if(cntb[i]||cnta[i])
//			cout<<i<<" "<<dp[cntb[i]][cnta[i]]<<endl;
		ans+=dp[cntb[i]][cnta[i]];
	}
	cout<<ans<<endl; 
	return 0;
}