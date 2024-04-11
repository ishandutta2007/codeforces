// Problem: D. Array Differentiation
// Contest: Codeforces - Codeforces Global Round 15
// URL: https://codeforces.com/contest/1552/problem/D
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
		vector<int> a(n);
		for(auto &i : a) cin >> i;
		int ok = 0;
		for(int tk = 1; tk < 1<<n && !ok; tk++) {
			for(int pos = tk; pos >= 0 && !ok; pos = (pos-1)&tk) {
				int sum = 0;
				for(int i = 0; i < n; i++) if((tk>>i)&1)
					sum += (pos>>i)&1 ? a[i] : -a[i];
				if(sum == 0) ok = 1;
				if(!pos) break;

			}
		}
		report(ok);
	});
	
}