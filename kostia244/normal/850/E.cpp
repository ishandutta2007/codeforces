#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
vector<int> FWHT(vector<int> a, int inv) {
	int n = a.size();
	int inv2 = 1;
	for(int b = 1; b < n; b<<=1) {
		inv2 = inv2 * 1ll * (mod+1)/2 %mod;
		for(int i = 0; i < n; i++) if((i^b) > i) {
			int j = i^b;
			int x = (a[i]+a[j])%mod;
			int y = (mod+a[i]-a[j])%mod;
			a[i] = x;
			a[j] = y;
		}
	}
	if(inv) for(auto &i : a) i = i*1ll*inv2%mod;
	return a;
}
vector<int> conv(vector<int> a) {
	a = FWHT(a, 0);
	for(auto &i : a) i = i*1ll*i%mod;
	return FWHT(a, 1);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	char c;
	vector<int> a;
	for(int i = 0; i < 1<<n; i++) cin >> c, a.push_back(c-'0');
	a = conv(a);
	int ans = 0;
	for(int i = 0; i < 1<<n; i++) {
		for(int j = n-__builtin_popcount(i); j--;) a[i] = a[i]*2ll%mod;
		ans = (ans + a[i])%mod;
	}
	cout << ans*3ll%mod << '\n';
}