#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<ll>
#define pi pair<ll, ll>
#define mod 1000000007ll

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update> ordered_set;
ll H, th, n, k, ans = LONG_LONG_MAX;
vi a;
int main() {
	cin >> H >> n;
	if(H == 0)
		return cout << 0, 0;
	cin >> k;
	a.eb(k);
	if((H+k) <= 0)
		return cout << 1, 0;
	for(ll i = 1; i < n; i++) {
		cin >> k, a.eb(a[i-1]+k);
		if((H+a.back()) <= 0)
			return cout << (i+1), 0;
	}
	if(a.back() >= 0)
		return cout << -1, 0;
	th = H;
	for(ll i = 0; i < n; i++) {
		H = (th + a[i]);
		ll d = (H + ((-a.back()) - 1))/(-a.back());
		ans = min(ans, d*n + i + 1);
	}
	ll d = (th + ((-a.back()) - 1))/(-a.back());
	ans = min(ans, d*n);
	if(ans == LONG_LONG_MAX)
		return cout << -1, 0;
	else
		cout << fixed << ans;
}