//#pragma GCC optimize("trapv")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define pb push_back
#include <x86intrin.h>
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;
using ld = long double;
const int maxn = 2e5 + 55, mod = 998244353 , i2 = (mod+1)/2;
ll n, dp[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	dp[0] = 1;
	for(int i = 1; i <= n; i++) dp[i] = dp[i-1]*10ll%mod;
	for(int i = 1; i < n; i++) {
		ll ans = 0;
		ll t = n-i-1;
		t = t*10ll%mod;
		if(n-i-1>0) {
			t = (t*9ll*9ll)%mod;
			t = (t*1ll*dp[n-i-2])%mod;
			ans += t;
			ans%=mod;
		}
		t = 2;
		t = t*90ll%mod;
		t = (t*1ll*dp[n-i-1])%mod;
		ans += t;
			ans%=mod;
		cout << ans << " ";
	}
	cout << " 10";
}