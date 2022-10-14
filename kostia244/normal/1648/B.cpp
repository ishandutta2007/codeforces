// Problem: B. Integral Array
// Contest: Codeforces - Codeforces Round #775 (Div. 1, based on Moscow Open Olympiad in Informatics)
// URL: https://codeforces.com/contest/1648/problem/B
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
	cout << (ok?"Yes":"No") << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		int n, c;
		cin >> n >> c;
		vector<int> a(c+1);
		for(int t, i = 0; i < n; i++) {
			cin >> t;
			a[t]++;
		}
		for(int i = 1; i <= c; i++) a[i] += a[i-1];
		int bad = 0;
		for(int x = 1; x <= c; x++) if(a[x]==a[x-1]) {
			for(int k = 1; k*x <= c; k++) {
				int l = k*x-1;
				int r = min(k*(x+1)-1, c);
				bad |= (a[k]!=a[k-1])&&(a[l]!=a[r]);
			}
		}
		report(!bad);
	});
}
//x : x*k + ... / k