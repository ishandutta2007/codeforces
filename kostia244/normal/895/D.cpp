#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
const int maxn = 1<<21, mod = 1e9 + 7;
ll fact[maxn], inv[maxn];
ll bp(ll a, ll p) {
	ll r = 1;
	while(p) {
		if(p&1) r = r*a%mod;
		a = a*a%mod, p >>= 1;
	}
	return r;
}
int cnt[26];
ll calc() {
	ll res = 1, sm = 0;
	for(int i = 0; i < 26; i++) {
		sm += cnt[i];
		if(cnt[i] < 0) return 0;
	}
	sm = fact[sm];
	for(int i = 0; i < 26; i++) {
		sm = sm * inv[cnt[i]]%mod;
	}
	return sm;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	fact[0] = fact[1] = inv[0] = inv[1] = 1;
	for(int i = 2; i < maxn; i++) fact[i] = fact[i-1]*1ll*i%mod, inv[i] = bp(fact[i], mod-2);
	string l, r;
	cin >> l >> r;
	reverse(all(l));
	reverse(all(r));
	while(!l.empty() && l.back() == r.back()) l.pop_back(), r.pop_back();
	reverse(all(l));
	reverse(all(r));
	ll ans = 0;
	if(l.empty() || l[0] > r[0]) return cout << 0, 0;
	memset(cnt, 0, sizeof cnt);
	for(auto i : l) cnt[i-'a']++;
	for(int i = 1; i < l.size(); i++) {
		cnt[l[i-1]-'a']--;
		for(char c = l[i]+1; c <= 'z'; c++) {
			cnt[c-'a']--;
			(ans += calc()) %= mod;
			cnt[c-'a']++;
		}
	}
	memset(cnt, 0, sizeof cnt);
	for(auto i : l) cnt[i-'a']++;
	for(int i = 1; i < r.size(); i++) {
		cnt[r[i-1]-'a']--;
		for(char c = 'a'; c < r[i]; c++) {
			cnt[c-'a']--;
			(ans += calc()) %= mod;
			cnt[c-'a']++;
		}
	}
	memset(cnt, 0, sizeof cnt);
	for(auto i : l) cnt[i-'a']++;
	for(char i = l[0] + 1; i < r[0]; i++) {
		cnt[i-'a']--;
		(ans += calc()) %= mod;
		cnt[i-'a']++;
	}
	cout << ans;
}