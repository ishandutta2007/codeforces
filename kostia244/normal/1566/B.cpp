// Problem: B. MIN-MEX 
// Contest: Codeforces - Codeforces Global Round 16
// URL: https://codeforces.com/contest/1566/problem/B
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
		string s;
		cin >> s;int n = s.size();
		int l = 0;
		while(l < n && s[l] != '0') l++;
		int r = n-1;
		if(l == n) r = n;
		else while(s[r] != '0') r--;
		if(l==n)
			cout << "0\n";
		else if(r-l+1 == count(all(s), '0'))
			cout << 1 << '\n';
		else 
			cout << "2\n";
	});
	
}