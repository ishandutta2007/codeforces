#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,sse2,sse,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using vi = vector<ll>;
ll n, m, mat[505][505];
ll getr(ll i) {
	return n<=m?i:m+i;
}
ll getc(ll i) {
	return m<n?i:n+i;
}
ll get(ll i, ll j) {
	return (getr(i) *1ll *(getc(j)/__gcd(getr(i), getc(j))));
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	if(n==1&&m==1) {
		cout << 0;
		return 0;
	}
	for(int i = 1; i <= n; i++, cout << "\n")
		for(int j = 1; j <= m; j++) cout << get(i, j) << " ";
}