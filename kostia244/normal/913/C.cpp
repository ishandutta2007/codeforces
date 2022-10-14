#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define int ll
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<20;
ll n, l, c[maxn];
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> l;
	for(int i = 0; i < n; i++) cin >> c[i];
	for(int i = n-2; i >= 0; i--) c[i] = min(c[i], c[i+1]);
	for(int i = 1; i <= 30; i++) {
		if(i < n)
			c[i] = min(c[i-1]*2, c[i]);
		else
			c[i] = 2*c[i-1];
	}
	ll ans = 1ll<<60, cur = 0;
	for(int i = 31; i--;) if((l>>i)&1) {
		cur += c[i];
	} else {
		ans = min(ans, cur + c[i]);
	}
	cout << min(ans, cur) << '\n';
}