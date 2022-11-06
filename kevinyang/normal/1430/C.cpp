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
		if(n==2){
			cout << "2\n";
			cout << "1 2\n";
			continue;
		}
		cout << "2\n";
		cout << n << " " << n-2 << "\n";
		cout << n-1 << " " << n-1 << "\n";
		for(int i = n-1; i>2; i--){
			cout << i << " " << i-2 << "\n";
		}
	}
	return 0;
}