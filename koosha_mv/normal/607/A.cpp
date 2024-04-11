#include <bits/stdc++.h>
using namespace std;
 
int dp[1000006];
pair<int,int> a[100005];
int main() {
	int n,i,j,maxn,ans; cin>>n;
	for(i=0;i<n;i++) {
		scanf(" %d %d",&a[i].first,&a[i].second);
		a[i].first++;
	}
	sort(a,a+n);
	ans=0;
	maxn=a[n-1].first;
	for(i=1,j=0;i<=maxn;i++) {
		if(a[j].first == i) {
			dp[i]=1+dp[max(0,i-a[j].second-1)];
			j++;
		}
		else
			dp[i]=dp[i-1];
		ans=max(ans,dp[i]);
	}
	cout<<n-ans<<endl;
}