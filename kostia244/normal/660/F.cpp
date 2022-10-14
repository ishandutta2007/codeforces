#pragma GCC optimize("trapv")
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
ll n, a[200200];
ll ans = 0;
using ld = long double;
bool rem(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
	ld x = (a.second-b.second)/(b.first-a.first);
	return (1.0*c.first*x+c.second)-(1.0*b.first*x+b.second)>1e-9;
}
void solve(int l = 1, int r = n) {
	if(l>r) return;
	int mid = (l+r)>>1;
//	cout << l << " " << r << " " << mid << "\n";
	ll sf = 0, cur = 0, j = 0;
	vector<pair<ll, ll>> z{{0,0}}, tz;
	for(int i = mid+1; i <= r; i++) {
		sf += a[i];
		cur += (i-mid)*1ll*a[i];
		ans = max(ans, cur);
		z.pb({sf, cur});
	}
	sort(all(z));
	for(auto i : z) {
		if(tz.size()&&tz.back().first==i.first) tz.pop_back();
		while(tz.size()>1&&rem(tz[tz.size()-2], tz[tz.size()-1], i)) tz.pop_back();
		tz.pb(i);
	}
	z=tz;
	sf = cur = 0;
	for(int y = 1, i = mid; i >= l; i--, y++) {
		sf += a[i];
		cur += sf;
		while(j+1<z.size() && y*z[j].first + z[j].second <= y*z[j+1].first + z[j+1].second) j++;
		ans = max(ans, cur + (z.empty()?0:(y*z[j].first + z[j].second)));
	}
	solve(l, mid-1);
	solve(mid+1, r);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	solve();
	cout << ans;
}