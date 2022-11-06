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
		for(int i = 0; i<n; i++)
			cin >> arr[i];
		if(n==1)cout << "1\n";
		else{
			bool f = true;
			int cur = arr[0];
			for(int i = 1; i<n; i++){
				if(cur!=arr[i])f = false;
			}
			if(f){
				cout << n << "\n";
			}
			else{
				cout << 1 << "\n";
			}
		}
	}
	return 0;
}