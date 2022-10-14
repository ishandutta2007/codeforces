// Problem: B. Eastern Exhibition
// Contest: Codeforces - Codeforces Round #703 (Div. 2)
// URL: https://codeforces.com/contest/1486/problem/B
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
		vector<int> a, b;
		for(int x, y, i = 0; i < n; i++) {
			cin >> x >> y;
			a.push_back(x), b.push_back(y);
		}
		sort(all(a)), sort(all(b));
		int X = a[a.size()/2], Y = b[b.size()/2];
		int XX = a[(a.size()-1)/2], YY = b[(b.size()-1)/2];
		cout  << (abs(XX-X)+1)*1ll*(abs(YY-Y)+1) << '\n';
	});
	
}