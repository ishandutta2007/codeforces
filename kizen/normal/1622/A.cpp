#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int a, b, c; cin >> a >> b >> c;
		int sum = a + b + c;
		if(a * 2 == sum || b * 2 == sum || c * 2 == sum){
			cout << "YES\n";
		}
		else if((a == b && c % 2 == 0) || (b == c && a % 2 == 0) || (a == c && b % 2 == 0)){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}