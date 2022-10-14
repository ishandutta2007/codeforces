#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#include <x86intrin.h>
#define pb push_back
using namespace std;
using ll = long long;
const int maxn = 1e6 + 3;
void solve() {
	int n, lst;
	cin >> n >> lst;
	int ans = 1, cur = 1;
	for(int t, i = 1; i < n; i++) {
		cin >> t;
		if(t<=2*lst) ++cur;
		else cur = 1;
		lst = t, ans = max(ans, cur);
	}
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	//cin >> t;
	t = 1;
	while(t--) solve();
}