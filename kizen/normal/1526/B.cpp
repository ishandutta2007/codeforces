#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int x; cin >> x;
		int val = x % 11;
		if(x / 111 >= val){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}