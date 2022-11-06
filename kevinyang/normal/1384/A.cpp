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
		vector<char>arr2(100);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		for(int i = 0; i<100; i++){
			arr2[i] = 'a';
			cout << "a";
		}
		cout << "\n";
		for(int i = 0; i<n; i++){
			if(arr2[arr[i]]=='a'){
				arr2[arr[i]] = 'b';
			}
			else{
				arr2[arr[i]] = 'a';
			}
			for(int j = 0; j<100; j++){
				cout << arr2[j];
			}
			cout << "\n";
		}
	}
	return 0;
}