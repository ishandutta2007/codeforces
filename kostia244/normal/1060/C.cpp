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
const ll mod = (119*(1<<23) + 1);
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	vi a, b;
	cin >>n >> m;
	a.resize(n);
	b.resize(m);
	for(auto &i : a) cin >> i;
	for(auto &i : b) cin >> i;
	vector<pair<ll, ll>> res;
	for(int i = 0; i < n; i++){
		ll s = 0;
		for(int j = i; j < n; j++) {
			s += a[j];
			res.pb({s, j-i+1});
		}
	}
	sort(all(res));
	for(int i = 1; i < res.size(); i++)
		res[i].second = max(res[i].second, res[i-1].second);
	ll ans = 0, x;
	cin >> x;
	for(int i = 0; i < m; i++){
		ll s = 0;
		for(int j = i; j < m; j++) {
			s += b[j];
			auto it = lower_bound(all(res), pair<ll, ll>{(x/s)+1, 0});
			if(it==res.begin()) continue;
			--it;
			ans = max(ans, (j-i+1)*1ll*(it->second));
		}
	}
	cout << ans << "\n";
}