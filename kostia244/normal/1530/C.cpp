// Problem: C. Pursuit
// Contest: Codeforces - Codeforces Round #733 (Div. 1 + Div. 2, based on VK Cup 2021 - Elimination (Engine))
// URL: https://codeforces.com/contest/1530/problem/C
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
		cin >>n ;
		vector<int> a(n), b(n);
		for(auto &i : a) cin >> i;
		for(auto &i : b) cin >> i;
		sort(all(a), greater<>());
		sort(all(b), greater<>());
		auto check = [&](int k) {
			int s = n+k;
			s -= s/4;
			int t = min(s, k);
			int il = 0;
			for(int i = 0; i < min(n, s); i++)
				il += b[i];
			int me = t*100;
			s -= t;
			for(int i = 0; i < s; i++) {
				me += a[i];
			}
			if(0 && k ==2)
				cout << me << " " << il << " " << t << endl;
			return me >= il;
		};
		int x = -1;
		for(int z = 1<<22; z>>=1;)
			x += z*!check(x+z);
		cout << ++x << '\n';
	});
	
}