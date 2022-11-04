#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vi a(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int mx = -1;
		map<ll, int> mp;
		set<pair<ll, int>> s;
		s.insert({0, 1});
		mp[0] = 0;
		vi dp(n);
		ll pref = 0;
		for(int i = 0; i < n; i++) {
			int anshere = mx - i;
			pref += a[i];
			if(mp.find(pref) != mp.end()) {
				anshere = max(anshere, mp[pref]);
			}
			auto it = s.lower_bound({pref, -1000000000});
			if(it != s.begin()) {
				--it;
				anshere = max(anshere, it->second + i);
			}
			dp[i] = anshere;
			//cout << dp[i] << endl;
			mx = max(mx, anshere + i);
			if(mp.find(pref) == mp.end()) {
				mp[pref] = anshere;
			} else {
				mp[pref] = max(mp[pref], anshere);
			}
			anshere -= i;
			it = s.lower_bound({pref, -1000000000});
			if(it != s.end() && it->first == pref) {
				int temp = max(it->second, anshere);
				s.erase(it);
				s.insert({pref, temp});
			} else {
				it = s.lower_bound({pref, -1000000000});
				if(it != s.begin()) {
					--it;
					if(it->second >= anshere) {
						continue;
					}
				}
			}
			while(true) {
				auto it = s.lower_bound({pref + 1, -1000000000});
				if(it == s.end() || it->second > anshere) break;
				s.erase(it);
			}
			s.insert({pref, anshere});
		}
		cout << dp[n - 1] << '\n';
	}


}