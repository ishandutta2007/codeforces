// Problem: F. Two Different
// Contest: Codeforces - Grakn Forces 2020
// URL: https://codeforces.com/contest/1408/problem/F
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
vector<array<int, 2>> ans;
void add(int x, int y) {
	ans.push_back({x, y});
}
void solve(int n, int s) {
	if(n == 4) {
		add(s, s+1);
		add(s+2, s+3);
		add(s, s+2);
		add(s+1, s+3);
		return;
	}
	int z = n/2;
	solve(z, s);
	solve(z, s+z);
	for(int i = 0; i < z; i++)
		add(s+i, s+z+i);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n;
	cin >> n;
	if(n < 3) {
		cout << "0\n";
		return 0;
	}
	if(n == 3) {
		cout << "1\n1 2\n";
		return 0;
	}
	int m = 1;
	while(2*m <= n) m *= 2;
	solve(m, 1);
	solve(m, n-m+1);
	cout << ans.size() << '\n';
	for(auto [x, y] : ans)
		cout << x << " " << y << '\n';
}