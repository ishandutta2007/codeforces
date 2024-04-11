#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using ll = long long;
#define int ll
using namespace std;
const int maxn = 1<<19;
const int inf = 1e18;
int32_t main() {
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto &i : a) cin >> i;
		set<int> b(all(a));
		if(b.size() == 1) {cout << "NO\n";continue;}
		int l = 0;
		while(a[l] == a[0]) l++;
		cout << "YES\n";
		for(int i = 1; i < n; i++) if(a[i] == a[0]) cout << i+1 << " " << l+1 << '\n'; else cout << 1 << " " << i+1 << '\n';
	}
	return 0;
}