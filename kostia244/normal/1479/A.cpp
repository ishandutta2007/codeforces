// Problem: A. Searching Local Minimum
// Contest: Codeforces - Codeforces Round #700 (Div. 1)
// URL: https://codeforces.com/contest/1479/problem/A
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
int n;
map<int, int> memo;
int qry(int pos) {
	if(pos < 1 || pos > n) return 1<<30;
	if(memo.count(pos)) return memo[pos];
	cout << "? " << pos << endl;
	int t;
	cin >> t;
	return memo[pos] = t;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n;
	int l = 1, r = n;
	while(r-l > 4) {
		int a = (l+r)/2;
		int b = a+1;
		if(qry(a) < qry(b)) {
			r = b;
		} else {
			l = a;
		}
	}
	for(l; l <= r; l++) if(qry(l) < min(qry(l-1), qry(l+1))) {
		cout << "! " << l << endl; return 0;
	}
}