#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,popcnt,sse4.1,sse4.2,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<ll>;
using vvi = vector<vi>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<18, mod = 1e9 + 7 , lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll d, n, m;
map<int, int> g;
vpi a;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> d >> n >> m;
    g[0] = 0;
	g[d] = 1<<30;
	for(int a, b, i = 0; i < m; i++) {
		cin >> a >> b;
		g[a] = min(g.count(a)?g[a]:1<<30, b);
	}
	for(auto i : g) a.pb(i);
	map<ll, ll> can;
	ll ans = 0, cur = 0;
	ll lst = -1;
	for(int _i = 0; _i+1 < a.size(); _i++) {
		auto i = a[_i];
		auto j = a[_i+1];
		can[i.second] += lst == -1 ? n : i.first-lst;
		lst = i.first;
		while(can.rbegin()->first > i.second) {
			can[i.second] += can.rbegin()->second;
			can.erase(can.rbegin()->first);
		}
		ll req = j.first-i.first;
		while(cur < req && can.size()) {
			ll t = min(req-cur, can.begin()->second);
			ans += t*can.begin()->first;
			cur += t;
			if(can.begin()->second == t) can.erase(can.begin());
			else can.begin()->second -= t;
		}
		if(cur<0||cur>n) return cout << -1, 0;
		cur -= req;
		if(cur<0) return cout << -1, 0;
	}
	cout << ans;
}