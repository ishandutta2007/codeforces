#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<ll>
#define pi pair<int, int>
#define all(x) x.begin(), x.end()
#define mod 1000000007ll

using namespace __gnu_pbds;
using namespace std;
ll n, k, tx = 1, x, ans, mask = 0, cnt[30];
vi v;
int main() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
	cin >> n >> k >> x;
	while(k--) tx *= x;
	x = tx;
	v.resize(n);
	for(auto& i : v) {
		cin >> i;
		ans |= i;
		for(int k = 0; k < 30; k++) cnt[k] += (i>>k)&1;
	}
	for(int k = 0; k < 30; k++) mask += ((cnt[k] == 1) * (1<<k));
	ll tans = ans;
	for(auto& i : v) {
		ans = max(ans, (tans^(i&mask))|(i*x));
	}
	cout << ans;
}