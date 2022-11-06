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
		cout << 3*n << "\n";
		for(int i = 1; i<=n; i+=2){
			cout << "2 " << i << " " << i+1 << "\n";
			cout << "1 " << i << " " << i+1 << "\n";
			cout << "2 " << i << " " << i+1 << "\n";
			cout << "2 " << i << " " << i+1 << "\n";
			cout << "1 " << i << " " << i+1 << "\n";
			cout << "2 " << i << " " << i+1 << "\n";
		}
	}
	return 0;
}