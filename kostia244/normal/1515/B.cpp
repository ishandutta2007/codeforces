// Problem: B. Phoenix and Puzzle
// Contest: Codeforces - Codeforces Global Round 14
// URL: https://codeforces.com/contest/1515/problem/B
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
	auto suck = [&](ll x) {
		ll z = round(sqrt(x));
		return (z-1)*(z-1) == x || z*z == x || (z+1)*(z+1) == x;
	};
	multitest([&](){
		int n;
		cin >> n;
		report((n%4 == 0 && suck(n/4)) || (n%2 == 0 && suck(n/2)));
	});
	
}