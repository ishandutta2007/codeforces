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
		sort(arr.begin(),arr.end());
		for(int i = 1; i<n; i++){
			if(arr[i]<=arr[i-1]){
				arr[i]++;
			}
		}
		set<int>s;
		for(int i = 0; i<n; i++){
			s.insert(arr[i]);
		}
		cout << s.size() << "\n";
	}
	return 0;
}