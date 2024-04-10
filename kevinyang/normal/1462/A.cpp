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
		for(int i = 0; i<n; i++){
			if(i%2==0){
				cout << arr[i/2] << " ";
			}
			else{
				cout << arr[n-1-i/2] << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}