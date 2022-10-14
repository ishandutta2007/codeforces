// Problem: D. Max Median
// Contest: Codeforces - Codeforces Round #703 (Div. 2)
// URL: https://codeforces.com/contest/1486/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
const int maxn = 1<<19;
int n, k, a[maxn];
bool can(int v) {
	vector<int> pr {0};
	for(int i = 1; i <= n; i++) {
		pr.push_back(pr.back() + (a[i]<v?-1:1));
	}
	//for(auto i : pr) cout << i << " "; cout << endl;
	int mn = 0;
	for(int i = k; i <= n; i++) {
		mn = max(mn, -pr[i-k]);
		//cout << pr[i]-pr[i-k] << " " << pr[i]+mn << endl;
		if(pr[i]+mn > 0) return 1;
	}
	return 0;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	for(int z = maxn; z/=2;) {
		ans += z*can(ans+z);
	}
	cout << ans << '\n';
}