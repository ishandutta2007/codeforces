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
		
		int num = (n+3)/4;
		for(int i = 0; i<n-num; i++){
			cout << 9;
		}
		for(int i = 0; i<num; i++){
			cout << 8;
		}
		cout << "\n";
	}
	return 0;
}