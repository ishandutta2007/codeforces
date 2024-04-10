#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
const int N = 100000;


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
		int n, k;
		cin >> n >> k;
		vi a(n);
		vvi where(N + 1);
		int mn = N;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			mn = min(mn, a[i]);
			where[a[i]].push_back(i);
		}
		int ans = N;
		for(int mx = N; mx >= 0; mx--) {
			ans = min(ans, mx - mn);
			if(mx == 0) break;
			bool bad = false;
			for(const auto& i : where[mx]) {
				if(a[i] / k >= mx) {
					bad = true;
					break;
				}
				int here = a[i] / mx + 1;
				mn = min(mn, a[i] / here);
				where[a[i] / here].push_back(i);
			}
			if(bad) break;
			vi tp;
			swap(where[mx], tp);
		}
		cout << ans << '\n';
	}
}