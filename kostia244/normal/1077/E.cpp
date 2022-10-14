#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	map<int, int> cnt;
	cin >> n;
	for(int t, i = 0; i < n; i++) cin >> t, cnt[t]++;
	vi a;
	for(auto i : cnt) a.pb(i.second);
	sort(all(a), greater<ll>());
	ll mn = LLONG_MAX, ans, l;
	ans = l = 0;
	for(auto i : a) {
		l=(l<<1)|1;
		mn = min(mn/2, i);
		ans = max(ans, l*mn);
	}
	cout << ans;
}