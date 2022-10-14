#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
set<int> f;
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	for(int a, i = 0; i < n; i++) {
		a = 0;
		for(int t, j = 0; j < k; j++)
			cin >> t, a += t<<j;
		f.insert(a);
	}
	for(auto &i : f)
		for(auto &j : f) if((i&j) == 0) return cout << "YES\n", 0;
	cout << "NO\n";
}