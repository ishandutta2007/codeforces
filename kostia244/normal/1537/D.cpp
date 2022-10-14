// Problem: D. Deleting Divisors
// Contest: Codeforces - Codeforces Round #726 (Div. 2)
// URL: https://codeforces.com/contest/1537/problem/D
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
	int n= 1010;
	vector<int> win(n);
	for(int i = 1; i < n; i++) {
		win[i] = 0;
		for(int j = 2; j < i; j++) if(i%j == 0) {
			win[i] |= !win[i - i/j];
			//if(!win[i - i/j]) cout << i << " to " << i-(i/j) << '\n';
		}
		//if(win[i]) cout << i << endl;
		//if(i%2 == 0 && !win[i]) cout << i << endl;
	}
	multitest([&](){
		ll n;
		cin >> n;
		for(int i = 0; i < 30; i += 2)
			if((2<<i)==n)
				n = 1;
		cout << (((n+1)&1)?"Alice":"Bob") << '\n';
	});
			
}