// Problem: B. Hemose Shopping
// Contest: Codeforces - Codeforces Round #746 (Div. 2)
// URL: https://codeforces.com/contest/1592/problem/B
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
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		for(auto &i : a) cin >> i;
		x = n-x;
		vector<int> u;
		for(int i = 0; i < n; i++)
			if(i < x || (n-i-1) < x)
				u.push_back(a[i]);
		sort(all(u));
		if(u.size() == n) a = u;
		else 
			for(int i = 0; i < 2*x; i++)
				a[i < x ? i : (n-x+i-x)] = u[i];
		int ok = 1;
		for(int i = 1; i < n; i++) ok &= a[i-1] <= a[i];
		report(ok);
		
	});
	
}