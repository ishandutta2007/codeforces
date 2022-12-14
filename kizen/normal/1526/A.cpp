#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n; n *= 2;
		vector<int> a(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		for(int i = 0; i < n / 2; ++i){
			cout << a[i] << ' ' << a[i + n / 2] << ' ';
 		}
 		cout << '\n';
	}
	return 0;
}