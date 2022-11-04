#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
const int mod = 998244353;


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
		int n, m, k, q;
		cin >> n >> m >> k >> q;
		int am = 0;
		vector<pair<int, int>> qu(q);
		for(int i = 0; i < q; i++) {
			cin >> qu[i].first >> qu[i].second;
			--qu[i].first;
			--qu[i].second;
		}
		set<int> fir;
		set<int> sec;
		for(int i = q - 1; i >= 0; i--) {
			if(fir.size() != n && sec.size() != m && (fir.find(qu[i].first) == fir.end() || sec.find(qu[i].second) == sec.end())) {
				++am;
			}
			fir.insert(qu[i].first);
			sec.insert(qu[i].second);
		}
		int ans = 1;
		for(int i = 0; i < am; i++) {
			ans = (ll)ans * k % mod;
		}
		cout << ans << '\n';
	}
}