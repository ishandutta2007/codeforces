#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef array<ll,21> farray;

const int mn = 8e5+10;
const ll mod = 1e9+7;

int val[4]={0,1,0,2};
int dp[mn][4];

int solve(){
	int n;
	cin>>n;
	string s[2];
	cin>>s[0]>>s[1];
	for(int i=0;i<=n;i++)for(int j=0;j<4;j++)dp[i][j]=0xc0c0c0c0;
	dp[0][0]=0;
	for(int i=0;i<n;i++){
		int v=(1<<(s[0][i]-'0'))|(1<<(s[1][i]-'0'));
		//cerr<<v<<endl;
		for(int j=0;j<4;j++)dp[i+1][j|v]=max(dp[i+1][j|v],dp[i][j]);
		for(int j=0;j<4;j++)dp[i+1][0]=max(dp[i+1][0],dp[i+1][j]+val[j]);
	}
	printf("%d\n",dp[n][0]);
	return 0;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int tc;
	cin>>tc;
	for(int tcc=1;tcc<=tc;++tcc){
		int temp;
		if(temp = solve()) {
			cerr << "Case #"<<tcc << ": Invalid Return" << temp << endl;
		}
	}
}