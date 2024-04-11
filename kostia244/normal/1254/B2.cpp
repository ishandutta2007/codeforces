//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int maxn = 1000100;
ll n, a[maxn], suf[maxn];
ll find_opt(vector<pi> &v) {
	ll sm = v.back().second, cur = 0, ans;
	suf[v.size()] = suf[v.size()-1] = 0;
	for(int i = (int)v.size()-1;i--;) {
		suf[i] = suf[i+1];
		suf[i] += sm*(v[i+1].first-v[i].first);
		sm += v[i].second;
	}
	sm = v[0].second;
	ans = suf[0];
	for(int i = 1; i < v.size(); i++) {
		cur += sm*(v[i].first-v[i-1].first);
		ans = min(ans, cur+suf[i]);
		sm+=v[i].second;
//		cout << cur << " ";
	}
//	for(int i = 0; i < n; i++)
//		cout << suf[i] << " ";
//	cout << "\n=========\n";
	return ans;
}
ll solve(ll x) {
	vector<pi> pos;
	ll ans = 0, cur = 0;
	for(int i = 1; i <= n; i++) {
		int X = a[i]%x;
		if(cur+X>=x) {
			ll t = x-cur;
			X-=t;
			cur=x;
			pos.pb({i, t});
			ans += find_opt(pos);
			cur = 0;
			pos.clear();
		}
		if(X)
			pos.pb({i, X});
		cur += X;
	}
	return ans;
}
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	ll sum = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if(sum == 1) {
		cout << -1;
		return 0;
	}
	vi prime_divs;
	for(ll d = 2; d*d <= sum; d++) {
		if(sum%d) continue;
		prime_divs.pb(d);
		while(sum%d == 0) sum/=d;
	}
	if(sum > 1) prime_divs.pb(sum);
	ll ans = LLONG_MAX;
	for(auto i : prime_divs)
		ans = min(ans, solve(i));
	cout << ans;
}