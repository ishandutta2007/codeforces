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
		sort(arr.begin(),arr.end());
		int a = 0; int b = 0;
		reverse(arr.begin(),arr.end());
		for(int i = 0; i<n; i++){
			if(i%2==0){
				if(arr[i]%2==0)a+=arr[i];
			}
			else{
				if(arr[i]%2)b+=arr[i];
			}
		}
		if(a==b){
			cout << "Tie\n";
		}
		else if(a>b){
			cout << "Alice\n";
		}
		else{
			cout << "Bob\n";
		}
	}
	return 0;
}