#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,z;
		cin >> n >> z;
		int mx = 0;
		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
			mx = max(mx,z|x);
		}
		cout << mx << "\n";
	}
	return 0;
}