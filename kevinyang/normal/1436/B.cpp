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
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				if((i+j)%n<=1)cout << "1 ";
				else cout << "0 ";
			}
			cout << "\n";
		}
	}
	return 0;
}