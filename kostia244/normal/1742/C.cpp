// Problem: 
// Contest: Codeforces
// URL: https://m2.codeforces.com/contest/1742/problem/C
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
		vector<int> row(8), col(8);
		for(int i = 0; i < 8; i++)
			for(int j = 0; j < 8; j++) {
				char c; cin >> c;
				if(c == 'R') col[i]++;
				if(c == 'B') row[j]++;
			}
		if(*max_element(all(row)) == 8) cout << "B";
		else cout << "R";
		cout << '\n';
	});
	
}