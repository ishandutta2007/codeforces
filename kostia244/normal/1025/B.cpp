#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<20, mod = 998244353;
	vector<array<int, 2>> f;
void tr(int D) {
	int ok = 1;
	for(auto [x, y] : f) ok &= (x%D == 0) || (y%D == 0);
	if(ok) cout << D, exit(0);
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;f.resize(n);
	for(auto &i : f) cin >> i[0] >> i[1];
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	shuffle(all(f), rng);
	for(int X : {f[0][0], f[0][1]}) {
	for(int D = 2; D*D <= X; D++) {
		if(X%D) continue;
		tr(D);
		while(X%D == 0) X/=D;
	}
	if(X>1) tr(X);
	}
	cout << "-1\n";
}