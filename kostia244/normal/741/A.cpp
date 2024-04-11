#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
using ll = long long;
using namespace std;
const int maxn = 1<<10;
int n, a[maxn], vis[maxn];
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	ll ans = 1;
	for(int i = 1; i <= n; i++) if(!vis[i]) {
		int t = i;
		ll len = 0;
		while(!vis[t]) {
			vis[t] = 1;
			t = a[t];
			len++;
		}
		if(t != i) return cout << -1, 0;
		if(len%2 == 0) len /= 2;
		ans = ans*(len/__gcd(ans, len));
	}
	cout << ans << endl;
}
//?VK
//??V
//K?