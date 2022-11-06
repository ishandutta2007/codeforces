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
		bool one = false;
		int sum = 0;
		for(int i = 0; i<n; i++){
			cin >> arr[i];
			sum+=arr[i];
			if(arr[i]==1)one = true;
		}
		if(sum%2==0){
			if(sum%4==2){
				if(one){
					cout << "Yes\n";
				}
				else{
					cout << "No\n";
				}
			}
			else{
				cout << "Yes\n";
			}
		}
		else{
			cout << "No\n";
		}
	}
	return 0;
}