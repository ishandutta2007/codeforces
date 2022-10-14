#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int ll
using ll = long long;
using namespace std;
const int maxn = 1<<22, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll x, d;
	cin >> x >> d;
	vector<ll> a;
	ll cur = 1;
	for(ll b = 30; b-->1;) while(x >= (1<<b) -1) {
		for(int f = b; f--;) a.push_back(cur);
		x -= (1<<b)-1;
		cur += d+1;
	}
	cout << a.size() << endl;
	for(auto i : a) cout << i << " "; cout << endl;
}