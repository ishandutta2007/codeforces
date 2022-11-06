#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n);
	for(int i = 0; i<n; i++){
		cin >> arr[i];
	}
	if(n%2==0){
		int total = 0;
		for(int i = 0; i<n; i++){
			total^=arr[i];
		}
		if(total!=0){
			cout << "NO\n";
			return 0;
		}
		cout << "YES\n";
		cout << n-2 << "\n";
		for(int i = 1; i<=n-2; i+=2){
			cout << i << " " << i+1 << " " << n-1 << "\n";
		}
		for(int i = 1; i<=n-2; i+=2){
			cout << i << " " << i+1 << " " << n-1 << "\n";
		}
	}
	else{
		cout << "YES\n";
		cout << n-1 << "\n";
		for(int i = 1; i<=n-1; i+=2){
			cout << i << " " << i+1 << " " << n << "\n";
		}
		for(int i = 1; i<=n-1; i+=2){
			cout << i << " " << i+1 << " " << n << "\n";
		}
	}
	return 0;
}