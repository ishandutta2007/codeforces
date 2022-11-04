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
		set<ll> vals;
		ll sum;
		cin >> sum;
		for(int a4 = 0; a4 < 100; a4++) {
			if(a4 * 4 > sum) continue;
			if((sum - a4 * 4) % 6 == 0) {
				vals.insert(a4 + (sum - a4 * 4) / 6);
			}
		}
		for(int a4 = 0; a4 < 100; a4++) {
			if(a4 * 6 > sum) continue;
			if((sum - a4 * 6) % 4 == 0) {
				vals.insert(a4 + (sum - a4 * 6) / 4);
			}
		}
		if(vals.empty()) {
			cout << -1 << '\n';
		} else {
			cout << *(vals.begin()) << ' ' << *(vals.rbegin()) << '\n';
		}
	}
}