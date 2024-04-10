#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		cout << n - 1 << '\n';
		int last = (int)1e9 + 7;
		int lv = 1;
		for(int i = 0; i < n - 1; ++i){
			int x = min(a[i], a[i + 1]);
			if(i == n - 2){
				while(__gcd(x, last + 1) != 1 || __gcd(last + 1, lv) != 1) ++last;
			}
			cout << i + 2 << ' ' << i + 1 << ' ' << x << ' ' << last + 1 << '\n';
			a[i] = ++last, a[i + 1] = x;
			lv = a[i];
		}
	}
	return 0;
}