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
const int maxn = 3e5 + 5;
ll n, m;
vector<vi> g;
set<int> u, v;
vi cur;
void merge(vi& a, vi b) {
	map<int, int> cnt;
	for(auto i : a) {
		cnt[i]|=1;
		v.erase(i);
		u.insert(i);
	}
	for(auto i : b)
		cnt[i]|=2;
	a.clear();
	for(auto i : cnt) {
		if(i.second==3) {
			u.erase(i.first);
			v.insert(i.first);
			a.pb(i.first);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	g.resize(n+1);
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	for(int i = 2; i <= n; i++)
		u.insert(i);
	for(auto i : g[1]) {
		u.erase(i);
		v.insert(i);
	}
	cur = g[1];
	int ans = 0, c = 0;
	while(u.size()||v.size()) {
		if(u.size()) {
			c = *u.begin();
			u.erase(u.begin());
		} else {
			ans++;
			c = *v.begin();
			v.erase(v.begin());
		}
		merge(cur, g[c]);
	}
	cout << ans;
}