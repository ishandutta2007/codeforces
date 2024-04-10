#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int M=2e5+9;
int n;
int dp[M<<1];
int a[M],cnt[M],ma;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		cnt[a[i]]++;
	}
	for(int i=1;i<=100;++i){
		if(cnt[i]>cnt[ma])ma=i;
	}
	for(int i=1;i<=100;++i){
		if(i==ma)continue;
		int s=0;
		for(int j=0;j<=2*n;++j)dp[j]=1e9;
		dp[s+n]=0;
		for(int j=1;j<=n;++j){
			if(a[j]==i)s++;	
			else if(a[j]==ma)s--;
			ans=max(ans,j-dp[s+n]);
			if(dp[s+n]==1e9)dp[s+n]=j;
		}
	}
	cout<<ans<<endl;
}