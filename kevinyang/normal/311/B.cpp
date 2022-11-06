#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,p;
vector<int>a(100005);
vector<int>psa(100005);
vector<int>dp(100005);
vector<int>dp2(100005);
double intersect(int a, int b){
	return -1*(double)(dp[a]+psa[a]-dp[b]-psa[b])/(double)(-a+b);
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m >> p;
	vector<int>d(n+1);
	for(int i = 2; i<=n; i++){
		cin >> d[i];
		d[i]+=d[i-1];
	}
	vector<int>arr(m);
	for(int i = 0; i<m; i++){
		int h,t;
		cin >> h >> t;
		t-=d[h];
		arr[i] = t;
	}
	sort(arr.begin(),arr.end());
	for(int i = 0; i<m; i++){
		a[i+1] = arr[i];
	}
	for(int i = 1; i<=m; i++){
		psa[i] = a[i]+psa[i-1];
	}
	for(int i = 1; i<=m; i++){
		dp[i] = i*a[i]-psa[i];
	}
	for(int t = 2; t<=p; t++){
		deque<int>dq;
		dq.push_back(1);
		for(int i = 2; i<=m; i++){
			while(dq.size()>=2&&intersect(dq[0],dq[1])<a[i]){
				dq.pop_front();
			}
			dp2[i] = dp[dq[0]] + (i-dq[0])*a[i] - psa[i]+psa[dq[0]];
			while(dq.size()>=2&&intersect(dq[dq.size()-2],i)<intersect(dq[dq.size()-2],dq[dq.size()-1])){
				dq.pop_back();
			}
			dq.push_back(i);
		}
		for(int i = 1; i<=m; i++){
			dp[i] = dp2[i];
		}
	}
	cout << dp[m] << "\n";
	return 0;
}