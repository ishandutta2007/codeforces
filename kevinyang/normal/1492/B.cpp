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
		vector<int>arr(n+5);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		vector<pair<int,int>>pre(n+5);
		for(int i = 1; i<=n; i++){
			pre[i] = max(pre[i-1],{arr[i],i});
		}
		int r = n;
		while(r>0){
			pair<int,int>p = pre[r];
			for(int i = p.second; i<=r; i++){
				cout << arr[i] << " ";
			}
			r = p.second-1;
		}
		cout << "\n";
	}
	return 0;
}