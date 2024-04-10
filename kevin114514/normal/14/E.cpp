#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define sz(Vector) (int)(Vector.size())
using namespace std;
const ll mod=1e9+7;
ll dp[22][22][22][6][3];
void update(ll &a,ll b)
{
	a+=b;
}
int main()
{
	dp[1][0][0][1][2]=1;
	dp[1][0][0][2][2]=1;
	dp[1][0][0][3][2]=1;
	dp[1][0][0][4][2]=1;
	int n,t;
	cin>>n>>t;
	for(int i=0;i<n;i++)
		for(int j=0;j<=n;j++)
			for(int k=0;k<=n;k++)
				for(int l=1;l<=4;l++)
					for(int m=0;m<=2;m++)
					{
						for(int x=1;x<=4;x++)
							if(l!=x)
							{
								bool f=x>l;
								if(f==m||m==2)
									update(dp[i+1][j][k][x][f],dp[i][j][k][l][m]);
								else
								{
									if(m==0)
									{
										update(dp[i+1][j][k+1][x][f],dp[i][j][k][l][m]);
									} 
									else
									{
										update(dp[i+1][j+1][k][x][f],dp[i][j][k][l][m]);
									}
								}
							}
					}
	ll ans=0;
	for(int i=0;i<8;i++)
		update(ans,dp[n][t][t-1][i/2+1][i%2]);
	cout<<ans<<endl;
	return 0;
}