// Problem: C. Dominant Character
// Contest: Codeforces - Codeforces Round #754 (Div. 2)
// URL: https://codeforces.com/contest/1605/problem/C
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
		int ans = 69;
		for(int i = 0; i < n; i++) {
			vector<int> c(3);
			for(int j = i; j < min(n, i+10); j++) {
				c[s[j]-'a']++;
				if(j>i && max(c[1], c[2])<c[0])
					ans = min(ans, j-i+1);
			}
		}
		if(ans == 69) ans = -1;
		cout << ans << '\n';
		
	});
	
}