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
	int n, k;
	string t;
	cin >> n >> k >> t;
	int sup = 0;
	for(int i = 1; i < n; i++) {
		int ok = 1;
		for(int j = 0; j < i; j++)
			ok &= t[j] == t[t.size()-i+j];
		if(ok) sup = i;
	}
	string ans = t;
	while(--k) {
		ans += t.substr(sup);
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