//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 3e5 + 55, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int pw[maxn];
int n, x[maxn];
void setup() {
	pw[0] = 1;
	for(int i = 1; i < maxn; i++) {
		pw[i] = (pw[i-1]<<1)%mod;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	setup();
	cin >> n;
	for(int i = 0; i < n; i++) cin >> x[i];
	sort(x, x+n);
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ans = (ans+pw[i]*1ll*x[i])%mod;
	}
	for(int i = 0; i < n; i++) {
		ans = ans - (pw[n-i-1]*1ll*x[i])%mod;
		if(ans < 0) ans += mod;
	}
	cout << ans;
}