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
	vl good = {1};
	for(int i = 2; i <= 14; i++) {
		good.push_back(good.back() * i);
	}
	int t;
	cin >> t;
	while(t--) {
		int ans = 10000;
		ll n;
		cin >> n;
		for(int mask = 0; mask < (1 << good.size()); mask++) {
			ll here = 0;
			for(int i = 0; i < good.size(); i++) {
				if((mask >> i) & 1) {
					here += good[i];
				}
			}
			if(n >= here) {
				ans = min(ans, __builtin_popcount(mask) + __builtin_popcountll(n - here));
			}
		}
		cout << ans << '\n';
	}
}