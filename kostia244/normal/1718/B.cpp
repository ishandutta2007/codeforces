// Problem: B. Fibonacci Strings
// Contest: Codeforces - Codeforces Round #814 (Div. 1)
// URL: https://codeforces.com/contest/1718/problem/B
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
	const int C = 60;
	vector<ll> fib{1, 1};
	for(int i = 0; i+2 < C; i++)
		fib.push_back(end(fib)[-1] + end(fib)[-2]);
	assert(fib.back() > 2e11);
	multitest([&](){
		int n;
		cin >> n;
		vector<ll> a(n);
		for(auto &i : a) cin >> i;
		vector<int> c(fib.size());
		auto upd = [&](ll t, int val, int bad) {
			for(int j = fib.size(); j-- > bad;)
				if(t >= fib[j])
					t -= fib[j], c[j] += val;
			return t;
		};
		auto check = [&]() {
			int ok = 1, pos = 1;
			while(pos < fib.size() && c[pos])
				pos++;
			for(int i = 1; i < fib.size(); i++)
				ok &= c[i] == (i < pos);
			return ok;
		};
		int ok = 0;
		for(int i = 0; i < n; i++)
			upd(a[i], 1, 0);
		for(int i = 0; i < n; i++) {
			upd(a[i], -1, 0);
			ll bad = upd(a[i]-1, 1, 2);
			ok |= !bad && check();
			upd(a[i]-1, -1, 2);
			upd(a[i], 1, 0);
		}
		report(ok);
	});
}