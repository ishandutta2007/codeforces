//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 1e9 + 7;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, t, d=0;
	cin >> n;
	set<int> ev, th;
	vi ans;
	for(int i = 0; i < n; i++) {
		++d;
		cin >> t;
		if(t>0) {
			if(th.count(t))
				return cout << -1, 0;
			ev.insert(t);
			th.insert(t);
		} else {
			t=-t;
			if(!ev.count(t))
				return cout << -1, 0;
			ev.erase(t);
		}
		if(ev.empty()) {
			ans.pb(d);
			th.clear();
			d = 0;
		}
	}
	if(!ev.empty())
		return cout << -1, 0;
	cout << ans.size() << "\n";
	for(auto i : ans) cout << i << " ";
}