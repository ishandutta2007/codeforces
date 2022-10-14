// Problem: D. Double Strings
// Contest: Codeforces - Codeforces Round #806 (Div. 4)
// URL: https://codeforces.com/contest/1703/problem/D
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
		map<string, int> a;
		int n;
		cin >> n;
		vector<string> s(n);
		for(auto &i : s) { 
		cin >> i;
		a[i]++;
		}
		for(auto &i : s) {
			int ok = 0;
			a[i]--;
			for(int x = 1; x <= i.size(); x++) {
				if(a[i.substr(0, x)] && a[i.substr(x, i.size())])
					ok = 1;
			}
			a[i]++;
			cout << ok;
		}
		cout << '\n';
	});
	
}