#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int M=1e5+9;
int a[M],dp[M];
void work(){
	int n,x;
	cin>>n>>x;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i){
		a[i]+=a[i-1];
		dp[i]=min(dp[i-1],a[i]);
	}
	int ans=0;
	for(int k=0;k<=n;++k){
		for(int i=1;i<=n;++i){
			if(i>=k)ans=max(ans,a[i]-dp[i-k]+k*x);
		}
		cout<<ans<<" \n"[k==n];
	}
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
3 5
-2 -7 -1
*/