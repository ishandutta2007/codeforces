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
		vi a(n), b(n), d(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			--a[i];
		}
		for(int i = 0; i < n; i++) {
			cin >> b[i];
			--b[i];
		}
		for(int i = 0; i < n; i++) {
			cin >> d[i];
			--d[i];
		}
		vi to(n);
		for(int i = 0; i < n; i++) {
			to[a[i]] = b[i];
		}
		vi cmp(n, -1);
		int now = 0;
		set<int> all;
		for(int i = 0; i < n; i++) {
			if(cmp[i] != -1) continue;
			int v = i;
			int am = 0;
			while(cmp[v] == -1) {
				cmp[v] = now;
				v = to[v];
				++am;
			}
			++now;
			if(am > 1) {
				all.insert(now - 1);
			}
		}
		for(int i = 0; i < n; i++) {
			if(d[i] == -1) continue;
			auto it = all.find(cmp[d[i]]);
			if(it != all.end()) {
				all.erase(it);
			}
		}
		int ans = 1;
		for(int i = 0; i < all.size(); i++) {
			ans = ans * 2 % 1000000007;
		}
		cout << ans << '\n';
	}

}