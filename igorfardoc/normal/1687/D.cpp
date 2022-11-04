#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
#define maxa 2000001



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
	vector<bool> here(maxa + 2, false);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		here[a[i]] = true;
	}
	vi l(maxa + 2, -1), r(maxa + 2, -1);
	vi pref(maxa + 3, 0);
	for(int i = 1; i <= maxa + 2; i++) {
		pref[i] = pref[i - 1] + here[i - 1];
	}
	int now = -1;
	for(int i = 0; i < maxa + 2; i++) {
		if(here[i]) now = i;
		l[i] = now;
	}
	now = -1;
	for(int i = maxa + 1; i >= 0; i--) {
		if(here[i]) now = i;
		r[i] = now;
	}
	for(int i = 1; i <= a[n - 1]; i++) {
		if((ll)i * i + i < a[0]) continue;
		ll lhere = max(0ll, (ll)i * i - a[0]);
		ll rhere = (ll)i * i + i - a[0];
		if(n == 1) {
			cout << lhere;
			return 0;
		}
		int prevr = -1;
		for(int j = i; (ll)j * j - ((ll)i * i + i) <= a[n - 1]; j++) {
			int l1 = a[0] + max(0ll, (ll)j * j - ((ll)i * i + i));
			int r1 = a[0] + (ll)j * j + j - (ll)i * i;
			r1 = min(r1, maxa);
			l1 = min(l1, maxa);
			if(prevr != -1) {
				if(pref[l1] - pref[prevr + 1] > 0) {
					rhere = lhere - 1;
					break;
				}
			}
			prevr = r1;
			if(pref[r1 + 1] - pref[l1] == 0) continue;
			lhere = max(lhere, (ll)j * j - (r[l1] - a[0]) - a[0]);
			rhere = min(rhere, (ll)j * j + j - (l[r1] - a[0]) - a[0]);
			//cout << i << ' ' << j << ' ' << lhere << ' ' << rhere << endl;
		}
		if(lhere > rhere) continue;
		cout << lhere;
		return 0;
	}
	
}