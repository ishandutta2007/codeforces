// Problem: C. Unequal Array
// Contest: Codeforces - Codeforces Global Round 20
// URL: https://codeforces.com/contest/1672/problem/C
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
		cin >> n;
		vector<int> a(n);
		for(auto &i : a) cin >> i;
		int l = 0, r = n-1;
		while(l+1 < n && a[l] != a[l+1])
			l++;
		while(r-1 >= l && a[r] != a[r-1])
			r--;
		if(r-l+1 < 3) cout << "0\n";
		else if(r-l+1 == 3) cout << "1\n";
		else cout << r-l-2 << '\n';
	});
	
}