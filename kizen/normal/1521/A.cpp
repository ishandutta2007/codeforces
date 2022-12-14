#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int a, b; cin >> a >> b;
		if(b == 1){
			cout << "NO\n";
		}
		else if(b == 2){
			cout << "YES\n";
			cout << a << ' ' << a * 3 << ' ' << a * 4 << '\n';
		}
		else{
			cout << "YES\n";
			cout << a * (b - 1) << ' ' << a << ' ' << a * b << '\n';
		}
	}
	return 0;
}