// Problem: E. Forensic Examination
// Contest: Codeforces - Codeforces Round #349 (Div. 1)
// URL: https://codeforces.com/contest/666/problem/E
// Memory Limit: 768 MB
// Time Limit: 6000 ms
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
	string s;
	cin >> s;
	s = s.substr(5, s.size());
	set<string> suf;
	vector<array<int, 2>> can(s.size()+1);
	int n = s.size();
	can[s.size()] = {1, 1};
	for(int end = (int)s.size()-1; end >= 0; end--) {
		can[end] = {0, 0};
		if(end+1<n) {
			string t = s.substr(end, 2);
			int oof = 0;
			if(end+3<n)
				oof = t != s.substr(end+2, 2) && can[end+2][0];
			can[end][0] = can[end+2][1] | oof;
		}
		if(end+2< s.size()) {
			string t = s.substr(end, 3);
			int oof = 0;
			if(end+5<n)
				oof = t != s.substr(end+3, 3) && can[end+3][1];
			can[end][1] = can[end+3][0] | oof;
		}
		if(can[end][0]) suf.insert(s.substr(end, 2));
		if(can[end][1]) suf.insert(s.substr(end, 3));
	}
	cout << suf.size() << '\n';
	for(auto i : suf) cout << i << '\n';
}