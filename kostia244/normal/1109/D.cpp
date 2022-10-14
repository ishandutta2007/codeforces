#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
const int maxn = 1<<22, mod = 1e9 + 7;
int fact[maxn], inv[maxn];
void setup() {
	inv[0] = fact[0] = inv[1] = 1;
	for(int i = 2; i < maxn; i++) inv[i] = mod - (mod/i)*1ll*inv[mod%i]%mod;
	for(int i = 1; i < maxn; i++) {
		fact[i] = fact[i-1]*1ll*i%mod, inv[i] = inv[i-1]*1ll*inv[i]%mod;
	}
}
int bp(int a, int p) {
	int r = 1;
	while(p) {
		if(p&1) r = r*1ll*a%mod;
		a = a*1ll*a%mod, p>>=1;
	}
	return r;
}
int nck(int n, int k) {
	if(k > n || k < 0) return 0;
	return (fact[n]*1ll*inv[k]%mod)*1ll*inv[n-k]%mod;
}
int f(int n, int k) {
	if(k > n) return 0;
	if(k == n) return fact[n-2];
	int res = k;
	if(k > 1) {
		res = res*1ll*fact[n-2]%mod;
		res = res*1ll*inv[n-k]%mod;
	}
	res = res*1ll*bp(n, n-k-1)%mod;
	return res;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    setup();
    int n, m;
    cin >> n >> m;
	int ans = 0; 
	for(int i = 2; i <= n; i++) {
		int t = f(n, i);
		t = t*1ll*nck(m-1, i-2)%mod;
		t = t*1ll*bp(m, n-i)%mod;
		ans = (ans + t)%mod;
	}
	cout << ans << '\n';
}