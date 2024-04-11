// Problem: C. Bottom-Tier Reversals
// Contest: Codeforces - Codeforces Round #740 (Div. 1, based on VK Cup 2021 - Final (Engine))
// URL: https://codeforces.com/contest/1558/problem/C
// Memory Limit: 512 MB
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
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto &i : a) cin >> i;
		for(int i = 0; i < n; i++) {
			if((i%2) == (a[i]%2)) {
				cout << "-1\n";
				return;
			}
		}
		vector<int> ops;
		auto find = [&](int v) {
			int p = 0;
			while(a[p] != v) p++;
			return p;
		};
		auto op = [&](int v) {
			if(v == 0) return;
			assert(v%2 == 0);
			ops.push_back(++v);
			reverse(a.begin(), a.begin()+v);
		};
		for(; n>1; n -= 2) {
			int N = find(n), N1 = find(n-1);
			op(N);
			N1 = find(n-1);
			op(N1-1);
			op(N1+1);
			op(2);
			op(n-1);
		}
		for(int i = 1; i < n; i++) assert(a[i] > a[i-1]);
		cout << ops.size() << '\n';
		for(auto i : ops) cout << i << " "; cout << '\n';
	});
	
}