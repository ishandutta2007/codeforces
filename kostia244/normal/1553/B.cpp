// Problem: B.  
// Contest: Codeforces - Harbour.Space Scholarship Contest 2021-2022 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1553/problem/B
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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		string s, t;
		cin >> s>> t;
		int pos = 0;
		for(int i = 0; i < s.size(); i++) {
			pos = 0;
			for(int j = i; pos < t.size() && j < s.size(); j++) {
				if(t[pos] == s[j]) pos++;
				else pos = 1<<30;
				int p2 = pos;
				for(int k = j-1; p2 < t.size() && k >= 0; k--) {
					if(t[p2] == s[k]) p2++;
					else p2 = 1<<30;
				}
				if(p2 == t.size()) pos = t.size();
			}
			if(pos == t.size()) break;
		}
		report(pos==t.size());
	});
	
}