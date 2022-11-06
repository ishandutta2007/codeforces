#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e9+7;//change this if needed
int modpow(int x, int y) {
	return !y?1:((y % 2 ? x : 1) * modpow((x * x) % mod, y / 2)) % mod;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int k;
	cin >> k;
	int v = 1LL<<k;
	v-=2;
	int ans = 6;
	ans*=modpow(4,v);
	ans%=mod;
	cout << ans << "\n";
	return 0;
}