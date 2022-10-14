// Problem: B. Arrays Sum
// Contest: Codeforces - Grakn Forces 2020
// URL: https://codeforces.com/contest/1408/problem/B
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
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for(auto &i : a) cin >> i;
		int u = 0;
		for(int i = 1; i < n;i++)
			u += !!(a[i]-a[i-1]);
		if(m == 1) cout << (u==0?1:-1) << '\n';
		else cout << max(1,(u+m-2)/(m-1)) << '\n';
	});
	
}