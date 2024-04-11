// Problem: D. Maximum AND
// Contest: Codeforces - Educational Codeforces Round 134 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1721/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
		vector<int> a(n), b(n);
		for(auto &i : a) cin >> i;
		for(auto &i : b) cin >> i;
		auto check = [&](int msk) {
			map<int,int>cnt;
			for(auto i : a) cnt[i & msk]++;
			for(auto i : b) cnt[(i & msk)^msk]--;
			for(auto [x,y]: cnt) if(y) return 0;
			return 1;
		};
		int msk = 0;
		for(int z = 1<<30; z>>=1;)
			msk |= z * check(msk|z);
		cout << msk << '\n';
	});
	
}