#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)998244353;//change this if needed
int modpow(int x, int y) {
	return !y?1:((y % 2 ? x : 1) * modpow((x * x) % mod, y / 2)) % mod;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m,a;
	cin >> n >> m >> a;
	vector<int>arr; arr.push_back(0);
	for(int i = 0; i<m; i++){
		int x;
		cin >> x;
		arr.push_back(x);
	}
	int ans = 1;
	for(int i = 1; i<=m; i++){
		int d = arr[i]-arr[i-1];
		assert(d<mod);
		int v = modpow(a,2*d)-modpow(a,d)+mod;
		v%=mod;
		v*=modpow(2,mod-2); v%=mod;
		v+=modpow(a,d); v%=mod;
		ans*=v;
		ans%=mod;
	}
	int rem = n-arr[m]*2;
	ans*=modpow(a,rem); ans%=mod;
	cout << ans << "\n";
	return 0;
}