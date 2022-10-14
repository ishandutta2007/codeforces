#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1e5 + 10, mlg = 17, mod = 1e9 + 7;
inline pi rev(const pi& x) {
	return {x.second, x.first};
}
ll n, L, S, w[maxn];
struct state {
	ll ans = 0;
	set<pi> ls, sl;
	ll lbias = 0, sbias = 0;
	void erase(pi a) {
		ls.erase(a);
		sl.erase(rev(a));
	}
	void add(ll w) {
		while(!ls.empty()&&ls.rbegin()->first+lbias==L) {
			erase(*ls.rbegin());
		}
		while(!sl.empty()&&sl.rbegin()->first+sbias+w>S) {
			erase(rev(*sl.rbegin()));
		}
		if(ls.empty()) {
			ans++, lbias = sbias = 0;
			ls.insert({1, w});
			sl.insert({w, 1});
		} else {
			sbias += w;
			lbias += 1;
		}
	}
	void merge(state& rhs) {
		ans += rhs.ans;
		for(auto i : rhs.ls) {
			pi t = {i.first+rhs.lbias-lbias, i.first+rhs.sbias-sbias};
			ls.insert(t);
			sl.insert(rev(t));
		}
	}
};
state a[maxn];
vi g[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n >> L >> S;
	for(int i = 1; i <= n; i++) {
		cin >> w[i];
		if(w[i] > S)
			return cout << -1, 0;
	}
	for(int t, i = 2; i <= n; i++) {
		cin >> t;
		g[t].pb(i);
	}
	for(int i = n; i; i--) {
		for(auto j : g[i]) {
			if(a[j].ls.size()>a[i].ls.size())
				swap(a[i], a[j]);
		}
		for(auto j : g[i]) {
			a[i].merge(a[j]);
		}
		a[i].add(w[i]);
	}
	cout << a[1].ans;
	return 0;
}