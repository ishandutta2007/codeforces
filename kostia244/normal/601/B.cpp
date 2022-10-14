#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 1e5 + 55;
ll n, m, a[maxn], b[maxn], d[maxn], st[maxn], sz;
ll calc(ll i, ll j) {
	ll l = j-i;
	for(int k = i; k+1 <= j; k++) {
		b[k-i] = abs(a[k]-a[k+1]);
//		cout << b[k-i] << " dff\n";
	}
	sz = 0;
	for(int k = 0; k < l; k++) {
		while(sz&&b[st[sz-1]]<=b[k]) {
			sz--;
		}
//		cout << (sz?st[sz-1]:-1) << " " << k << "kk\n";
		d[k] = k-(sz?st[sz-1]:-1);
		st[sz++] = k;
	}
	sz = 0;
	for(int k = l; k--;) {
		while(sz&&b[st[sz-1]]<b[k]) {
			sz--;
		}
		d[k] *= (sz?st[sz-1]:l)-k;
		st[sz++] = k;
	}
	ll sm = 0;
	for(int i = 0; i < l; i++) {
//		cout << b[i] << " " << d[i]<< "\n";
		sm += b[i]*d[i];
	}
	return sm;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int l, r, i = 0; i < m; i++) {
		cin >> l >> r, l--, r--;
		cout << calc(l, r) << "\n";
	}
}