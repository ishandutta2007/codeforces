// Problem: B. Running for Gold
// Contest: Codeforces - Codeforces Global Round 15
// URL: https://codeforces.com/contest/1552/problem/B
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
	multitest([&](){
		int n;
		cin >> n;
		vector<array<int, 6>> a(n);
		int pos = 0;
		for(auto &i : a) {for(int j = 0; j < 5; j++) cin >> i[j];i[5] = pos++;}
		auto cmp = [](array<int, 6> a, array<int, 6> b) -> bool {
			int val = 0;
			for(int i = 0; i < 5; i++) val += a[i] > b[i] ? 1 : -1;
			return val > 0;
		};
		sort(all(a), cmp);
		int ok = 1;
		for(int i = 0; i+1 < n; i++) ok &= cmp(a[i], a.back());
		if(!ok) a.back()[5] = -2;
		cout << 1+a.back()[5] << '\n';
	});
	
}