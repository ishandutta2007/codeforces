#pragma GCC optimize("trapv")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
using namespace __gnu_pbds;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
using ld = long double;
const int maxn = 2e5 + 10;
ll n, cnt[maxn][2];
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++)
		cnt[i][0] = cnt[i][1] = 0;
	for(int a, f, i = 0; i < n; i++) {
		cin >> a >> f;
		cnt[a][f]++;
	}
	vpi t;
	for(int i = 1; i <= n; i++) {
		if(cnt[i][0]||cnt[i][1])
			t.pb({cnt[i][0]+cnt[i][1], cnt[i][1]});
	}
	sort(rall(t));
	int ans = 0, bans = 0, lst = t[0].first;
	multiset<int, greater<int>> zzqorz;
	int i = 0;
	while(lst) {
		while(i < t.size() && t[i].first>=lst) {
			zzqorz.insert(t[i++].second);
		}
		if(zzqorz.size()) {
			ans += lst;
			bans += min(lst, *zzqorz.begin());
			zzqorz.erase(zzqorz.begin());
		}
		lst--;
	}
	cout << ans << " " << bans << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}