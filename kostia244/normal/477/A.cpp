#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll a, b;
	cin >> a >> b;
	ll sum = 0;
	for(int i = 1; i <= a; i++) sum = (sum + i)%mod;
	ll ans = 0;
	for(int r = 1; r < b; r++) {
		ans = (ans + r*a + ((r*sum%mod)*b))%mod;
	}
	cout << ans << endl;
}