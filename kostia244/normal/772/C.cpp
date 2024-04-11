#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const int mod = 1e9 + 7;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, phi = 1;
ll bp(ll a, ll p) {
	ll r = 1;
	while (p) {
		if (p & 1)
			r = (r * a) % m;
		a = (a * a) % m;
		p >>= 1;
	}
	return r;
}
ll jump(int x, int y) {
	int g1 = __gcd(x, m);
	int g2 = __gcd(y, m);
	x/=g1, y/=g2;
	return (y*bp(x, phi-1)*g2/g1)%m;
}
vi cnt[200200];
int p[200200], dp[200200];
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	ll tm = m;
	for (ll d = 2; d * d <= tm; d++) {
		if (tm % d)
			continue;
		ll c = 1;
		while (tm % d == 0)
			c *= d, tm /= d;
		phi *= (c / d) * (d - 1);
	}
	if (tm > 1)
		phi *= tm - 1;
	vi a;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
	sort(all(a));
	int u = 0;
	vi b;
	for (int i = 0; i < m; i++) {
		if (u < a.size() && a[u] == i)
			u++;
		else
			cnt[__gcd(i, m)].pb(i);
	}
	for(int i = m; i;i--) {
		p[i] = -1;
		for(int j = i+i; j <= m; j += i)
			if(p[i]==-1||dp[j]>dp[p[i]]) {
				p[i] = j;
			}
		dp[i] = cnt[i].size();
		if(p[i]!=-1) dp[i] += dp[p[i]];
	}
	int i = 1;
	while(i!=-1) {
//		cout << i << " " << cnt[i].size() << "\n";
		for(auto j : cnt[i]) b.pb(j);
		i = p[i];
	}
	vi ans;
	ll mul = 1;
	for (auto i : b) {
		if (ans.empty()) {
			ans.pb(i), mul = i;
		} else if (__gcd(i, m) % __gcd((int) mul, m) == 0) {
			ans.pb(jump(mul, i));
//			cout << mul << " ->" << i << " " << ans.back() << "\n";
			mul = i;
		}
	}

	cout << ans.size() << "\n";
	for (auto i : ans)
		cout << i << " ";
}