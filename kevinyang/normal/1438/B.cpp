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
		bool f = false;
		for(int i = 0; i<n; i++){
			for(int j = i+1; j<n; j++){
				if(arr[i]==arr[j])f = true;
			}
		}
		cout << (f?"YES\n":"NO\n");
	}
	return 0;
}