#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int N = 505;
int n, m;
struct matrix{
	bitset<N> a[N];
	matrix operator*(const matrix &r)const{
		matrix ans;
		for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) if(a[i][j])
			ans.a[i]|=r.a[j];
		return ans;
	}
};
matrix pw[61], inv[61];
void print(matrix &a) {
	for(int i = 0; i < n; i++, cout << '\n')
		for(int j = 0; j < n; j++)
			cout << a.a[i][j];
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int f, t, c, i = 0; i < m; i++) {
		cin >> f >> t >> c;
		if(c) inv[0].a[f][t] = 1;
		else pw[0].a[f][t] = 1;
	}
	for(int i = 1; i < 60; i++) {
		pw[i] = pw[i-1]*inv[i-1];
		inv[i] = inv[i-1]*pw[i-1];
	}
	matrix res;
	for(int i = 1; i <= n; i++) res.a[i][i] = 1;
	int iv = 0;
	ll ans = 0;
	for(int i = 60; i--;) {
		auto &nw = iv?inv[i]:pw[i];
		matrix t = res*nw;
		if(t.a[1].count()) res = t, iv^=1, ans += 1ll<<i;
	}
	if(ans > 1000000000000000000) ans = -1;
	cout << ans << endl;
}