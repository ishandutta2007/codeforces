// Problem: D. Cyclic Rotation
// Contest: Codeforces - Codeforces Global Round 20
// URL: https://codeforces.com/contest/1672/problem/D
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
		vector<int> a(n), b(n);
		for(auto &i : a) cin >> i;
		for(auto &i : b) cin >> i;
		map<int, int> stuck;
		int i = 0, cnt = 1;
		for(auto v : b) {
			while((a[i] != v || !cnt)) {
				stuck[a[i]] = cnt;
				if(++i == n)  {
					cout << "NO\n";
					return;
				}
				cnt = 1+stuck[a[i]];
			}
			if(--cnt < 0) {
				cout << "NO\n";
				return;
			}
		}
		cout << "YES\n";
	});
	
}