// Problem: B. Range and Partition
// Contest: Codeforces - Codeforces Round #768 (Div. 1)
// URL: https://codeforces.com/contest/1630/problem/B
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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		int n, k;
		cin >> n >> k;
		int sum = -n, K = 0;
		while(sum < k) sum += 2, K += 1;
		vector<int> a(n);
		for(auto &i : a) cin >> i;
		auto b = a;
		sort(all(b));
		array<int, 2> ans  = {1<<30, 0};
		for(int i = 0; i+K-1 < n; i++) {
			ans = min(ans, {b[i+K-1]-b[i], b[i]});
		}
		ans[0] += ans[1];
		swap(ans[0], ans[1]);
		cout << ans[0] << " " << ans[1] << '\n';
		int l = 0, c = 0;
		for(int i = 0; i < n; i++) {
			c += ans[0] <= a[i] && a[i] <= ans[1] ? 1 : -1;
			if(c>0 && (i+1 == n || k > 1)) {
				cout << l+1 << " " << i+1 << '\n';
				l = i+1;
				c = 0;
				k--;
			}
		}
	});
	
}