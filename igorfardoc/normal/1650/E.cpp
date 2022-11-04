#include<bits/stdc++.h>
#define inf 1000000000
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
		int n, d;
		cin >> n >> d;
		vi a(n);
		int mx = -1;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			if(i == 0) {
				mx = max(mx, a[i] - 1);
			} else {
				mx = max(mx, a[i] - a[i - 1] - 1);
			}
		}
		int bc = d - a[n - 1];
		mx = max(mx, d - a[n - 1]);
		vi pref(n + 1, inf);
		vi suff(n + 1, inf);
		for(int i = 1; i <= n; i++) {
			if(i == 1) {
				pref[i] = a[i - 1] - 1;
			} else {
				pref[i] = min(pref[i - 1], a[i - 1] - a[i - 2] - 1);
			}
		}
		for(int i = n - 1; i >= 0; i--) {
			suff[i] = suff[i + 1];
			if(i == 0) {
				suff[i] = min(suff[i + 1], a[i - 1] - 1);
			} else {
				suff[i] = min(suff[i + 1], a[i] - a[i - 1] - 1);
			}
		}
		int ans = -1;
		for(int i = 0; i < n; i++) {
			int heremx = mx;
			int bchere = bc;
			if(i == n - 1) {
				bchere = d - a[i - 1];
			}
			int bef = 0;
			int nxt = d + 1;
			if(i != 0) {
				bef = a[i - 1];
			}
			if(i != n - 1) {
				nxt = a[i + 1];
			}
			heremx = max(heremx, nxt - bef - 1);
			int here = min(pref[i], suff[min(i + 2, n)]);
			here = min(here, nxt - bef - 1);
			here = min(here, max((heremx - 1) / 2, bchere - 1));
			ans = max(ans, here);
		}
		cout << ans << '\n';
	}

}