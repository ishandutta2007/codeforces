#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mn = 3e3+10;
const ll mod = 1e9+7;

int a[mn];
int dp[mn][mn];
vector<int>pos[mn];

void solve(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j]=0;
	for(int i=1;i<=n;i++)pos[i].clear();
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			dp[i][j]=dp[i-1][j];
			for(int p:pos[a[i]])if(j<=p){
				dp[i][j]=max(dp[i][j],dp[i-1][p+1]+dp[p][j]+1);
			}
		}
		dp[i][i]=0;
		pos[a[i]].push_back(i);
	}
	printf("%d\n",n-1-dp[n][1]);
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int tc;
	cin>>tc;
	for(int tcc=1;tcc<=tc;++tcc){
		int temp;
		solve();
	}
}