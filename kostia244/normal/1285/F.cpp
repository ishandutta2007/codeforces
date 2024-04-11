#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using ld = long double;
#include<bits/extc++.h>
using namespace __gnu_pbds;
using oset = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 1<<17, mod = 1e9 + 7;
int mu[maxn], lp[maxn];
vi pr, gdiv[maxn];
void sieve() {
	mu[1] = 1;
	for(int i = 2; i < maxn; i++) {
		if(lp[i] == 0) {
			pr.pb(i);
			lp[i] = i;
			mu[i] = -1;
		} else {
			if(lp[i] == lp[i/lp[i]]) mu[i] = 0;
			else mu[i] = -mu[i/lp[i]];
		}
		for(int j = 0; j < pr.size() && pr[j] <= lp[i] && i*pr[j] < maxn; j++) lp[i*pr[j]] = pr[j];
	}
}
vi fct(int x) {
	vi ret;
	while(x > 1) {
		int t = lp[x];
		while(x%t == 0) x/=t;
		ret.pb(t);
	}
	vi r;
	for(int i = 0; i < 1<<ret.size(); i++) {
		int t = 1;
		for(int j = 0; j < ret.size(); j++) {
			if((i>>j)&1) t *= ret[j];
		}
		r.pb(t);
	}
	return r;
}
struct coprime_stack {
	int cnt[maxn];
	vi st;
	coprime_stack() {
		memset(cnt, 0, sizeof cnt);
	}
	ll push(int x) {
		ll ans = 0;
		int lft = 0;
		for(auto r : gdiv[x]) {
			lft += mu[r] * cnt[r]++;
		}
		while(lft) {
			if(__gcd(x, st.back()) == 1) ans = st.back()*1ll*x, lft--;
			pop();
		}
		st.push_back(x);
		return ans;
	}
	void pop() {
		int x = st.back();
		for(auto r : gdiv[x]) {
			cnt[r]--;
		}
		st.pop_back();
	}
};
coprime_stack st;
int occ[maxn], n;
ll solve(int g) {
	ll ans = 0;
	for(int i = maxn/g; i--;) {
		if(!occ[i*g]) continue;
		ans = max(ans, st.push(i));
	}
	while(st.st.size()) st.pop();
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	sieve();
	for(int i = 1; i < maxn; i++) gdiv[i] = fct(i);
	cin >> n;
	ll ans = 0;
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		occ[t]++, ans = max(ans, (ll)t);
	}
	for(int g = 1; g < maxn; g++) {
		ans = max(ans, g*solve(g));
	}
	cout << ans;
}