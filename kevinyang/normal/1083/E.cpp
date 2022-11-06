#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<int>x(1000005);
vector<int>y(1000005);
vector<int>a(1000005);
vector<int>dp(1000005);
#define double long double
double intersect(int a, int b){
	return -1*(double)(dp[a]-dp[b])/((double)-x[a]+x[b]);
}
bool comp(pair<int,pair<int,int>>a, pair<int,pair<int,int>>b){
	return a.first<b.first;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	vector<pair<int,pair<int,int>>>arr(n);
	for(int i = 0; i<n; i++){
		cin >> arr[i].first >> arr[i].second.first >> arr[i].second.second;
	}
	sort(arr.begin(),arr.end(),comp);
	for(int i = 1; i<=n; i++){
		x[i] = arr[i-1].first; y[i] = arr[i-1].second.first; a[i] = arr[i-1].second.second;
	}
	deque<int>dq;
	dp[1] = x[1]*y[1]-a[1];
	dq.push_back(1);
	for(int i = 2; i<=n; i++){
		while(dq.size()>=2&&intersect(dq[0],dq[1])>y[i]){
			dq.pop_front();
		}
		dp[i] = dp[dq[0]]-x[dq[0]]*y[i] + x[i]*y[i]-a[i];
		dp[i] = max(dp[i],x[i]*y[i]-a[i]);
		while(dq.size()>=2&&intersect(dq[dq.size()-2],i)>intersect(dq[dq.size()-2],dq[dq.size()-1])){
			dq.pop_back();
		}
		dq.push_back(i);
	}
	int ans = 0;
	for(int i = 1; i<=n; i++){
		ans = max(ans,dp[i]);
	}
	cout << ans << "\n";
	return 0;
}