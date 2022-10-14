// Problem: B. Groups
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1598/problem/B
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
		vector<array<int, 5>> a(n);
		for(auto &i : a)
			for(auto &j : i) cin >> j;
		int ok = 0;
		for(int x = 0; x < 5; x++) {
			array<int, 5> lo {};
			int los = 0, les = 0;
			lo[x] = -(1<<24);
			for(int i = 0; i < n; i++)
				if(a[i][x] == 0) {
					los++;
					for(int j  =0; j < 5; j++) lo[j] += a[i][j];
				} else les++;
			if(les < n/2) continue;
			for(int i = 0; i < 5; i++) if(lo[i] != los) lo[i] = -(1<<24);
			for(int i = 0; i < n; i++)
				if(a[i][x] == 1) {
					for(int j  =0; j < 5; j++) lo[j] += a[i][j];
				}
			for(int j = 0; j < 5; j++) ok |= lo[j] >= (n/2);
		}
		report(ok);
	});
	
}