#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	priority_queue<int> pq;
	int ans = 0, sum = 0;
	for(int i = 0; i < n; ++i){
		sum += a[i];
		if(a[i] < 0){
			pq.push(-a[i]);
		}
		++ans;
		if(sum < 0){
			--ans;
			sum += pq.top(); pq.pop();
		}
	}
	cout << ans;
	return 0;
}