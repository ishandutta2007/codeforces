#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
const ll mod = (119 * (1 << 23) + 1);
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
vector<pair<ll, ll>> x;
ll n, c;

bool can(ll v) {
	ll ans = 0, xx = 0;
	for(int i = 0; i < n; i++) {
		if((xx < (n+1)/2)&&x[i].second >= v)
		ans += max(v, x[i].first), xx++;
		else
			ans+=x[i].first;
	}
	if(xx < (n+1)/2)
		return false;
	return ans <= c;
}

void solve() {
	cin >> n >> c;
	x.assign(n, {0, 0});
	for(auto &i : x) cin >> i.first >> i.second;
	sort(rall(x));
	ll ans = 0;
	for(ll i = 1ll<<29;i;i>>=1) {
		if(can(ans+i)) ans+=i;
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
}