#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n);
		int f = 1;
		for(int i = 0; i < n; ++i){
			cin >> a[i];
			if(a[i] != i + 1){
				f = 0;
			}
		}
		if(f){
			cout << "0\n";
		}
		else if(a[0] == 1 || a[n - 1] == n){
			cout << "1\n";
		}
		else if(a[0] != n || a[n - 1] != 1){
			cout << "2\n";
		}
		else{
			cout << "3\n";
		}
	}
	return 0;
}