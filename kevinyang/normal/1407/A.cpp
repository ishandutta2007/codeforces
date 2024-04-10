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
		int zeroes = 0; int ones = 0;
		for(int i = 0; i<n; i++){
			if(arr[i]==0)zeroes++;
			else ones++;
		}
		if(zeroes>=n/2){
			cout << n/2 << "\n";
			for(int i = 0; i<n/2; i++){
				cout << 0 << " ";
			}
		}
		else{
			int a = n/2;
			if(a%2==1)a++;
			cout << a << "\n";
			for(int i = 0; i<a; i++){
				cout << 1 << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}