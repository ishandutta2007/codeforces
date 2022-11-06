#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<int>arr(n+1);
	vector<int>arr2(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	for(int i = 1; i<=n; i++){
		cin >> arr2[i];
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	vector<int>bad(n+1);
	int ans = 0;
	for(int i = 1; i<=n; i++){
		m-=(arr[i]%100);
		if(arr[i]%100)pq.push({arr2[i]*(100-(arr[i]%100)),i});
		if(m<0){
			m+=100;
			auto p = pq.top(); pq.pop();
			ans+=p.first;
			bad[p.second] = true;
		}
	}
	cout << ans << "\n";
	for(int i = 1; i<=n; i++){
		if(bad[i]){
			cout << (arr[i]+99)/100 << " 0\n";
		}
		else{
			cout << arr[i]/100 << " " << arr[i]%100 << "\n";
		}
	}
	return 0;
}