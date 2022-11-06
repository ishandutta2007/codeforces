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
		vector<int>ind(101);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
			ind[arr[i]] = i+1;
		}
		sort(arr.begin(),arr.end());
		if(arr[0]<arr[1])cout << ind[arr[0]] << "\n";
		else cout << ind[arr[n-1]] << "\n";
	}
	return 0;
}