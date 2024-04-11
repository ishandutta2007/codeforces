#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1e9 + 7;
void solve() {
	ll x;
	string s;
	cin >> x >> s;
	ll val = s[0]-'0';
	ll ans = s.size(), t = s.size()-1;
	for(int k = 1; s.size() < x+3 && k <= x; k++) {
		int os = s.size();
		for(int kk = 1; kk < val&&s.size()<x+3; kk++)
		for(int i = k; i < os && s.size()<x+3; i++) {
			s += s[i];
		}
		if(k<s.size())
			val = s[k]-'0';
	}
	val = s[0]-'0';
	for(int i = 0; i < x; i++) {
		val = s[i]-'0';
		val--;
		(ans += val*t)%=mod;
		t = ((val+1)*t - 1)%mod;
	}
	cout << ans << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}