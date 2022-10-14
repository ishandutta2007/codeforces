// Problem: B.   
// Contest: Codeforces - Codeforces Global Round 18
// URL: https://codeforces.com/contest/1615/problem/B
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
const int N = 2e5 + 15, C = 20;
int p[N][C];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	for(int i = 0; i < N; i++) {
		if(i) {
			for(int j = 0; j < C; j++)
				p[i][j] = p[i-1][j];
		}
		for(int j = 0; j < C; j++) if(((i>>j)&1)==0)
			p[i][j]++;
	}
	multitest([&](){
		int l, r;
		cin >> l >> r;
		int ans = 1<<30;
		for(int b = 0; b < C; b++)
			ans = min(ans, p[r][b]-p[l-1][b]);
		cout << ans << '\n';
	});
	
}