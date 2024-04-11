#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
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
const int maxn = 5e2 + 10, mlg = 17, mod = 1e9 + 7;
ll p = 1;
ll p2(ll a) {
	ll r = 1;
	while(a--) r = (r<<1)%mod;
	return (r*r)%mod;
}
#define M(x) ((x)%mod)
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	ll ans = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i]=='1')
		ans = M(ans + M(p*p2(s.size()-i-1)));
		p = (p<<1)%mod;
	}
	cout << ans;
	return 0;
}