#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
mt19937_64 rng(time(0));
 
const int mn = 71;
const ll mod = 1e9+7;

int a[mn][mn];
int dp[2][mn][mn];
int ret[mn][mn];
int ans[mn];

void getrow(int r[mn], int m, int k, int ind){
	memset(dp,0xc0,sizeof(dp));
	dp[0][0][0]=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<k;j++)for(int l=0;l<=m/2;l++){
			dp[1][(j+r[i])%k][l+1]=max(dp[1][(j+r[i])%k][l+1],dp[0][j][l]+r[i]);
			dp[1][j][l]=max(dp[1][j][l],dp[0][j][l]);
		}
		memcpy(dp[0],dp[1],sizeof(dp[0]));
		memset(dp[1],0xc0,sizeof(dp[1]));
	}
	for(int i=0;i<k;i++)for(int j=0;j<=m/2;j++)ret[ind][i]=max(ret[ind][i],dp[0][i][j]);
}

int t[mn];
void add(int a[mn], int b[mn],int k){
	memset(t,0xc0,sizeof(t));
	for(int i=0;i<k;i++)for(int j=0;j<k;j++)t[(i+j)%k]=max(t[(i+j)%k],a[i]+b[j]);
	memcpy(a,t,sizeof(t));
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];
	memset(ret,0xc0,sizeof(ret));
	for(int i=0;i<n;i++){
		getrow(a[i],m,k,i);
	}
	memset(ans,0xc0,sizeof(ans));
	ans[0]=0;
	for(int i=0;i<n;i++)add(ans,ret[i],k);
	printf("%d\n",ans[0]);
}