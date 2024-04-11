// Problem: B. Reverse Sort
// Contest: Codeforces - Codeforces Round #754 (Div. 2)
// URL: https://codeforces.com/contest/1605/problem/B
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
		int n;
		string s;
		cin >> n >> s;
		int ze = count(all(s), '0'); 
		vector<int> ans {};
		for(int i = 0; i < n; i++) {
			if(i < ze && s[i] == '1') 
				ans.push_back(i);
			else if(i >= ze && s[i] == '0')
				ans.push_back(i);
		}
		if(ans.empty()) cout << "0\n";
		else {
			cout << "1\n" << ans.size() << " ";
			for(auto i : ans) cout << 1+i << " ";cout << '\n';
		}
	});
	
}