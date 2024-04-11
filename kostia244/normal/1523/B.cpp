// Problem: B. Lord of the Values
// Contest: Codeforces - Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1523/problem/B
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
		vector<array<int, 3>> ops;
		for(int i = 0; i < n; i+=2) {
			ops.push_back({2, i+1, i+2});
			ops.push_back({1, i+1, i+2});
			ops.push_back({2, i+1, i+2});
			ops.push_back({2, i+1, i+2});
			ops.push_back({1, i+1, i+2});
			ops.push_back({2, i+1, i+2});
		}
		cout << ops.size() << '\n';
		for(auto [x, y, z] : ops) {
			cout << x << " " << y << " " << z << '\n';
			if(x == 1) a[y-1] += a[z-1];
			else a[z-1] -= a[y-1];
		}
		//for(auto i : a) cout << i << ' ';cout<<endl;
	});
	
}
//a b
//a+b b //a b-a
//a+b