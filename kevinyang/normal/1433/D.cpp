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
		bool f = true;
		for(int i = 1; i<n; i++){
			if(arr[i]!=arr[0])f = false;
		}
		if(f){
			cout << "NO\n";
			continue;
		}
		int ind = 0;
		for(int i = 1; i<n; i++){
			if(arr[i]!=arr[0]){
				ind = i;
				break;
			}
		}
		cout << "YES\n";
		cout << 1 << " " << ind+1 << "\n";
		for(int i = 1; i<n; i++){
			if(i==ind)continue;
			if(arr[i]==arr[0]){
				cout << i+1 << " " << ind+1 << "\n";
			}
			else{
				cout << 1 << " " << i+1 << "\n";
			}
		}
	}
	return 0;
}