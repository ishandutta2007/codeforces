// Problem: B. Take Your Places!
// Contest: Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1556/problem/B
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
		vector<vector<int>> c(2);
		for(auto &i : a) cin >> i, i %= 2;
		for(int i = 0; i < n; i++)
			c[a[i]].push_back(i);
		if(c[0].size() == c[1].size()) {
			ll A = 0, B = 0;
			for(int i = 0; i < c[0].size(); i++)
				A += abs(2*i-c[0][i]), B += abs(2*i+1-c[0][i]);
			cout << min(A, B) << '\n';
		} else if(abs(int(c[0].size())-(int)c[1].size())<2) {
			ll A = 0;
			if(c[0].size() < c[1].size()) swap(c[0], c[1]);
			for(int i = 0; i < c[0].size(); i++)
				A += abs(2*i-c[0][i]);
			cout << A << '\n';
		} else cout << "-1\n";
	});
	
}