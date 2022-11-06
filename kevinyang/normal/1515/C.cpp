#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m,x;
		cin >> n >> m >> x;
		vector<int>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
		for(int i = 0; i<m; i++){
			q.push({0,i});
		}
		vector<int>ans(n);
		for(int i = 0; i<n; i++){
			pair<int,int>p = q.top(); q.pop();
			p.first+=arr[i];
			ans[i] = p.second;
			q.push(p);
		}
		cout << "YES\n";
		for(int i = 0; i<n; i++){
			cout << ans[i]+1 << " ";
		}
		cout << "\n";
	}
	return 0;
}