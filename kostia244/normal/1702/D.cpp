// Problem: D. Not a Cheap String
// Contest: Codeforces - Codeforces Round #805 (Div. 3)
// URL: https://codeforces.com/contest/1702/problem/D
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
	multitest([&](){
		string s;
		cin >> s;
		int k;cin >> k;
		vector<vector<int>> c(26);
		vector<int> die(s.size());
		ll cost = 0;
		for(int i = 0; i < s.size(); i++) {
			c[s[i]-'a'].push_back(i);
			cost += s[i] - 'a' + 1;
		}
		for(int z = 26; z--;) {
			for(auto i : c[z]) {
				if(cost > k) die[i] = 1, cost -= z+1;
				else break;
			}
		}
		for(int i = 0; i < s.size(); i++) if(!die[i]) cout << s[i];cout << '\n';
	});
	
}