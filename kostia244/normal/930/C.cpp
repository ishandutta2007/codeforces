#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<20, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, a[maxn], v[maxn];
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int l, r, i = 0; i < n; i++) {
		cin >> l >> r;
		a[l]++, a[r+1]--;
	}
	for(int i = 1; i <= m; i++) a[i] += a[i-1];
	vector<int> ans;
	for(int i = 1; i <= m; i++) {
		auto it = upper_bound(all(ans), a[i]);
		if(it == ans.end()) ans.push_back(a[i]);
		else *it = a[i];
		v[i] = upper_bound(all(ans), a[i])-ans.begin();
	}
	ans.clear();
	for(int i = m; i; i--) {
		auto it = upper_bound(all(ans), a[i]);
		if(it == ans.end()) ans.push_back(a[i]);
		else *it = a[i];
		v[i] += upper_bound(all(ans), a[i])-ans.begin();
	}
	int res = 0;
	for(int i = 1; i <= m; i++) res = max(res, v[i]-1);
	cout << res << endl;
}