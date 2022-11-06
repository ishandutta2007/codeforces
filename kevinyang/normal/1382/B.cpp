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
		for(int i = 0; i<n; i++){
			if(arr[i]!=1){
				f = false;
			}
		}
		if(f){
			if(n%2==1){
				cout << "First\n";
			}
			else{
				cout << "Second\n";
			}
			continue;
		}
		int count = 0;
		for(int i = 0; i<n; i++){
			if(arr[i]==1)count++;
			else break;
		}
		if(count%2==0)cout << "First\n";
		else cout << "Second\n";
	}
	return 0;
}