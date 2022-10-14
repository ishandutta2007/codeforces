#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
const int maxn = 1<<20;
map<int, vector<array<int, 2>>> segs;
int n, m;
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	vector<int> v(n), mex;
	for(auto &i : v) cin >> i;
	for(int x, l, r, i = 0; i < m; i++) {
		cin >> l >> r >> x;
		if(l == 1) mex.push_back(r);
	}
	v.push_back(1e9);
	sort(all(v));
	sort(all(mex));
	int ans = 1<<30;
	for(int i = 0; i < v.size(); i++) {
		ans = min(ans, i + int(mex.end() - lower_bound(all(mex), v[i])));
	}
	cout << ans << '\n';
}