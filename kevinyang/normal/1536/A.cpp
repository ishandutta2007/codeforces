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
		bool f = true;
		for(int i = 0; i<n; i++){
			cin >> arr[i];
			if(arr[i]<0)f = false;
		}
		if(f){
			cout << "Yes\n";
			cout << "101\n";
			for(int i = 0; i<=100; i++){
				cout << i << " ";
			}
			cout << "\n";
		}
		else{
			cout << "No\n";
		}
	}
	return 0;
}