// Problem: C. New Year Book Reading
// Contest: Codeforces - Good Bye 2014
// URL: https://codeforces.com/contest/500/problem/C
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
	//multitest([&](){});
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for(auto &i : a) cin >> i;
	for(auto &j : b) cin >> j;
	ll ans = 0;
	for(int i = 0; i < m; i++) {
		bitset<569> used = 0;
		for(int j = i-1; j >= 0 && b[j] != b[i]; j--) {
			if(!used[b[j]]) {
				used[b[j]] = 1;
				ans += a[b[j]-1];
			}
		}
	}
	cout << ans << '\n';
}