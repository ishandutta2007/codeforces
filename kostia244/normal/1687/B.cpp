// Problem: B. Railway System
// Contest: Codeforces - Codeforces Round #796 (Div. 1)
// URL: https://codeforces.com/contest/1687/problem/B
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
	//multitest([&](){});
	int n, m;
	cin >> n >> m;
	vector<array<int, 2>> W(m);
	for(int i = 0; i < m; i++) {
		string s(m, '0');
		s[i] = '1';
		cout << "? " << s << endl;
		cin >> W[i][0];
		W[i][1] = i;
	}
	string cur(m, '0');
	sort(all(W));
	int lst = 0, tmp;
	for(auto [w, id] : W) {
		cur[id] = '1';
		cout << "? " << cur << endl;
		cin >> tmp;
		if(tmp == lst + w)
			lst = tmp;
		else 
			cur[id] = '0';
	}
	cout << "! " << lst << endl;
}