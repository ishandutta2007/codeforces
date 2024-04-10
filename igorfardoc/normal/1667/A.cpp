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
	int n;
	cin >> n;
	vi a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll ans = 1e18;
	for(int i = 0; i < n; i++) {
		ll anshere = 0;
		ll now = 0;
		for(int j = i + 1; j < n; j++) {
			ll here = now / a[j];
			anshere += here;
			ll curr = here * a[j];
			if(curr <= now) {
				curr += a[j];
				++anshere;
			}
			now = curr;
		}
		now = 0;
		for(int j = i - 1; j >= 0; j--) {
			ll here = now / a[j];
			anshere += here;
			ll curr = here * a[j];
			if(curr <= now) {
				curr += a[j];
				++anshere;
			}
			now = curr;
		}
		ans = min(ans, anshere);
	}
	cout << ans;
}