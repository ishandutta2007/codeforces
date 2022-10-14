// Problem: B.    
// Contest: Codeforces - Codeforces Round #767 (Div. 1)
// URL: https://codeforces.com/contest/1628/problem/B
// Memory Limit: 512 MB
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
		cin >> n;
		vector<string> s(n);
		for(auto &i : s) {
			cin >> i;
		}
		for(int I = 0; I < 2; I++) {
		set<string> uh;
		for(auto i : s) {
			if(I==1) reverse(all(i));
			auto j = i;
			reverse(all(j));
			if(i==j) {
				report(1);
				return;
			}
			j = "";
			for(int x = i.size(); x--;) {
				j += i[x];
				string z = j+i;
				auto y = z;
				reverse(all(y));
				if(y==z && uh.count(j)) {
					report(1);
					return;
				}
			}
			uh.insert(i);
		}
		reverse(all(s));
		}
		report(0);
	});
	
}