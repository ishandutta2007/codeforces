#pragma GCC optimize("trapv")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 5e5 + 555;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
struct hsh {
	pair<ll, ll> a;
	void gen() {
		a.first = rng();
		a.second = rng();
	}
	void add(hsh& b) {
		a.first ^= b.a.first;
		a.second ^= b.a.second;
	}
	void zero() {
		a.first=a.second=0;
	}
	bool operator==(const hsh& o) {
		return a==o.a;
	}
};
vi coord;
struct seg {
	ll l, r, id;
	void get() {
		cin >> l >> r;
		coord.pb(l);
		coord.pb(r);
	}
	void comp() {
//		cout << l << " " << r << " =? ";
		l = lower_bound(all(coord), l)-coord.begin();
		r = lower_bound(all(coord), r)-coord.begin();
//		cout << l << " " << r << "\n";
	}
};
hsh h[maxn], prefs[maxn], prefe[maxn];
int n;
vector<seg> x, y;
vector<hsh> find(vector<seg> v) {
	vector<hsh> res(n);
	for(int i = 0; i < maxn; i++){
		prefs[i].zero();
		prefe[i].zero();
	}
//	for(int i = 0; i < n; i++)
//		cout << i << " " << v[i].l << " " << v[i].r << "\n";
	for(auto i : v) {
		prefs[i.l].add(h[i.id]);
		prefe[i.r].add(h[i.id]);
	}
	for(int i = 1; i < maxn; i++){
		prefs[i].add(prefs[i-1]);
		prefe[i].add(prefe[i-1]);
//		if(i < 10) {
//			cout << i << " " << prefs[i].a.first << " " << prefs[i].a.second << "\n";
//		}
	}
	for(int i = 0; i < n; i++) {
		res[i] = prefs[v[i].r];
		if(v[i].l)
			res[i].add(prefe[v[i].l-1]);
	}
	return res;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) h[i].gen();//, cout << i << " " << h[i].a.first << " " << h[i].a.second << "\n";
	x.resize(n);
	y.resize(n);
	for(int i =0; i < n; i++) {
		x[i].get();
		y[i].get();
//		cout << i << " " << x[i].l << " " << x[i].r << "\n";
		x[i].id=y[i].id=i+1;
	}
//	for(auto i : coord) cout << i << " ";cout << ";;;\n";
	sort(all(coord));
	coord.erase(unique(all(coord)), coord.end());
	for(auto &i : x) i.comp();
	for(auto &i : y) i.comp();
	vector<hsh> a = find(x);
	vector<hsh> b = find(y);
	for(int i = 0; i < n; i++)
		if(!(a[i]==b[i])) return cout << "NO", 0;
	cout << "YES";
}