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
		vector<int>arr2(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
			cin >> arr2[i];
		}
		sort(arr.begin(),arr.end());
		sort(arr2.begin(),arr2.end());
		if(n%2==1){
			cout << "1\n";
		}
		else{
			cout << (arr[n/2]-arr[n/2-1]+1)*(arr2[n/2]-arr2[n/2-1]+1) << "\n";
		}
	}
	return 0;
}