#include <bits/stdc++.h>
using namespace std;
#define int long long
bool comp(int a, int b){
	return a%2 < b%2;
}
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
		sort(arr.begin(),arr.end(),comp);
		for(int i = 0; i<n; i++){
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}