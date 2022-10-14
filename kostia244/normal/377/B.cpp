#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
struct bug {
	ll i, c;
	bool operator<(const bug &rhs) {
		return c < rhs.c;
	}
};
struct usr {
	ll i, skl, cst;
	bool operator<(const usr &usr) {
		return skl < usr.skl;
	}
};
ll n, m, c, an[100100];
vector<bug> v;
vector<usr> u;
set<pi> x;
bool can(ll d) {
	x.clear();
	ll ans = 0;
	int i = 0, j = 0;
	ll U = 0, zz = 0;
	while(i < m) {
		while(j < n && u[j].skl >= v[i].c) {
			x.insert({u[j].cst, u[j].i});
			j++;
		}
		if(U) {
			U--;
			an[v[i].i] = zz;
			i++;
			continue;
		} else {
			U = d-1;
			if(x.empty()) return false;
			ans += x.begin()->first;
			zz = x.begin()->second+1;
			x.erase(x.begin());
			an[v[i].i] = zz;
			i++;
		}
	}
	return ans<=c;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> c;
	v.resize(m);
	for(int i = 0; i < m; i++) {
		cin >> v[i].c;
		v[i].i = i;
	}
	u.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> u[i].skl;
		u[i].i = i;
	}
	for(int i = 0; i < n; i++) {
		cin >> u[i].cst;
	}
	sort(rall(v));
	sort(rall(u));
	if(!can(m)) return cout << "NO", 0;
	ll days = 0;
	for(int x = 1<<16; x; x>>=1) if(days+x <= m && !can(days+x)) days += x;
	days++;
	cout << "YES\n";
	can(days);
	for(int i = 0; i < m; i++) cout << an[i] << " ";
}