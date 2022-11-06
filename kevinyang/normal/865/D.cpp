#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	priority_queue<int,vector<int>,greater<int>>pq;
	int ans = 0;
	for(int i = 1; i<=n; i++){
		pq.push(arr[i]);
		pq.push(arr[i]);
		ans+=arr[i]-pq.top();
		pq.pop();
	}
	cout << ans << "\n";
	return 0;
}