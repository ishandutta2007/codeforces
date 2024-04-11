// Problem: E. Colors and Intervals
// Contest: Codeforces - Codeforces Global Round 15
// URL: https://codeforces.com/contest/1552/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	int n, k;
	cin >> n >> k;
	vector<int> a(n*k);
	for(auto &i : a) cin >> i;
	int match = 0;
	vector<int> f(n+1);
	vector<array<int, 2>> seg(n+1);
	seg[0][0] = -1;
	while(match < n) {
		vector<int> lst(n+1, -1);
		int eat = -1;
		for(int i = 0; i < n*k; i++) {
			if(!f[a[i]] && lst[a[i]] > eat) {
				seg[a[i]] = {lst[a[i]], i};
				//cout << lst[a[i]] << " to " << i << endl;
				f[a[i]] = 1;
				eat = i;
				match++;
			}
			lst[a[i]] = i;
		}
	}
	for(auto [l, r] : seg) if(l != -1) cout << l+1 << " " << r+1 << "\n";
}