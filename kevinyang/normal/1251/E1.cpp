#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<pair<int,int>>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i].first >> arr[i].second;
		}
		sort(arr.begin(),arr.end());
		int total = 0;
		for(int i = 0; i<n; i++){
			total+=arr[i].second;
		}
		int total2 = 0;
		priority_queue<int>q;
		int ind = 0;
		for(int i = 0; i<n; i++){
			while(ind<n&&arr[ind].first==i){
				q.push(arr[ind].second);
				ind++;
			}
			if(q.size()){
				int v = q.top(); q.pop();
				total2+=v;
			}
		}
		cout << total-total2 << "\n";
	}
	return 0;
}