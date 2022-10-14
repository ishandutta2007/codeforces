#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
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
const int maxn = 404, mod = (119<<23)+1, lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	string t;
	int n, x;
	cin >> n >> x >> t;
	int bal = 0;
	map<int, int> cnt;
	for(auto i : t) {
		if(i == '0') bal++;
		else bal--;
		cnt[bal]++;
	}
	if(bal == 0&&cnt[x]==0) {cout << "0\n";return;}
	if(bal == 0) {cout << "-1\n";return;}
	ll ans = 0;
	for(auto i : cnt) {
		if(i.first == x) {ans += i.second;continue;}
		if(((bal>0)^(i.first > x)) && abs(i.first-x)%abs(bal) == 0) ans += i.second;}
		if(x==0) ans++;
		cout << ans <<'\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}