#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int q; cin >> q; while(q--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for(int i = 0;i < n;i++) {
			cin >> a[i];
		}
		sort(a.begin(),a.end());
		if(a[0] + k < a[n - 1] - k) {
			cout << -1 << endl;
		}
		else {
			cout << a[0] + k << endl;
		}
		
	}
}