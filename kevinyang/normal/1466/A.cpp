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
		vector<int>arr(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		set<int>s;
		for(int i = 0; i<n; i++){
			for(int j = i+1; j<n; j++){
				s.insert(arr[j]-arr[i]);
			}
		}
		cout << s.size() << "\n";
	}
	return 0;
}