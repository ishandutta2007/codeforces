#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
#include<bits/extc++.h>
using namespace __gnu_pbds;
using oset = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 1<<18, mod = 1e9 + 7, lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//bit | pref | cyc
//0   |    0 |   4
//1   |    0 |   4
//2   |    1 | 4x4
//3   |    1 | 4x4
ll table[2][4][3] = 
{
	{{0, 0, 0}, {1, 0, 1}, {0, 1, 1}, {1, 1, 0}},
	{{0, 0, 0}, {0, 1, 1}, {1, 1, 0}, {1, 0, 1}}
};
ll get(ll b, ll p) {
	ll i = p/3;
	ll j = p%3;
	ll cyc = 1ll<<min(b, b^1);
	ll pref = 0, TT = 1;
	while(TT < cyc) {
		pref += TT;
		TT<<=2;
	}
	if(i < pref) {
		return 0;
	}
	if(i < pref+cyc) {
		return table[b&1][1][j];
	}
	i -= pref+cyc;
	i /= cyc;
	return table[b&1][i%4][j];
}
ll solve(ll v) {
	ll ans = 0;
	for(int i = 0; i < 60; i++) ans += get(i, v)<<i;
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t, x;
	cin >> t;
	while(t--) {
		cin >> x;
		cout << solve(x-1) << '\n';
	}
	return 0;
}