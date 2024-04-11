#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<int, int>;
using vpi = vector<pi>;
const int maxn = 63, mod = 1e9 + 9;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll lp[maxn], mu[maxn];
vi pr;
void setup() {
	memset(lp, 0, sizeof lp);
	memset(mu, 0, sizeof mu);
	mu[1] = 1;
	for(int i = 2; i < maxn; i++){
		if(!lp[i]) {
			lp[i] = i;
			mu[i] = -1;
			pr.pb(i);
		} else {
			if(lp[i]==lp[i/lp[i]]) mu[i] = 0;
			else mu[i] = -mu[i/lp[i]];
		}
		for(int j = 0; j < pr.size() && pr[j] <= lp[i] && pr[j]*i < maxn; j++) {
			lp[i*pr[j]] = pr[j];
		}
	}
}
ll bp(ll a, ll p) {
	ll r = 1;
	while(p) {
		if(p&1) {
			if(a>LLONG_MAX/r) return LLONG_MAX;
			r = (r*a);
		}
		if(p>1) {
		if(a>LLONG_MAX/a) return LLONG_MAX;
		p>>=1, a = (a*a);
		} else
			break;
	}
	return r;
}
void solve() {
	ll n, ans = 0, t;
	cin >> n;
	for(int i = 1; (1ll<<i) <= n; i++) {
		if(!mu[i]) continue;
		t = pow(n, 1./i);

		while(bp(t, i)>n) t--;
		while(bp(t+1, i)<=n) t++;
		if(t)
		ans += mu[i]*(t-1);
	}
	cout << ans << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	setup();
	int t;
	cin >> t;
	while(t--) solve();
}