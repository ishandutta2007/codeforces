// Problem: D. Searchlights
// Contest: Codeforces - Grakn Forces 2020
// URL: https://codeforces.com/contest/1408/problem/D
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
const int C = 1e6 + 16;
int A[C];
void mq(int p, int v) {
	A[p] = max(A[p], v);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n, m;
	cin >> n >> m;
	vector<array<int, 2>> a(n), b(m);
	for(auto &[x, y] : a) cin >> x >> y;
	for(auto &[x, y] : b) cin >> x >> y;
	sort(all(b));
	vector<int> sufy(m);
	for(int i = 0; i < m; i++)
		sufy[i] = b[i][1];
	sufy.push_back(-1);
	for(int i = m-1; i-->0;)
		sufy[i] = max(sufy[i], sufy[i+1]);
	for(int i = 0; i < n; i++) {
		int lst;
		lst = max(0, sufy[0]-a[i][1]+1);
		for(int j = 0; j < m; j++) {
			int xo = max(0, b[j][0]-a[i][0]+1);
			int cur = max(0, sufy[j+1]-a[i][1]+1);
			if(xo)
				mq(xo-1, lst);
			lst = cur;
		}
		mq(C-1, lst);
	}
	int ans = 1<<30;
	for(int i = C-1;i--;)
		A[i] = max(A[i], A[i+1]);
	for(int i = 0; i < C-3; i++)
		ans = min(ans, A[i]+i);
	cout << ans << '\n';
}