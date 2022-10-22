#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
mt19937_64 rng(time(0));

const int mn = 3e5+10;
const ll mod = 1e9+7;

int h[mn];
int dp[20][20][20];
pii bac[20][20][20];
int num[20][20][20];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n,a,b;
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)cin>>h[i],++h[i];
	memset(dp,0x3f,sizeof(dp));
	dp[2][h[2]][h[1]]=0;
	for(int i=2;i<n;i++){
		for(int j=0;j<=h[i];j++)for(int k=0;k<=h[i-1];k++){
			for(int l=0;l<20;l++){
				if(k-l*b>0)continue;
				int jj=max(0,h[i+1]-l*b);
				int kk=max(0,j-l*a);
				if(dp[i+1][jj][kk]>dp[i][j][k]+l){
					dp[i+1][jj][kk]=dp[i][j][k]+l;
					bac[i+1][jj][kk]={j,k};
					num[i+1][jj][kk]=l;
				}
				if(jj==0&&kk==0)break;
			}
		}
	}
	printf("%d\n",dp[n][0][0]);
	pii st{0,0};
	for(int i=n;i>2;i--){
		int k=num[i][st.first][st.second];
		for(int j=0;j<k;j++)printf("%d ",i-1);
		st=bac[i][st.first][st.second];
	}
}