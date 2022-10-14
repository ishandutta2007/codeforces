//#pragma GCC optimize("trapv")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define pb push_back
#include <x86intrin.h>
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;
using ld = long double;
const int maxn = 2e5 + 55, mod = 998244353 , i2 = (mod+1)/2;
int q;
void check(vi &a, vi &b, vi &vis, int x) {
	if(vis[x]) return;
	vi cyc;
	while(!vis[x]) {
		cyc.pb(x);
		vis[x] = 1;
		x = a[x];
	}
	//for(auto i : cyc) cout << i << " ";cout << '\n';
//	for(auto i : cyc) cout << b[i] << " ";
	//cout << ';' << '\n';
	int n = a.size();
	for(int i = 1; i <= cyc.size(); i++) {
		if(cyc.size()%i) continue;
		vi v(cyc.size(), -1);
		int g = 1;
		for(int j = 0; g && j < cyc.size(); j++) {
			if(v[j%i]==-1) v[j%i] = b[cyc[j]];
			if(v[j%i]!=b[cyc[j]]) v[j%i] = -2;
		}
		for(auto x : v) if(x>0) q = min(q, (int)i);
	}
}
void solve() {
	int n;
	q = 1<<30;
	cin >> n;
	vi a(n), b(n), vis(n);
	for(auto &i : a) cin >> i, i--;
	for(auto &i : b) cin >> i;
	for(int i = 0; i < n; i++) {
		check(a, b, vis, i);
	}
	cout << q << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	//t = 1;
	while(t--) solve();
}