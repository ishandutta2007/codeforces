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
ll n, ans = 0, a[200200];
vi z;
ll eval() {
	ll med = z[z.size()/2];
	ll ans = 0;
	for(auto i : z)
		ans += abs(med-i);
	return ans;
}
ll solve(ll x) {
	ll ans = 0, sm = 0;
	for(int i = 0; i < n; i++) {
		if(!a[i]) continue;
		z.pb(i);
		sm += a[i];
		if(sm%x==0) {
			ans += eval();
			sm=0;
			z.clear();
		}
	}
	z.clear();
	return ans;
}
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int lst = -1, cnt = 0;
	for(int t, i = 0; i < n; i++) {
		cin >> a[i];
		cnt += a[i];
	}
	if(cnt < 2) return cout << -1, 0;
	vi pr;
	for(ll d = 2; d*d <= cnt; d++) {
		if(cnt%d) continue;
		pr.pb(d);
		while(cnt%d==0) cnt/=d;
	}
	if(cnt>1) pr.pb(cnt);
	ll ans = LLONG_MAX;
	for(auto x : pr) {
		ans = min(ans, solve(x));
	}
	cout << ans << "\n";
}