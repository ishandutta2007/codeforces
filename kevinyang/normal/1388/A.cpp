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
		if(n<=30){
			cout << "NO\n";
		}
		if(n>30){
			//6 10 14 15
			cout << "YES\n";
			if(n==36||n==40||n==44){
				cout << "6 10 15 " << n-31 << "\n";
			}
			else{
				cout << "6 10 14 " << n-30 << "\n";
			}
		}
	}
	return 0;
}