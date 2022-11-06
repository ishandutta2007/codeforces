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
		for(int i = 2; i<=n; i++){
			cout << i << " ";
		}
		cout << 1 << "\n";
	}
	return 0;
}