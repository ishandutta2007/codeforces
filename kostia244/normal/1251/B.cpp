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

void solve() {
	int n;
	int cnt[2] = { 0, 0 }, odd = 0;
	cin >> n;
	string t;
	vi x;
	for (int i = 0; i < n; i++) {
		cin >> t;
		for (auto i : t)
			cnt[i == '1']++;
		x.pb(t.size());
	}
	sort(all(x));
	ll ans = 0;
	ll tt = 0;
	for(int i = 0;i  < 2; i++)
	if(cnt[i]&1)cnt[i]--;
	for (auto i : x) {
		tt += i - (i&1);
		if((cnt[0] + cnt[1])>=tt)ans++;
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