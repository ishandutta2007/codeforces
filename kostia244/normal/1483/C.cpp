// Problem: C. Skyline Photo
// Contest: Codeforces - Codeforces Round #709 (Div. 1, based on Technocup 2021 Final Round)
// URL: https://codeforces.com/contest/1483/problem/C
// Memory Limit: 256 MB
// Time Limit: 2500 ms
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
	int n;
	cin >> n;
	vector<ll> h(n), c(n);
	for(auto &i : h) cin >> i;
	for(auto &i : c) cin >> i;
	vector<ll> dp(n);
	multiset<ll> opts;
	vector<array<ll, 2>> st;
	st.push_back({0, 0});
	opts.insert(c[0]);
	dp[0] = c[0];
	for(int i = 1; i < n; i++) {
		ll cur = dp[i-1];
		while(st.size() && h[st.back()[0]] > h[i]) {
			cur = max(cur, st.back()[1]);
			opts.erase(opts.find(c[st.back()[0]]+st.back()[1]));
			st.pop_back();
		}
		st.push_back({i, cur});
		opts.insert(cur+c[i]);
		dp[i] = *opts.rbegin();
	}
	cout << dp.back() << '\n';
}