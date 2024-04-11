// Problem: D1.    ( )
// Contest: Codeforces - Codeforces Global Round 16
// URL: https://codeforces.com/contest/1566/problem/D1
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
#include<bits/extc++.h>
using namespace __gnu_pbds;
using Tr = tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		int n, m;
		cin >> n >> m;
		vector<array<int, 2>> a(n*m), pos(n*m);
		vector<Tr> f(n);
		for(int i = 0; i < n*m; i++)
			cin >> a[i][0], a[i][1] = -i;
		sort(all(a));
		for(int i = 0; i < n*m; i++)
			pos[-a[i][1]] = {i/m, i%m};
		ll ans = 0;
		for(auto [x, y] : pos) {
			ans += f[x].order_of_key(y);
			f[x].insert(y);
		}
		cout << ans << '\n';
	});
	
}