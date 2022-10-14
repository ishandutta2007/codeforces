// Problem: B. Almost Rectangle
// Contest: Codeforces - Codeforces Round #713 (Div. 3)
// URL: https://codeforces.com/contest/1512/problem/B
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
		vector<int> a, b;
		int n;
		cin >> n;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				char c;cin >> c;
				if(c=='*') {
					a.push_back(i);b.push_back(j);
				}
			}
		}
		if(a[0]==a[1])a[1]=(a[0]==0);
		if(b[0]==b[1])b[1]=(b[0]==0);
		for(int i = 0; i < n; i++, cout << '\n')
			for(int j = 0; j < n; j++) {
				cout << ((a[0]==i||a[1]==i)&&(b[0]==j||b[1]==j) ? '*' : '.');
			}
	});
	
}