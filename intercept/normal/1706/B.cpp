#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define eb emplace_back
#define pii pair<int,int>
using namespace std;
const int M=1e5+9;
int n;
int dp[M][2];
void work(){
	cin>>n;
	for(int i=1;i<=n;++i)dp[i][0]=dp[i][1]=0;
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		dp[x][i%2]=max(dp[x][i%2],dp[x][(i%2)^1]+1);
	}
	for(int i=1;i<=n;++i)cout<<max(dp[i][0],dp[i][1])<<" ";
	puts("");
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}