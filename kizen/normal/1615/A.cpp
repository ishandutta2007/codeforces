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
		int n; cin >> n;
		vector<int> a(n);
		int sum = 0;
		for(int i = 0; i < n; ++i){
			cin >> a[i];
			sum += a[i];
		}
		if(sum % n == 0) cout << "0\n";
		else cout << "1\n";
	}
	return 0;
}