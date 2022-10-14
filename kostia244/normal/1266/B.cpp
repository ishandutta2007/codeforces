#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,sse2,sse,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using vi = vector<ll>;
bool can(ll x) {
	return x%14==0;
}
void solve() {
	ll x;
	cin >> x;
	bool ok = false;
	for(ll i = 1; !ok && i <= 6; i++) {
		if(x<21-i) continue;
		ok|=can(x-21+i);
	}
	cout << (ok?"YES\n":"NO\n");
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}