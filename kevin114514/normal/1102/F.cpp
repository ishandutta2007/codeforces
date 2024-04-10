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
int mn[19][19];
int mn2[19][19];
int matrix[19][10100];
int dp[19][19][(1<<16)];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>matrix[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			mn[i][j]=1e9;
			for(int k=0;k<m;k++)
				mn[i][j]=min(mn[i][j],abs(matrix[i][k]-matrix[j][k]));
			mn2[i][j]=1e9;
			for(int k=0;k<m-1;k++)
				mn2[i][j]=min(mn2[i][j],abs(matrix[i][k]-matrix[j][k+1]));
		}
//	memset(dp,0x3f3f3f3f,sizeof(dp));
	for(int i=0;i<n;i++)
		dp[i][i][(1<<i)]=1e9;
	for(int msk=1;msk<(1<<n);msk++)
		for(int i=0;i<n;i++) if(msk>>i&1)
			for(int j=0;j<n;j++) if(msk>>j&1) if(__builtin_popcount(msk)==1||i!=j)
				for(int k=0;k<n;k++) if(!(msk>>k&1))
					dp[i][k][msk|(1<<k)]=max(dp[i][k][msk|(1<<k)],min(dp[i][j][msk],mn[j][k]));
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) if(n==1||i!=j)
		{
//			cout<<i<<" "<<j<<" "<<dp[i][j][(1<<n)-1]<<" "<<mn2[j][i]<<endl; 
			ans=max(ans,min(dp[i][j][(1<<n)-1],mn2[j][i]));
		}
	cout<<ans<<endl;
	return 0;
}