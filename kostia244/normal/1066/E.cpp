#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 998244353ll;

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	ll n, m;
	string s, t;
	cin >> n >> m >> s >> t;
	reverse(all(s));
	reverse(all(t));
	while(n < m) s += '0', n++;
	while(m < n) t += '0', m++;
	reverse(all(s));
	reverse(all(t));
	vi pref(n+1, 0);
	pref[0] = t[0]=='1';
	for(int i = 1; i < n; i++)
		pref[i] = pref[i-1] + (t[i]=='1');
	ll ans = 0, p2 = 1;
	for(int i = n-1; i >= 0; i--, p2 = (p2<<1)%mod) {
		if(s[i] == '0') continue;
		ans = (ans + p2*1ll*pref[i])%mod;
	}
	cout << ans;
}