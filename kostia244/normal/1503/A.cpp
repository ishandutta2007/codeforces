// Problem: A. Balance the Bits
// Contest: Codeforces - Codeforces Round #712 (Div. 1)
// URL: https://codeforces.com/contest/1503/problem/A
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
		int n;
		string s, a, b ;
		cin >> n >> s;
		if(s[0] == '0' || s.back() == '0') return cout << "NO\n", 0;
		if(count(all(s), '0')%2) return cout << "NO\n", 0;
		int x = 0, y = 1;
		for(auto i : s) {
			if(i == '0') {
				if(x%2)
					a += ")", b += "(";
				else
					a += "(", b += ")";
				x++;
			} else {
				if(y == 1)
					a += "(", b += "(";
				else if(a.size()+1 == s.size())			
					a += ")", b += ")";
				else {
				if((y+1)%2)
					a += "(", b += "(";
				else
					a += ")", b += ")";
				}
				y++;
			}
		}
		cout << "YES\n" << a << '\n' << b << '\n';
		return 0;
	});
	
}