// Problem: B. I love AAAB
// Contest: Codeforces - Codeforces Global Round 20
// URL: https://codeforces.com/contest/1672/problem/B
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
		string A;
		cin >> A;
		int bal = 0, ok = A.back()=='B';
		for(auto i : A) {
			bal += i == 'A' ? 1 : -1;
			ok &= bal >= 0;
		}
		report(ok);
	});
	
}