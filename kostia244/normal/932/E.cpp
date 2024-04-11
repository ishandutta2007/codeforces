#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int inv(int x) { return x>1?mod-(mod/x)*1ll*inv(mod%x)%mod:x; }
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> r(k+1), t(k+1);
	t[0] = r[0] = 1;
	for(int i = 0; i < k; i++)
		r[i+1] = r[i]*1ll*inv(i+1)%mod;
	r[0]++;
	auto conv = [&](vector<int> &a, vector<int> &b) {
		vector<int> c(k+1);
		for(int i = 0; i <= k; i++)
			for(int j = 0; i+j <= k; j++)
				c[i+j] = (c[i+j] + a[i]*1ll*b[j])%mod;
		return c;
	};
	while(n) {
		if(n&1) t = conv(t, r);
		r = conv(r, r), n>>=1;
	}
	for(int j = 1; j <= k; j++)
		t[k] = t[k]*1ll*j%mod;
	cout << t[k] << '\n';
}