//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const int mod = 7 * 17 * (1 << 23) + 1;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct dsu {
	vi r, p;
	int sz;
	void init(int n) {
		sz = n;
		r.assign(n+1, 0);
		p.resize(n+1, 0);
		for(int i = 0; i <= n; i++) p[i] = i;
	}
	int par(int i) {
		if(i==p[i]) return i;
		return p[i] = par(p[i]);
	}
	void unite(int i, int j) {
		i = par(i), j = par(j);
		if(i==j) return;
		--sz;
		if(r[i] < r[j]) swap(i, j);
		p[j] = i;
		r[i] += r[i] == r[j];
	}
};
int main() { //DINIC ORZ, FFT ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	dsu d;
	vvi x;
	cin >> n;
	d.init(n);
	x.resize(27);
	string t;
	while(n) {
		cin >> t;
		for(auto i : t)
			x[i-'a'].pb(n);
		n--;
	}
	for(auto i : x) {
		int p = -1;
		for(auto j : i) {
			if(p!=-1) d.unite(j, p);
			p = j;
		}
	}
	cout << d.sz;
}