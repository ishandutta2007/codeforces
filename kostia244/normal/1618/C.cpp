// Problem: C.  
// Contest: Codeforces - Codeforces Round #760 (Div. 3)
// URL: https://codeforces.com/contest/1618/problem/C
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
	#define int long long
	multitest([&](){
		int n;
		cin >> n;
		vector<int> a(n); 
		for(auto &i : a) cin >> i;
		int x = 0, y = 0;
		for(int i = 0; i < n; i++) {
			if(i&1)
				x = __gcd(x, a[i]);
			else
				y = __gcd(y, a[i]);
		}
		for(int i = 1; y && i < n; i+=2) 
			if(a[i]%y== 0)
				y = 0;
		for(int i = 0; x && i < n; i+=2)
			if(a[i]%x == 0)
				x = 0;
		cout << max(x, y) << '\n';
	});
	
}