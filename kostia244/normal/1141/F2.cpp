#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<ll>
#define pi pair<int, int>
#define all(x) x.begin(), x.end()
#define mod 1000000007ll
//using namespace __gnu_pbds;
using namespace std;

int n;
vi pref;
map<int, __V<pi>> a;
__V<pi> t, ans;
int main() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
	cin >> n;
	pref.resize(n);
	cin >> pref[0];
	for (int i = 1; i < n; i++)
		cin >> pref[i], pref[i] += pref[i - 1];
	for(int r = 0; r < n; r++) {
		for(int l = 0; l <= r; l++) {
			a[pref[r] - (l ? pref[l - 1] : 0)].pb({l, r});
		}
	}
	for(auto& i : a) {
		auto& v = i.second;
		if(v.empty()) continue;
		int r = v[0].second;
		t = {v[0]};
		for(int j = 1; j < v.size(); j++)
			if(v[j].first > r) {
				r = v[j].second;
				t.pb(v[j]);
			}
		if(t.size() > ans.size()) ans = t;
	}
	cout << ans.size() << "\n";
	for(auto& i : ans) cout << i.first+1 << " " << i.second+1 << "\n";


}