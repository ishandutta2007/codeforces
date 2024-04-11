#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1e6, mod = 1e9 + 7;
vector<int> a;
int cnt[maxn], inv[maxn], fact[maxn];
ll nck(int n, int k) {
	if(k < 0 || n < k) return 0;
	ll r= fact[n]*1ll*inv[k]%mod;
	return r*inv[n-k]%mod;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	a.resize(n);
	for(auto &i : a) cin >> i;
	for(int d = 2; d <= 31625; d++) {
		for(int i = 0; i < n; i++) while(a[i]%d == 0) a[i]/=d, cnt[d]++;
	}
	ll ans = 1;
	map<int, int> ccnt;
	for(int i = 0; i < n; i++) if(a[i]>1) ccnt[a[i]]++;
	inv[0] = fact[0] = inv[1] = 1;
	for(int i = 2; i < maxn; i++) inv[i] = mod - (mod/i)*1ll*inv[mod%i]%mod;
	for(int i = 1; i < maxn; i++) {
		fact[i] = i*1ll*fact[i-1]%mod;
		inv[i] = inv[i]*1ll*inv[i-1]%mod;
	}
	for(int i = 0; i <= 31625; i++) {
		ans = ans*nck(cnt[i]+n-1, n-1)%mod;
	}
	for(auto i : ccnt)
		ans = ans*nck(i.second+n-1, n-1)%mod;
	cout << ans << endl;
}