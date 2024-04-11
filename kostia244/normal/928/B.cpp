// Problem: B.   
// Contest: Codeforces - VK Cup 2018 -  1
// URL: https://codeforces.com/contest/928/problem/B
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
	//multitest([&](){});
	int n, k; 
	cin >> n >> k;
	vector<int> a(n), b(n);
	for(auto &i : a) cin >> i,i--;
	for(int j = 0; j < n; j++) {
		if(a[j] != -1) {
			if(j-a[j]-1 <= 2*k)
				b[j] = b[a[j]]+(j-a[j]);
			else
				b[j] = b[a[j]] + 2*k + 1;
		} else b[j] = min(k+1, j+1);
		cout << b[j]+min<int>(k, n-j-1) << ' ';
	}
}