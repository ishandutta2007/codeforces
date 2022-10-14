#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define int ll
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<20;
ll f1[maxn], f2[maxn];
void add(int p, int v, int t) {
	for(; p < maxn; p += p&-p) {
		f1[p] += v;
		f2[p] += t;
	}
}
int can(ll t) {
	ll p = 0, r = 0;
	for(int i = 1<<20; i>>=1;)
		if(f2[p|i] <= t)
			t -= f2[p|i], r += f1[p|i], p|=i;
	return r;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, t, ans = 0;
	cin >> n >> t;
	int I = 0;
	vector<array<int,3>> a(n), ta;
	for(auto &[x, y, i] : a) cin >> x >> y, i = I++, ta.push_back({y, x, i});
	sort(all(a), greater<>());
	sort(all(ta));	
	for(auto [x, y, i] : a) {
		add(lower_bound(all(ta), array<int,3>{y, x, i}) - ta.begin() + 1, 1, y);
		ans = max(ans, min(x, can(t)));
	}
	cout << ans << '\n' << ans << '\n';
	vector<array<int,2>> b;
	for(auto [x, y, i] : a) if(x >= ans) b.push_back({y,i});
	sort(all(b));
	for(auto i : b) if(t >= i[0]) {
		t -= i[0];
		cout << i[1]+1 << " ";
		if(!--ans) break;
	} cout << '\n';
}