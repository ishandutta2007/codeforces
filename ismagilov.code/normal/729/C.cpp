#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endl "\n"

using namespace std;

vector<int> zap;
int n, k, s, t;

bool prov(int v) {
	int tek = 0;
	int tim = 0;
	for (int i = 0; i < zap.size(); i++) {
		if ((zap[i] - tek) > v) {
			return 0;
		}
		else {
			int tektim = 2 * (zap[i] - tek);
			if (v - (tektim / 2) > 0) {
				tektim = max(zap[i] - tek, tektim - (v - (tektim / 2)));
			}
			tim += tektim;
		}
		tek = zap[i];
	}
	if (tim <= t) {
		return 1;
	}
	else {
		return 0;
	}
}

main() {
	ios_base::sync_with_stdio(0);
	cin >> n >> k >> s >> t;
	int kol = 0;
	pair<int, int> a[n];
	vector<int> a1(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].fs >> a[i].sc;
		a1[i] = a[i].sc;
	}
	for (int i = 0; i < k; i++) {
		int c;
		cin >> c;
		zap.pb(c);
	}
	zap.pb(s);
	sort(zap.begin(), zap.end());
	sort(a1.begin(), a1.end());
	reverse(a1.begin(), a1.end());
	int mini = 1000000000;
	int l = 0;
	int r = n;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (prov(a1[mid])) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i].sc >= a1[l]) {
			mini = min(mini, a[i].fs);
		}
	}
	if (!prov(a1[l]) ) {
		cout << -1 << endl;
	}
	else {
		cout << mini;
	}
}