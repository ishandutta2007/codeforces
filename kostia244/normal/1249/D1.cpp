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
	int n, k;
	cin >> n >> k;
	map<int, vi> ev;
	map<int, vector<pair<ll, ll>>> ends;
	int l, r, x = 1;
	while(n--) {
		cin >> l >>r;
		ev[l].pb(r);
		ends[r].pb({l, x++});
		l = ev[r].size();
	}
	multiset<int> e;
	int ans = 0;
	vi vec;
	for(auto i : ev) {
		for(auto j : i.second) {
			e.insert(j);
		}
		while(e.size() > k) {
			ans++;
			vec.pb(*e.rbegin());
			e.erase(e.find(*e.rbegin()));
		}
		e.erase(i.first);
	}
	cout << ans << "\n";
	for(auto &i : ends) sort(rall(i.second));
	for(auto i : vec) {
		cout << ends[i].back().second << " ";
		ends[i].pop_back();
	}
}