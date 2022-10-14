#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#include <x86intrin.h>
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;
const int maxn = 4003, mod = 998244353;
void solve() {
	int n, k;
	cin >> n >> k;
	vector<pi> a(n);
	vi b, r(n);
	int pos = 0;
	map<int, int> cnt;
	for(auto &i : a) cin >> i.first, i.second = pos++, cnt[i.first%k]++;
	sort(all(a), [&](auto a, auto b) {
		return (a.first%k) < (b.first%k);
	});
	for(int i = 0; i < k; i++) cnt[i]+=0;
	multiset<int> extra;
	for(auto i : cnt) {
		if(i.second<(n/k))
		for(int j = 0; j < (n/k)-i.second; j++) extra.insert(i.first);//, 		cout << i.first << " " << i.second << '\n';
	}
	ll ans = 0;
	int rem = 0;
	for(int i = 0; i < n; i++) {
		if(cnt[a[i].first%k]<=(n/k)) continue;
		cnt[a[i].first%k]--;
		auto it = extra.lower_bound(a[i].first%k);
		if(it==extra.end()) it = extra.begin();
		int t = (k + *it - a[i].first%k)%k;
		ans += t;
		a[i].first += t;
		extra.erase(it);
	}
	sort(all(a), [](auto a, auto b) {
		return a.second < b.second;
	});
	cout << ans << '\n';
	for(auto i : a) cout << i.first << " ";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
//	cin >> t;
	t = 1;
	while(t--) solve();
}