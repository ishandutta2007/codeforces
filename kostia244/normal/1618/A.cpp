// Problem: A.    
// Contest: Codeforces - Codeforces Round #760 (Div. 3)
// URL: https://codeforces.com/contest/1618/problem/A
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
		vector<ll> a(7);
		for(auto &i : a) cin >> i;
		a.push_back(0);
		sort(all(a));
		do {
			int ok = 1;
			for(int i = 1; i < 8; i++) {
				int j = i&-i;
				if(a[i] != (a[i^j] + a[j]))
					ok = 0;
			}
			if(ok)
			break;
		} while(next_permutation(1+all(a)));
		cout << a[1] << " " << a[4] << " " << a[2] << endl;
	});
	
}