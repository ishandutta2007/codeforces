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
		for(int i = 2*n+2; i<=4*n; i+=2){
			cout << i << " ";
		}
		cout << "\n";
	}
	return 0;
}