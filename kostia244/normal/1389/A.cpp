#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse4,popcnt,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<17, mod = 1e9 + 7;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t, l, r;
	cin >> t;
	while(t--) {
		cin >> l >> r;
		if(2*l > r) cout << "-1 -1\n";
		else cout << l << " " << 2*l << '\n';
	}
}