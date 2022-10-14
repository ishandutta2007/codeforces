// Problem:  
// Contest: Codeforces
// URL: https://m1.codeforces.com/contest/1654/problem/B
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
		vector<int> cnt(256);
		for(auto i : s) cnt[i]++;
		int i = 0;
		while(i < s.size()) {
			if(cnt[s[i]]==1) break;
			cnt[s[i]]--;
			i++;
		}
		cout << s.substr(i, s.size()) << '\n';
	});
	
}